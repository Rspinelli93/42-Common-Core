/*
Assignment name: argo
Expected files: argo.c
Allowed functions: getc, ungetc, printf, malloc, calloc, realloc, free, isdigit, fscanf, write
-----------------
Write a function argo that will parse a json file in the structure declared in argo.h:

int	argo(json *dst, FILE *stream);

	dst	- is the pointer to the AST that you will create
	stream	- is the file to parse (man FILE)

Your function will return 1 for success and -1 for failure.
If an unexpected token is found you will print the following message in stdout:
"Unexpected token '%c'
"
or if the token is EOF:
"Unexpected end of input
"

Only handle numbers, strings and maps.
Numbers will only be basic ints like in scanf("%d")
Handle escaping in the strings only for backslashes and quotation marks (no 
 \u ...)
Don't handle spaces -> consider them as invalid tokens.

In case of doubt how to parse json, read rfc8259. But you won't need it as the format is simple. Tested with the main, the output should be exactly the same as the input (except for errors).
There are some functions in argo.c that might help you.

Examples that should work:

$> echo -n '1' | ./argo /dev/stdin | cat -e
1$
$> echo -n '"bonjour"' | ./argo /dev/stdin | cat -e
"bonjour"$
$> echo -n '"escape! \" "' | ./argo /dev/stdin | cat -e
"escape! \" "$
$> echo -n '{"tomatoes":42,"potatoes":234}' | ./argo /dev/stdin | cat -e
{"tomatoes":42,"potatoes":234}$
$> echo -n '{"recursion":{"recursion":{"recursion":{"recursion":"recursion"}}}}' | ./argo /dev/stdin | cat -e
{"recursion":{"recursion":{"recursion":{"recursion":"recursion"}}}}$
$> echo -n '"unfinished string' | ./argo /dev/stdin | cat -e
unexpected end of input$
$> echo -n '"unfinished string 2\"' | ./argo /dev/stdin | cat -e
unexpected end of input$
$> echo -n '{"no value?":}' | ./argo /dev/stdin | cat -e
unexpected token '}'$
*/

#include "argo.h"

static int	parse_integer(json *dst, FILE *stream)
{
	if (fscanf(stream, "%d", &dst->integer) != 1)
	{
		unexpected(stream);
		return (-1);
	}
	dst->type = INTEGER;
	return (1);
}

static int	parse_string(json *dst, FILE *stream)
{
	char	buf[4096];
	int		i;
	int		c;

	i = 0;
	getc(stream);
	while (1)
	{
		c = getc(stream);
		if (c == EOF)
		{
			unexpected(stream);
			return (-1);
		}
		if (c == '\\')
		{
			c = getc(stream);
			if (c != '\\' && c != '"')
			{
				unexpected(stream);
				return (-1);
			}
		}
		else if (c == '"')
			break ;
		buf[i++] = c;
	}
	buf[i] = '\0';
	dst->string = strdup(buf);
	if (!dst->string)
		return (-1);
	dst->type = STRING;
	return (1);
}

static int	parse_map(json *dst, FILE *stream)
{
	getc(stream);
	dst->type = MAP;
	dst->map.data = NULL;
	dst->map.size = 0;
	if (accept(stream, '}'))
		return (1);
	while (1)
	{
		pair	p;
		json	key;

		if (peek(stream) != '"')
		{
			unexpected(stream);
			return (-1);
		}
		if (parse_string(&key, stream) == -1)
			return (-1);
		p.key = key.string;
		if (!expect(stream, ':'))
		{
			free(p.key);
			return (-1);
		}
		if (argo(&p.value, stream) == -1)
		{
			free(p.key);
			return (-1);
		}
		dst->map.data = realloc(dst->map.data,
				sizeof(pair) * (dst->map.size + 1));
		if (!dst->map.data)
			return (-1);
		dst->map.data[dst->map.size++] = p;
		if (accept(stream, '}'))
			return (1);
		if (!expect(stream, ','))
			return (-1);
	}
}

int	argo(json *dst, FILE *stream)
{
	int	c;

	c = peek(stream);
	if (c == EOF)
	{
		unexpected(stream);
		return (-1);
	}
	if (c == '{')
		return (parse_map(dst, stream));
	if (c == '"')
		return (parse_string(dst, stream));
	if (isdigit(c) || c == '-')
		return (parse_integer(dst, stream));
	unexpected(stream);
	return (-1);
}

/*
How it works:
This is a recursive descent parser — each type gets its own function, and argo dispatches based on the first character (peek).
3 cases:

{ → map
" → string
digit/- → integer

String parsing: read char by char, handle \" and \\ escapes manually, stop at unescaped ".
Map parsing: loop of "key":value pairs separated by ,, ended by }. Calls argo recursively for values — that's how {"recursion":{...}} works.
Key helpers from the given code:

- peek() — look without consuming
- accept() — consume only if matches
- expect() — consume or print error
- unexpected() — prints the right error message

The realloc grows the pairs array one slot at a time — not efficient but clean for an exam.*/
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

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> 

//
typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

//
typedef struct	pair {
	char	*key;
	json	value;
}	pair;

void	free_json(json j);
int	argo(json *dst, FILE *stream);

//
int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

//
void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

//
int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

//
int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

//
void	free_json(json j)
{
	switch (j.type)
	{
		case MAP:
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);
				free_json(j.map.data[i].value);
			}
			free(j.map.data);
			break ;
		case STRING:
			free(j.string);
			break ;
		default:
			break ;
	}
}

//
void	serialize(json j)
{
	switch (j.type)
	{
		case INTEGER:
			printf("%d", j.integer);
			break ;
		case STRING:
			putchar('"');
			for (int i = 0; j.string[i]; i++)
			{
				if (j.string[i] == '\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"');
			break ;
		case MAP:
			putchar('{');
			for (size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(',');
				serialize((json){.type = STRING, .string = j.map.data[i].key});
				putchar(':');
				serialize(j.map.data[i].value);
			}
			putchar('}');
			break ;
	}
}

int	parse_string(char **dst, FILE *stream);
int	argo(json *dst, FILE *stream);

//
int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	json	file;
	if (argo (&file, stream) != 1)
	{
		free_json(file);
		return 1;
	}
	serialize(file);
	printf("\n");
}

int	parse_string(char **dst, FILE *stream)
{
	char	buf[4096];
	int		i;
	int		c;

	i = 0;
	if (!expect(stream, '"'))
		return (-1);
	while (1)
	{
		c = getc(stream);
		if (c == EOF)
			return (unexpected(stream), -1);
		if (c == '\\')
		{
			c = getc(stream);
			if (c != '"' && c != '\\')
				return (unexpected(stream), -1);
			buf[i++] = '\\';
		}
		else if (c == '"')
			break ;
		buf[i++] = c;
	}
	buf[i] = '\0';
	*dst = strdup(buf);
	return (*dst ? 1 : -1);
}

int	argo(json *dst, FILE *stream)
{
	if (isdigit(peek(stream)) || peek(stream) == '-')
	{
		dst->type = INTEGER;
		if (fscanf(stream, "%d", &dst->integer) != 1)
			return (unexpected(stream), -1);
		return (1);
	}
	if (peek(stream) == '"')
	{
		dst->type = STRING;
		return (parse_string(&dst->string, stream));
	}
	if (peek(stream) == '{')
	{
		getc(stream);
		dst->type = MAP;
		dst->map.data = NULL;
		dst->map.size = 0;
		if (accept(stream, '}'))
			return (1);
		while (1)
		{
			dst->map.data = realloc(dst->map.data,
				sizeof(pair) * (dst->map.size + 1));
			if (!dst->map.data)
				return (-1);
			pair *p = &dst->map.data[dst->map.size++];
			if (parse_string(&p->key, stream) == -1)
				return (-1);
			if (!expect(stream, ':'))
				return (-1);
			if (argo(&p->value, stream) == -1)
				return (-1);
			if (accept(stream, '}'))
				return (1);
			if (!expect(stream, ','))
				return (-1);
		}
	}
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
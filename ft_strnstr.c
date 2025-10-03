/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:26:50 by rspinell          #+#    #+#             */
/*   Updated: 2025/09/29 16:28:12 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*     
If *s2 is an empty string, *s1 is returned; if *s2	occurs nowhere
in *s1, NULL is returned; otherwise a pointer to	the first character of
the first occurrence of *s2 is returned.

The strnstr() function locates the first	occurrence of the  null-termi-
nated  string *s2 in the string *s1, where not more than len charac-
ters are	searched.  Characters that appear after	a `\0'	character  are
not  searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = (char *) s1;
	if (len == 0 || s1 == s2)
		return (ptr1);
	ptr2 = (char *) s2;
	if (ft_strlen(ptr2) < ft_strlen(ptr1))
	{
		while ((i + ft_strlen(ptr2)) <= len)
		{
			if (ft_strncmp(ptr1, ptr2, ft_strlen(s2)) == 0)
				return (ptr1);
			ptr1++;
			i++;
		}
	}
	return (NULL);
}

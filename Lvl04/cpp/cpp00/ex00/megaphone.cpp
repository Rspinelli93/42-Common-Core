/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:57:33 by rick              #+#    #+#             */
/*   Updated: 2025/12/13 16:06:56 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void print_no_params();
void print_uppercase(char *str);

int	main(int ac, char **av)
{
	int i = 1;

	if (ac == 1)
		print_no_params();
	else
	{
		while (i < ac)
		{
			print_uppercase(av[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return 0;
}

void print_no_params()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

void print_uppercase(char *str)
{
	while (*str)
	{
		std::cout << (char)toupper(*str);
		str++;
	}
}
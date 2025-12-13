/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:42:11 by rick              #+#    #+#             */
/*   Updated: 2025/12/13 17:13:01 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int main(void)
{
    char *command;

    while (1)
    {
        std::cin >> command;
        if (command == "EXIT")
            break ;
        if (command == "SEARCH")
            break ;
        if (command == "ADD")
            break ;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:36:54 by rick              #+#    #+#             */
/*   Updated: 2025/12/13 17:14:22 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

//https://cplusplus.com/doc/oldtutorial/classes/

#include <iostream>

class Contact {
    public:
        char *name;
        void set_name(char *input)
        {
            name = input;
        }
};

class PhoneBook {
    public:
        Contact *book;
        int i;
};

#endif
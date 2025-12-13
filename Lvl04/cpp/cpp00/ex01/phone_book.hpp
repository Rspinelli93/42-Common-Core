/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:36:54 by rick              #+#    #+#             */
/*   Updated: 2025/12/13 17:13:40 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

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
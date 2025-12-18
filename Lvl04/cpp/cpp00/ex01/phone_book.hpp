/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:36:54 by rick              #+#    #+#             */
/*   Updated: 2025/12/18 16:03:26 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

//https://cplusplus.com/doc/oldtutorial/classes/

#include <iostream>
#include <string>

class Contact {
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;
};

class PhoneBook {
    public:
        Contact book[8];
        int i;
        void set_name(std::string name, Contact *temp) { temp->first_name = name; }
        void set_surname(std::string name, Contact *temp) { temp->last_name = name; }
        void set_nickname(std::string name, Contact *temp) { temp->nickname = name; }
        void set_number(std::string number, Contact *temp) { temp->phone_number = number; }
        void set_secret(std::string secret, Contact *temp) { temp->secret = secret; }
        void add_contact(Contact temp) { book[i] = temp; }
        void next_contact() { if(i == 7) i = 0; else i++; }
        PhoneBook(){ i = 0; }
};

#endif
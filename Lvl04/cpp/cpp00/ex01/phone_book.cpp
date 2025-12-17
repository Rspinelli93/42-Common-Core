/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:42:11 by rick              #+#    #+#             */
/*   Updated: 2025/12/17 15:06:14 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

static void add_contact(PhoneBook *my_phonebook);

int main(void)
{
    std::string command;
    PhoneBook   my_phonebook;

    while (1)
    {
        std::cin >> command;
        if (command == "EXIT")
            break ;
        if (command == "SEARCH")
        {
            int i = 0;
            while (i < 8)
            {
                std::cout << my_phonebook.book[i].first_name;
                i++;
            }
        }
        if (command == "ADD")
           add_contact(&my_phonebook);
    }
    return (0);
}

static void add_contact(PhoneBook *my_phonebook)
{
    std::string prompt;
    Contact     temp;

    std::cout << "Enter contact First name: ";
    std::cin >> prompt;
    while (prompt == "\n")
    {
        std::cout << "Enter contact First name: ";
        std::cin >> prompt;
    }
    my_phonebook->set_name(prompt, temp);
    std::cout << "\n";
    std::cout << "Enter contact Last name: ";
    std::cin >> prompt;
    while (prompt == "\n")
    {
        std::cout << "Enter contact Last name: ";
        std::cin >> prompt;
    }
    my_phonebook->set_surname(prompt, temp);
    std::cout << "\n";
    std::cout << "Enter contact Nickname: ";
    std::cin >> prompt;
    while (prompt == "\n")
    {
        std::cout << "Enter contact Nickname: ";
        std::cin >> prompt;
    }
    my_phonebook->set_nickname(prompt, temp);
    std::cout << "\n";
    std::cout << "Enter contact Phone number: ";
    std::cin >> prompt;
    while (prompt == "\n")
    {
        std::cout << "Enter contact Phone number: ";
        std::cin >> prompt;
    }
    my_phonebook->set_number(prompt, temp);
    std::cout << "\n";
    std::cout << "Enter contact Darkest Secret: ";
    std::cin >> prompt;
    while (prompt == "\n")
    {
        std::cout << "Enter contact Darkest Secret: ";
        std::cin >> prompt;
    }
    my_phonebook->set_secret(prompt, temp);
    std::cout << "\n";
    my_phonebook->next_contact();
}

std::string trunc_string(std::string str)
{
    std::string ret;
    int         i;

    i = 0;
    if (str.length() == 10)
        return (str);
    if (str.length() > 10)
    {
        while (i < 9)
        {
            ret[i] = str[i];
            i++;
        }
        ret[i] = '.';
    }
    else
    {
        i = 10 - str.length();
        while (i < 10)
        {
            ret[i] = str[i];
            i++;
        }
    }
}
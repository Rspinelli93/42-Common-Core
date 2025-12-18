/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:42:11 by rick              #+#    #+#             */
/*   Updated: 2025/12/18 16:06:32 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

static void	add_contact(PhoneBook *my_phonebook);
std::string	make_print(PhoneBook *pb);
int main(void)
{
	std::string	command;
	PhoneBook	my_phonebook;

	while (1)
	{
		std::cin >> command;
		if (command == "EXIT")
			break ;
		if (command == "SEARCH")
		{
			std::cout << make_print(&my_phonebook);
		}
		if (command == "ADD")
			add_contact(&my_phonebook);
	}
	return (0);
}

static void	add_contact(PhoneBook *my_phonebook)
{
	std::string	prompt;
	Contact		temp;

	std::cout << "Enter contact First name: ";
	std::cin >> prompt;
	while (prompt == "\n")
	{
		std::cout << "Enter contact First name: ";
		std::cin >> prompt;
	}
	my_phonebook->set_name(prompt, &temp);
	std::cout << "\n";
	std::cout << "Enter contact Last name: ";
	std::cin >> prompt;
	while (prompt == "\n")
	{
		std::cout << "Enter contact Last name: ";
		std::cin >> prompt;
	}
	my_phonebook->set_surname(prompt, &temp);
	std::cout << "\n";
	std::cout << "Enter contact Nickname: ";
	std::cin >> prompt;
	while (prompt == "\n")
	{
		std::cout << "Enter contact Nickname: ";
		std::cin >> prompt;
	}
	my_phonebook->set_nickname(prompt, &temp);
	std::cout << "\n";
	std::cout << "Enter contact Phone number: ";
	std::cin >> prompt;
	while (prompt == "\n")
	{
		std::cout << "Enter contact Phone number: ";
		std::cin >> prompt;
	}
	my_phonebook->set_number(prompt, &temp);
	std::cout << "\n";
	std::cout << "Enter contact Darkest Secret: ";
	std::cin >> prompt;
	while (prompt == "\n")
	{
		std::cout << "Enter contact Darkest Secret: ";
		std::cin >> prompt;
	}
	my_phonebook->set_secret(prompt, &temp);
	std::cout << "\n";
	my_phonebook->add_contact(temp);
	my_phonebook->next_contact();
}

std::string trunc_string(std::string str)
{
	int spaces_needed;

	spaces_needed = 10 - str.length();
	if (str.length() == 10)
		return (str);
	else if (str.length() > 10)
	{
		str.erase(9);
		str.append(".");
	}
	else
		str.insert(0, spaces_needed, ' ');
	return(str);
}

std::string	make_print(PhoneBook *pb)
{
	int			i;
	std::string	to_print;
	
	to_print += "|" + trunc_string("Index") + "|";
	to_print += trunc_string("First Name") + "|";
	to_print += trunc_string("Last Name") + "|";
	to_print += trunc_string("Nickname") + "\n";
	i = 0;
	while (i < 8)
	{
		if (pb->book[i].first_name.empty())
			break;
		to_print += "|" + trunc_string("1.") + "|";
		to_print += trunc_string(pb->book[i].first_name) + "|";
		to_print += trunc_string(pb->book[i].last_name) + "|";
		to_print += trunc_string(pb->book[i].nickname) + "|\n";
		i++;
	}
	return (to_print);
}
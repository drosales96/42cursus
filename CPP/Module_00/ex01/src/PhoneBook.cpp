/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:27:54 by drosales          #+#    #+#             */
/*   Updated: 2025/02/18 13:34:22 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->_id = 0;
    ft_print_header();
    std::cout << YELLOW HELLO RESET << std::endl;
    std::cout << std::endl;
}

PhoneBook::~PhoneBook(void) {
    std::cout << YELLOW BYE RESET << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::ft_add_contact(void) {
    std::string str;

    str = "";
    if (this->_id > 7) {
        std::cout << RED WARNING RESET CYAN << \
        this->_list[this->_id % 8].ft_get_name() \
        << RESET << std::endl;
        std::cout << std::endl;
    }
    while (!std::cin.eof() && str == "") {
        if (this->_id > 7)
            std::cout << WHITE ENTER << \
            this->_list[this->_id % 8].ft_get_name() \
            << " " << NAME RESET;
        else
            std::cout << WHITE ENTER << \
            this->_list[this->_id % 8].ft_get_name() \
            << NAME RESET;
        if (std::getline(std::cin, str) && str != "")
            this->_list[this->_id % 8].ft_set_name(str);
    }
    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << WHITE ENTER << \
        this->_list[this->_id % 8].ft_get_name() \
        << "'s" << " " << LNAME RESET;
        if (std::getline(std::cin, str) && str != "")
            this->_list[this->_id % 8].ft_set_last_name(str);
    }
    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << WHITE ENTER << \
        this->_list[this->_id % 8].ft_get_name() \
        << "'s" << " " << NICK RESET;
        if (std::getline(std::cin, str) && str != "")
            this->_list[this->_id % 8].ft_set_nick(str);
    }
    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << WHITE ENTER << \
        this->_list[this->_id % 8].ft_get_name() \
        << "'s" << " " << PHONEN RESET;
        if (std::getline(std::cin, str) && str != "")
            this->_list[this->_id % 8].ft_set_telephone(str);
    }
    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << WHITE ENTER << \
        this->_list[this->_id % 8].ft_get_name() \
        << "'s" << " " << DKSECRET RESET;
        if (std::getline(std::cin, str) && str != "") {
            this->_list[this->_id % 8].ft_set_dark_secret(str);
            std::cout << this->_list[this->_id % 8].ft_get_name() <<
            "'s " << GREEN ADD_SUCCESS << " [" << this->_id % 8 + 1 << OK_END RESET << \
            std::endl;
            std::cout << std::endl; 
        }
    }
    this->_id++;
}

void    PhoneBook::ft_search_contact(void) {
    std::string str;

    if (ft_display_table(this->_list)) {
        std::cout << std::endl << RED EMPTY_PB << std::endl;
        return ;
    }
    while (!std::cin.eof())
    {
        std::cout << BLUE INDX_SELECC RESET;
        if (std::getline(std::cin, str) && str != "") {
            if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
                this->_list[str[0] - 1 - '0'].ft_get_name().size())
                break;
        }
        if (str != "")
            std::cout << RED INDX_ERR RESET << std::endl;
    }
    if (!std::cin.eof())
        this->ft_print_contact(this->_list[str[0] - 1 - '0']);
}

void    PhoneBook::ft_print_contact(Contact contact) {
    std::cout << std::endl << BLUE SEARCH_INP RESET << std::endl;
    if (!contact.ft_get_name().size())
    {
        std::cout << RED SEARCH_INP_ERR RESET << std::endl;
        return ;
    }
    std::cout << BLUE T_NAME RESET << contact.ft_get_name() << std::endl;
    std::cout << BLUE T_LNAME RESET << contact.ft_get_last_name() << std::endl;
    std::cout << BLUE T_NICK RESET << contact.ft_get_nick() << std::endl;
    std::cout << BLUE T_PHONE RESET << contact.ft_get_telephone() << std::endl;
    std::cout << BLUE T_DKSECRET RESET << contact.ft_get_dark_secret() << std::endl;
    std::cout << std::endl;
}
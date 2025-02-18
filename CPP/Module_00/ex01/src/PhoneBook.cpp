/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:27:54 by drosales          #+#    #+#             */
/*   Updated: 2025/02/12 13:17:31 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->_id = 0;
    ft_print_header();
    std::cout << BLUE HELLO RESET << std::endl;
    std::cout << std::endl;
}

PhoneBook::~PhoneBook(void) {
    std::cout << BLUE BYE RESET << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::ft_add_contact(void) {
    std::string str;

    str = "";
    if (this->_id > 7) {
        std::cout << WARNING << \
        this->_list[this->_id % 8].ft_get_name() \
        << RESET << std::endl;
        std::cout << std::endl;
    }
    while (!std::cin.eof() && str == "") {
        if (this->_id > 7)
            std::cout << ENTER << \
            this->_list[this->_id % 8].ft_get_name() \
            << " " << NAME RESET;
        else
            std::cout << ENTER << \
            this->_list[this->_id % 8].ft_get_name() \
            << NAME RESET;
        if (std::getline(std::cin, str) && str != "")
            this->_list[this->_id % 8].ft_set_name(str);
    }
    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << ENTER << \
        this->_list[this->_id % 8].ft_get_last_name() \
        << LNAME RESET;
        if (std::getline(std::cin, str) && str != "")
            this->_list[this->_id % 8].ft_set_last_name(str);
    }
    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << ENTER << \
        this->_list[this->_id % 8].ft_get_nick() \
        << NICK RESET;
        if (std::getline(std::cin, str) && str != "")
            this->_list[this->_id % 8].ft_set_nick(str);
    }
    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << ENTER << \
        this->_list[this->_id % 8].ft_get_telephone() \
        << PHONEN RESET;
        if (std::getline(std::cin, str) && str != "")
            this->_list[this->_id % 8].ft_set_telephone(str);
    }
    str = "";
    while (!std::cin.eof() && str == "") {
        std::cout << ENTER << \
        this->_list[this->_id % 8].ft_get_dark_secret() \
        << DKSECRET RESET;
        if (std::getline(std::cin, str) && str != "") {
            this->_list[this->_id % 8].ft_get_dark_secret() << \
            ADD_SUCCESS << this->_id % 8 + 1 << OK_END RESET << \
            std::endl;
            std::cout << std::endl;
        }
    }
    this->_id++;
}

void    PhoneBook::ft_search_contact(void) {
    std::string str;

    if (ft_display_table(this->_list)) {
        std::cout << std::endl << EMPTY_PB << std::endl;
        return ;
    }
    while (!std::cin.eof())
    {
        std::cout << INDX_SELECC RESET;
        if (std::getline(std::cin, str) && str != "") {
            if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
                this->_list[str[0] - 1 - '0'].ft_get_name().size())
                break;
        }
        if (str != "")
            std::cout << INDX_ERR RESET << std::endl;
    }
    if (!std::cin.eof())
        this->ft_print_contact(this->_list[str[0] - 1 - '0']);
}

void    PhoneBook::ft_print_contact(Contact contact) {
    std::cout << std::endl << 
}
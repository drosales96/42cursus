/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:23:05 by drosales          #+#    #+#             */
/*   Updated: 2025/02/19 11:10:50 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main(void)
{
    PhoneBook   PH1;
    std::string str;

    while (str != "EXIT")
    {
        std::cout << BLUE MENU RESET;
        std::getline(std::cin, str);
        if (str == "ADD")
            PH1.ft_add_contact();
        else if (str == "SEARCH")
            PH1.ft_search_contact();
        else if (str != "EXIT") {
            std::cout << std::endl;
            std::cout << RED ERROR RESET RED MENU_ERR RESET << std::endl;
            std::cout << std::endl;
        }
        if (std::cin.eof()) {
            std::cout << std::endl;
            return (0);
        }
    }
    return (0);
}
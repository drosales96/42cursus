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
    std::cout << BLUE "HI" RESET << std::endl;
    std::cout << std::endl;
}

PhoneBook::~PhoneBook(void) {
    std::cout << BLUE "BYE BYE" RESET << std::endl;
    std::cout << std::endl;
}
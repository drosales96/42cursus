/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Setters.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:09:48 by drosales          #+#    #+#             */
/*   Updated: 2025/02/12 13:17:22 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

// Methods that takes the string, that I use as argument.

void    Contact::ft_set_name(std::string str) {
    this->_name = str;
}

void    Contact::ft_set_last_name(std::string str) {
    this->_last_name = str;
}

void    Contact::ft_set_nick(std::string str) {
    this->_nick = str;
}

void    Contact::ft_set_dark_secret(std::string str) {
    this->_dark_secret = str;
}

void    Contact::ft_set_telephone(std::string str) {
    this->_phone = str;
}
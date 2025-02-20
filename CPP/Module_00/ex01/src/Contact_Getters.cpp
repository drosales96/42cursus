/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Getters.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:48:51 by drosales          #+#    #+#             */
/*   Updated: 2025/02/12 13:17:01 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

// Calling the constructor

Contact::Contact (void){

}

//Calling the destructor

Contact::~Contact (void){

}

// Methods that returns the values from the array

std::string Contact::ft_get_name(void) const {
    return (this->_name);
}

std::string Contact::ft_get_last_name(void) const {
    return (this->_last_name);
}

std::string Contact::ft_get_nick(void) const {
    return (this->_nick);
}

std::string Contact::ft_get_dark_secret(void) const {
    return (this->_dark_secret);
}

std::string Contact::ft_get_telephone(void) const {
    return (this->_phone);
}


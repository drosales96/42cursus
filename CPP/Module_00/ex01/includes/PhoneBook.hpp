/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:28:09 by drosales          #+#    #+#             */
/*   Updated: 2025/02/19 11:16:56 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

// Colors

#include "Colors.hpp"
#include "Macros.hpp"

// Libraries

#include <iostream>
#include <string>
#include <iomanip>

// Classes

class Contact{
    
    private:

        std::string _name;
        std::string _last_name;
        std::string _nick;
        std::string _dark_secret;
        std::string _phone;

    public:

        Contact(void);
        ~Contact(void);
    
        // Functions that get the info from the array.

        std::string ft_get_name() const;
        std::string ft_get_last_name() const;
        std::string ft_get_nick() const;
        std::string ft_get_dark_secret() const;
        std::string ft_get_telephone() const;

        // Functions that takes the string, that I use as argument.

        void        ft_set_name(std::string str);
        void        ft_set_last_name(std::string str);
        void        ft_set_nick(std::string str);
        void        ft_set_dark_secret(std::string str);
        void        ft_set_telephone(std::string str);
    };


class PhoneBook{
    
    private:
    
        Contact _list[8];
        int     _id;

    public:

        PhoneBook(void);
        ~PhoneBook(void);
    
        void        ft_add_contact();
        void        ft_print_header();
        void        ft_print_contact(Contact contact);
        void        ft_search_contact();
};

// Display functions (including spaces and table sizing)

std::string         ft_table_spaces(int nbr);
std::string         ft_table_width(std::string str, long unsigned w_max);
int                 ft_display_table(Contact list[8]);

#endif
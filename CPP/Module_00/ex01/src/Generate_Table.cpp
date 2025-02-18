/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate_Table.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:48:46 by drosales          #+#    #+#             */
/*   Updated: 2025/02/18 13:37:49 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

std::string ft_table_spaces(int nbr) {
    std::string total;

    while (nbr) {
        total.append(" ");
        nbr--;
    }
    return (total);
}

std::string ft_table_widht(std::string str, long unsigned w_max) {
    if (str.size() > w_max) {
        str.resize(w_max);
        str[str.size() - 1] = '.';
    }
    return (str);
}

int ft_display_table(Contact list[8]) {
    
    int search_and_display(Contact list[8]);
    int count = 0;

    std::cout << "   ___________________________________________   \n";
    std::cout << "  |  " WHITE "Index" RESET "   |" WHITE "First Name" RESET \
    "|" WHITE "Last  Name" RESET "|" WHITE " Nickname " RESET "|  \n";
    std::cout << "  |----------|----------|----------|----------|  \n";

    for (int i = 0; i < 8; i++) {
        if (!list[i].ft_get_name().empty()) {
            count++;
            std::cout << "  |" << std::setw(10) << i + 1;
            std::cout << "|" << std::setw(10) << list[i].ft_get_name();
            std::cout << "|" << std::setw(10) << list[i].ft_get_last_name();
            std::cout << "|" << std::setw(10) << list[i].ft_get_nick();
            std::cout << "|\n";
        }
    }
    std::cout << "   -------------------------------------------   \n";
    return (count);
}
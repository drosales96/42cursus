/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate_Table.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:48:46 by drosales          #+#    #+#             */
/*   Updated: 2025/02/19 11:22:18 by drosales         ###   ########.fr       */
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

std::string ft_table_width(std::string str, long unsigned w_max) {
    if (str.size() > w_max) {
        str.resize(w_max);
        str[str.size() - 1] = '.';
    }
    return (str);
}

int ft_display_table(Contact list[8]) {
    char		c;
	int			i;
	std::string	str;

	std::cout << "   ___________________________________________   " << std::endl;
	std::cout << "  |  " WHITE "Index" RESET "   |" WHITE "First Name" RESET \
	"|" WHITE "Last  Name" RESET "|" WHITE " Nickname " RESET "|  " << std::endl;
	std::cout << "  |----------|----------|----------|----------|  " << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (list[c - 1 - '0'].ft_get_name().size() && ++i)
		{
			str = c;
			str = ft_table_width(str, 10);
			std::cout << "  |" << ft_table_spaces(10 - str.size()) << str;
			str = ft_table_width(list[c - 1 - '0'].ft_get_name(), 10);
			std::cout << "|" << ft_table_spaces(10 - str.size()) << str;
			str = ft_table_width(list[c - 1 - '0'].ft_get_last_name(), 10);
			std::cout << "|" << ft_table_spaces(10 - str.size()) << str;
			str = ft_table_width(list[c - 1 - '0'].ft_get_nick(), 10);
			std::cout << "|" << ft_table_spaces(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << "   -------------------------------------------   " << std::endl;
	return (i);
}
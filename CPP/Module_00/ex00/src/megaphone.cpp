/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 18:43:12 by drosales          #+#    #+#             */
/*   Updated: 2025-02-10 18:43:12 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *av[])
{
    int i, j;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        for (i = 1; i < ac; ++i)
        {
            for (j = 0; j < av[i][j]; ++j)
            {
                std::cout << static_cast<char>(toupper(av[i][j]));
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}

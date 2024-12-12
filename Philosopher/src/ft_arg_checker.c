/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:58:09 by drosales          #+#    #+#             */
/*   Updated: 2024/12/12 21:08:35 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_validating_args(char	*av)
{
	int	i;

	i = 0;
	if (av == NULL)
		return (1);
	while (av[i])
	{
		if (!ft_is_digit(av[i]))
			return (1);
		else
			break ;
		i++;
	}
	return (0);
}

int	ft_checking_arguments(char **av)
{
	if (ft_atoi(av[1]) > 100 || ft_atoi(av[1]) < 0
		|| ft_validating_args(av[1]) == 1)
		return (printf("Philosophers: invalid number os philos'\n"));
	if (ft_atoi(av[2]) <= 0 || ft_validating_args(av[2]) == 1)
		return (printf("Philosopher: invalid time to die \n"));
	if (ft_atoi(av[3]) <= 0 || ft_validating_args(av[3]) == 1)
		return (printf("Philosophers: invalid time to eat \n"));
	if (ft_atoi(av[4]) <= 0 || ft_validating_args(av[4]) == 1)
		return (printf("Philosophers: invalid time to sleep \n"));
	if (av[5] && (ft_atoi(av[5]) < 0 || ft_validating_args(av[5]) == 1))
		return (printf("Philosophers: invalid argument about meals \n"));
	return (0);
}

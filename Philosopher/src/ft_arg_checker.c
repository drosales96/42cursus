/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:58:09 by drosales          #+#    #+#             */
/*   Updated: 2024/12/17 18:46:20 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_validating_args(char	*av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_is_digit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checking_arguments(char **av)
{
	if (ft_validating_args(av[1]) || ft_atoi(av[1]) <= 0 \
		|| ft_atoi(av[1]) > PHILO_MAX)
		return (printf("Philosophers: invalid number of philosophers!\n"), 1);
	if (ft_validating_args(av[2]) || ft_atoi(av[2]) <= 0)
		return (printf("Philosophers: invalid time to die\n"), 1);
	if (ft_validating_args(av[3]) || ft_atoi(av[3]) <= 0)
		return (printf("Philosophers: invalid time to eat\n"), 1);
	if (ft_validating_args(av[4]) || ft_atoi(av[4]) <= 0)
		return (printf("Philosophers: invalid time to sleep\n"), 1);
	if (av[5] && (ft_validating_args(av[5]) || ft_atoi(av[5]) < 0))
		return (printf("Philosophers: invalid argument about meals\n"), 1);
	return (0);
}
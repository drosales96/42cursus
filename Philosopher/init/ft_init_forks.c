/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:24:56 by drosales          #+#    #+#             */
/*   Updated: 2024/12/14 12:11:04 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_init_forks(pthread_mutex_t *forks, int philos)
{
    int i;

    i = 0;
    while (i < philos)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}
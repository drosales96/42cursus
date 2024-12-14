/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:25:07 by drosales          #+#    #+#             */
/*   Updated: 2024/12/14 11:02:47 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_init_table(t_table *table, t_philo *philo)
{
    table->flag = 0;
    table->philo = philo;
    pthread_mutex_init(&table->write_lock, NULL);
    pthread_mutex_init(&table->dead_lock, NULL);
    pthread_mutex_init(&table->meal_lock, NULL);
}
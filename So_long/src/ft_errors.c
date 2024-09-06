/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:30:17 by drosales          #+#    #+#             */
/*   Updated: 2024/09/06 11:35:43 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error2(t_elements *data, int num)
{
	data->moves++;
	data->moves--;
	if (num == 8)
		write(1, "►El mapa contiene caracteres erroneos.\n", 41);
	if (num == 9)
		write(1, "►El mapa no es rectangular\n", 29);
}

void	ft_error(t_elements *data, int num)
{
	write(1, "❌ERROR❌\n", 12);
	if (num > 7)
		ft_error2(data, num);
	if (num == 1)
		write(1, "►En el principio de linea no hay pared.🧱\n", 46);
	if (num == 2)
		write(1, "►En el final de linea no hay pared.🧱\n", 42);
	if (num == 3)
		write(1, "►En la primera linea no hay pared.🧱\n", 41);
	if (num == 4)
		write(1, "►En la ultima linea no hay pared.🧱\n", 40);
	if (data->collect < 1 && num == 5)
		write(1, "►No hay consumibles!\n", 21);
	if (data->pl != 1 && num == 5)
		write(1, "►El mapa solo debe tener un personaje. 🚶🏻‍♂️\n", 59);
	if (data->ex < 1 && num == 5)
		write(1, "►El mapa debe contener una salida. \n", 38);
	if (num == 6)
		write(1, "►El fichero no tiene la extension correcta.\n", 46);
	if (num == 7)
		write(1, "►El mapa no es rectangular.\n", 30);
	ft_free(data);
}
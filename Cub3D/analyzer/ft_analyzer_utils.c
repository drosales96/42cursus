/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyzer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:29:59 by drosales          #+#    #+#             */
/*   Updated: 2025/02/05 11:37:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_map_dimensions" calculates the dimensions (width and 
 * height) of a 2D map array and stores them in the corresponding structure 
 * fields.
 * 
 * @param t_map *map          A pointer to the map structure containing the
 *                            2D array and its dimension fields.
 * 
 * @return void               This function does not return a value.
 *                            It updates the structure directly.
 * 
 * The function "ft_map_spliting" validates and splits a map string into a 2D
 * array of strings (matrix). It ensures the map string is properly formatted
 * and splits it by newline characters.
 * 
 * @param t_cub3d *cub        A pointer to the structure where the map data
 *                            will be stored.
 * @param char *map           The map string to validate and split.
 * 
 * @return int                Returns EXIT_SUCCESS if the map is valid and 
 * 							  split successfully. Returns EXIT_FAILURE on 
 * 							  error.
 * 
 * The function "ft_matrix_to_str" reads a map from a file descriptor and
 * concatenates its lines into a single string. It handles errors during file
 * reading and memory allocation.
 * 
 * @param char *c             The first line of the map, passed as an initial
 *                            string to join.
 * @param int fd              The file descriptor from which to read the map.
 * 
 * @return char*              Returns the concatenated map string on success.
 *                            Returns NULL if an error occurs.
 * 
 * The function "ft_checking_lines" validates the structure of a map string by
 * checking for invalid empty lines or extra spaces between lines. It ensures
 * that the map does not contain empty lines between valid rows or at the end.
 * 
 * @param char *map            The map string to validate.
 * 
 * @return int                 Returns EXIT_SUCCESS if the map is valid.
 *                             Returns EXIT_FAILURE if invalid lines are found.
 * 
 */

int	ft_checking_lines(char	*map)
{
	int	i;

	if (!map || !map[0])
		return (ft_manage_err(MAP_ERR), EXIT_FAILURE);
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] == ' ')
				i++;
			if (map[i] == '\n' || map[i] == '\0')
				return (ft_manage_err(EXTRA_LINE_ERR), EXIT_FAILURE);
		}
		else
			i++;
	}
	return (EXIT_SUCCESS);
}

char	*ft_matrix_to_str(char *c, int fd)
{
	char	*map;
	char	*temp;

	map = NULL;
	while (c)
	{
		temp = ft_new_strjoin(map, c);
		if (!temp)
		{
			free(c);
			return (ft_manage_err(MATRIX_TO_STR_ERR), NULL);
		}
		map = temp;
		free(c);
		c = get_next_line(fd);
	}
	return (map);
}

int	ft_map_spliting(t_cub3d *cub, char *map)
{
	int	flag;

	flag = 0;
	if (ft_checking_lines(map))
		flag = 1;
	if (flag == 1)
		return (free(map), EXIT_FAILURE);
	cub->map.map = ft_split(map, '\n');
	free(map);
	if (!cub->map.map)
		return (ft_manage_err(FT_SPLIT_ERR), EXIT_FAILURE);
	cub->map.line_map = ft_split_len(cub->map.map);
	return (EXIT_SUCCESS);
}

void	ft_map_dimensions(t_map *map)
{
	int	i;
	int	j;
	int	len;

	if (!map->map || !map->map[0])
		return ;
	i = 0;
	j = 0;
	while (map->map[i])
	{
		len = ft_strlen(map->map[i]);
		if (len > j)
			j = len;
		i++;
	}
	map->x_map = j;
	map->y_map = i;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:37:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/27 11:47:53 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_player(t_map *map)
{
	if (!map->begin)
		print_map_error("No map found", map);
	if (map->player_dir == '0' || map->player_x == -1 || map->player_y == -1)
		print_map_error("The player's position has not been defined", map);
}

void	fill_player_vars(t_map *map)
{
	size_t	i;
	int		j;
	size_t	len;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		len = ft_strlen(map->matrix[j]);
		while (i < len)
		{
			if (map->matrix[j][i] == 'N' || map->matrix[j][i] == 'S'
				|| map->matrix[j][i] == 'E' || map->matrix[j][i] == 'W')
			{
				map->player_y = j;
				map->player_x = i;
				if (map->player_dir == '0')
					map->player_dir = map->matrix[j][i];
				else
					print_map_error("There can only be one player", map);
			}
			i++;
		}
		j++;
	}
}

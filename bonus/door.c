/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:52:33 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/17 12:35:22 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_is_door(float x, float y, t_cub3d *cub)
{
	char	**worldmap;

	worldmap = cub->map->matrix;
	if (worldmap[(int)y][(int)x] == 'D' || worldmap[(int)y][(int)x] == 'd')
		return (true);
	return (false);
}

static void	switch_door(t_cub3d *cub, int x, int y)
{
	if (cub->map->matrix[y][x] == 'D')
		cub->map->matrix[y][x] = 'd';
	else if (cub->map->matrix[y][x] == 'd')
	{
		if (!(x == (int)cub->player.pos_x && y == (int)cub->player.pos_y))
			cub->map->matrix[y][x] = 'D';
	}
}

void	opendoor(t_cub3d *cub)
{
	double	dir_x;
	double	dir_y;

	dir_x = ft_abs(cub->player.dir_x);
	dir_y = ft_abs(cub->player.dir_y);
	if (dir_y > dir_x && ft_is_door(cub->player.pos_x, \
			cub->player.pos_y + cub->player.dir_y, cub))
		switch_door(cub, cub->player.pos_x,
			cub->player.pos_y + cub->player.dir_y);
	else if (dir_y < dir_x && ft_is_door(cub->player.pos_x + cub->player.dir_x,
			cub->player.pos_y, cub))
		switch_door(cub, cub->player.pos_x + cub->player.dir_x,
			cub->player.pos_y);
}

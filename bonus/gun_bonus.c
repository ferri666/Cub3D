/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:48:49 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/26 12:48:34 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_gun(t_cub3d *c)
{
	static float	i = -25;
	static int		dir = 1;

	mlx_put_image_to_window(c->mlx.mlx, c->mlx.window,
		c->images.gun.img, 500, 520 + i);
	if (dir)
		i += 0.5;
	else
		i -= 0.5;
	if (i == 0)
		dir = 0;
	if (i == -25)
		dir = 1;
	if (c->bang)
	{
		mlx_put_image_to_window(c->mlx.mlx, c->mlx.window,
			c->images.bang.img, 0, 0);
		c->bang--;
	}
}

int	render(t_cub3d *cub)
{
	t_mlx			mlx;

	mlx = cub->mlx;
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img, 0, 0);
	draw_gun(cub);
	if (cub->minmap)
	{
		mlx_put_image_to_window(mlx.mlx, mlx.window,
			cub->images.mmap.img, 30, 5);
	}
	return (0);
}

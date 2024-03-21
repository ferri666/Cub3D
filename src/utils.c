/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:30:25 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/17 12:02:18 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	put_pixel(t_mlx *mlx, int color, int x, int y)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->l_length + x
			*(mlx->bit_x_pixl / 8));
	*(unsigned int *) dst = color;
}

void	fill(t_mlx *mlx, int color)
{
	int		i;
	int		j;

	j = -1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_WIDTH)
			put_pixel(mlx, color, i, j);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:01:00 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/26 12:57:51 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_square(t_mlx *m, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			put_pixel(m, color, x + i, y + j);
	}
}

static void	fill_mmap(t_mlx *mmap, t_cub3d *c)
{
	int	i;
	int	j;

	j = -1;
	while (++j < c->map->height)
	{
		i = -1;
		while (++i < c->map-> width)
		{
			if (i >= (int) ft_strlen(c->map->matrix[j]))
				put_square(mmap, i * 10, j * 10, 0x061647);
			else if (c->map->matrix[j][i] == '1' || c->map->matrix[j][i] == 'D')
				put_square(mmap, i * 10, j * 10, 0x061647);
			else
				put_square(mmap, i * 10, j * 10, 0x30485C);
		}
	}
}

static void	put_player(t_mlx *mmap, t_cub3d *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			put_pixel(mmap, 0x9CE3A8, c->player.pos_x * 10 + j,
				c->player.pos_y * 10 + i);
	}
}

void	draw_mini_map(t_cub3d *cub)
{
	t_images	*back;

	back = &cub->images;
	back->mmap.img = mlx_new_image(cub->mlx.mlx, cub->map->width * 10,
			cub->map->height * 10);
	back->mmap.addr = mlx_get_data_addr(back->mmap.img, &back->mmap.bit_x_pixl,
			&back->mmap.l_length, &back->mmap.endian);
	fill_mmap(&back->mmap, cub);
	put_player(&back->mmap, cub);
}

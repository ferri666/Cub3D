/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:31:17 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/13 17:46:26 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*update_adress(t_mlx *m)
{
	return (mlx_get_data_addr(m->img, &m->bit_x_pixl,
			&m->l_length, &m->endian));
}

void	*create_image(t_mlx *mlx, char *path, t_cub3d *cub)
{
	int		fd;
	int		x;
	int		y;
	void	*img;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Texture not found\n", 2);
		exit_game(cub, EXIT_FAILURE);
	}
	close (fd);
	img = mlx_xpm_file_to_image(mlx, path, &x, &y);
	return (img);
}

void	fill_images_struct(t_cub3d *cub3d, t_images *images)
{
	images->gun.img = create_image(cub3d->mlx.mlx,
			"textures/assets/GUN.xpm", cub3d);
	images->walls[SOUTH].img = create_image(cub3d->mlx.mlx,
			cub3d->map->textures[SOUTH], cub3d);
	images->walls[NORTH].img = create_image(cub3d->mlx.mlx,
			cub3d->map->textures[NORTH], cub3d);
	images->walls[WEST].img = create_image(cub3d->mlx.mlx,
			cub3d->map->textures[WEST], cub3d);
	images->walls[EAST].img = create_image(cub3d->mlx.mlx,
			cub3d->map->textures[EAST], cub3d);
	images->bang.img = mlx_new_image(cub3d->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	images->walls[SOUTH].addr = update_adress(&images->walls[SOUTH]);
	images->walls[NORTH].addr = update_adress(&images->walls[NORTH]);
	images->walls[WEST].addr = update_adress(&images->walls[WEST]);
	images->walls[EAST].addr = update_adress(&images->walls[EAST]);
	images->gun.addr = update_adress(&images->gun);
	images->bang.addr = update_adress(&images->bang);
	fill(&images->bang, 0xFF581E);
}

t_images	images(t_cub3d *cub3d)
{
	t_images	images;

	images.floor = cub3d->map->floor;
	images.ceiling = cub3d->map->ceiling;
	images.walls = ft_calloc(sizeof(t_mlx), 5);
	fill_images_struct(cub3d, &images);
	return (images);
}

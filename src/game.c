/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:19:24 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/26 12:21:23 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycast	init_raycast(void)
{
	t_raycast	ray;

	ray.ray_dir_x = 0;
	ray.ray_dir_y = 0;
	ray.line_height = 0;
	ray.draw_from = 0;
	ray.draw_to = 0;
	ray.map_x = 0;
	ray.map_y = 0;
	ray.tex_x = 0;
	ray.tex_y = 0;
	ray.tex_step = 0;
	ray.tex_pos = 0;
	ray.tex_wall_x = 0;
	ray.side_dist_x = 0;
	ray.side_dist_y = 0;
	ray.delta_dist_x = 0;
	ray.delta_dist_y = 0;
	ray.perp_wall_dist = 0;
	ray.step_x = 0;
	ray.step_y = 0;
	ray.side_hit = false;
	ray.wall_hit = false;
	return (ray);
}

static void	fill_player(t_player *pl, int dx, int dy)
{
	pl->dir_x = dx;
	pl->dir_y = dy;
	if (dx)
	{
		pl->plane_y = 0.66;
		pl->plane_x = 0;
	}
	else
	{
		pl->plane_x = 0.66;
		pl->plane_y = 0;
	}
	if (dx < 0)
		pl->plane_y *= -1.0;
	if (dy > 0)
		pl->plane_x *= -1.0;
}

t_player	init_player(t_cub3d *cub3d)
{
	t_player	player;

	player.pos_x = cub3d->map->player_x + 0.5;
	player.pos_y = cub3d->map->player_y + 0.5;
	if (cub3d->map->player_dir == 'E')
		fill_player(&player, 1, 0);
	else if (cub3d->map->player_dir == 'W')
		fill_player(&player, -1, 0);
	else if (cub3d->map->player_dir == 'N')
		fill_player(&player, 0, -1);
	else if (cub3d->map->player_dir == 'S')
		fill_player(&player, 0, 1);
	return (player);
}

int	start_game(t_cub3d *cub3d)
{
	t_mlx	*mlx;

	mlx = &cub3d->mlx;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bit_x_pixl,
			&mlx->l_length, &mlx->endian);
	raycasting(cub3d);
	return (0);
}

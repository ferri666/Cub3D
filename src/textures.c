/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:13:17 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/19 15:09:35 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calc_tex_positions(t_cub3d *cub)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	if (!ray->side_hit)
		ray->tex_wall_x = cub->player.pos_y + ray->perp_wall_dist \
			* ray->ray_dir_y;
	else
		ray->tex_wall_x = cub->player.pos_x + ray->perp_wall_dist \
			* ray->ray_dir_x;
	ray->tex_wall_x -= floor(ray->tex_wall_x);
	ray->tex_x = ray->tex_wall_x * 64;
	if (!ray->side_hit && ray->ray_dir_x < 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	if (ray->side_hit && ray->ray_dir_y > 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	ray->tex_step = 1.0 * 64 / ray->line_height;
	ray->tex_pos = (ray->draw_from - WIN_HEIGHT / 2 \
		+ ray->line_height / 2) * ray->tex_step;
}

static void	ft_draw_floor_ceiling(t_cub3d *cub, int x, int from)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < from)
			put_pixel(&cub->mlx, cub->images.ceiling, x, y);
		else
			put_pixel(&cub->mlx, cub->images.floor, x, y);
	}
}

int	ft_get_pixel_color(t_mlx *mlx, int x, int y)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->l_length + x
			* (mlx->bit_x_pixl / 8));
	return (*(unsigned int *) dst);
}

static void	ft_apply_texture(t_cub3d *cub, int direction, int x)
{
	int	color;

	color = ft_get_pixel_color(&cub->images.walls[direction], \
		cub->raycast.tex_x, cub->raycast.tex_y);
	put_pixel(&cub->mlx, color, x, cub->raycast.draw_from);
}

void	ft_draw_textures(t_cub3d *cub, int x)
{
	t_raycast	*ray;

	ray = &cub->raycast;
	ft_calc_tex_positions(cub);
	ft_draw_floor_ceiling(cub, x, ray->draw_from);
	while (ray->draw_from < ray->draw_to)
	{
		ray->tex_y = (int)ray->tex_pos & (64 - 1);
		ray->tex_pos += ray->tex_step;
		if (!ray->side_hit && cub->player.pos_x < ray->map_x)
			ft_apply_texture(cub, WEST, x);
		else if (!ray->side_hit && cub->player.pos_x > ray->map_x)
			ft_apply_texture(cub, EAST, x);
		else if (ray->side_hit && cub->player.pos_y < ray->map_y)
			ft_apply_texture(cub, NORTH, x);
		else if (ray->side_hit && cub->player.pos_y > ray->map_y)
			ft_apply_texture(cub, SOUTH, x);
		ray->draw_from++;
	}
}

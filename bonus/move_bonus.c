/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:03:57 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/26 13:05:08 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Is this coordinate on the map a wall or door?
*/
bool	ft_is_wall(float x, float y, t_cub3d *cub)
{
	char	**worldmap;

	worldmap = cub->map->matrix;
	if (worldmap[(int)y][(int)x] == '1' || worldmap[(int)y][(int)x] == 'D')
		return (true);
	return (false);
}

void	move_left_right(int keycode, t_cub3d *cub)
{
	double	speed;

	if (cub->run)
		speed = RUN_SPEED;
	else
		speed = WALK_SPEED;
	if (keycode == KEY_A)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_y * \
				(speed + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_y * speed;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y - \
				cub->player.dir_x * (speed + 0.1), cub))
			cub->player.pos_y -= cub->player.dir_x * speed;
	}
	if (keycode == KEY_D)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_y * \
				(speed + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_y * speed;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y + \
				cub->player.dir_x * (speed + 0.1), cub))
			cub->player.pos_y += cub->player.dir_x * speed;
	}
	draw_mini_map(cub);
}

void	move_up_down(int keycode, t_cub3d *cub)
{
	double	speed;

	if (cub->run)
		speed = RUN_SPEED;
	else
		speed = WALK_SPEED;
	if (keycode == KEY_W || keycode == 126)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_x * \
				(speed + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_x * speed;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y + \
				cub->player.dir_y * (speed + 0.1), cub))
			cub->player.pos_y += cub->player.dir_y * speed;
	}
	if (keycode == KEY_S || keycode == 125)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_x * \
				(speed + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_x * speed;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y - \
				cub->player.dir_y * (speed + 0.1), cub))
			cub->player.pos_y -= cub->player.dir_y * speed;
	}
	draw_mini_map(cub);
}

void	move_rotate(int keycode, t_cub3d *cub)
{
	double	r_speed;
	double	tmpx;

	r_speed = 0;
	if (keycode == K_LEFT)
		r_speed = ROT_SPEED * -1;
	else if (keycode == K_RIGHT)
		r_speed = ROT_SPEED;
	if (r_speed)
	{
		tmpx = cub->player.dir_x;
		cub->player.dir_x = cub->player.dir_x * cos(r_speed)
			- cub->player.dir_y * sin(r_speed);
		cub->player.dir_y = tmpx * sin(r_speed)
			+ cub->player.dir_y * cos(r_speed);
		tmpx = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x * cos(r_speed)
			- cub->player.plane_y * sin(r_speed);
		cub->player.plane_y = tmpx * sin(r_speed)
			+ cub->player.plane_y * cos(r_speed);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:52:09 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/17 13:24:46 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press_handler(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
		ft_close(cub);
	if (keycode == KEY_SHIFT)
		cub->run = 1;
	if (keycode == KEY_SPACE)
		opendoor(cub);
	if (keycode == KEY_M)
	{
		if (cub->minmap)
			cub->minmap = 0;
		else
			cub->minmap = 1;
	}
	ft_move_up_down(keycode, cub);
	ft_move_left_right(keycode, cub);
	ft_move_rotate(keycode, cub);
	start_game(cub);
	return (0);
}

int	ft_key_rel_handler(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_SHIFT)
		cub->run = 0;
	return (0);
}

int	ft_mouse_handler(int button, int x, int y, t_cub3d *cub)
{
	if (button == 1 && y > 10 && x > 0)
	{
		cub->bang = 2;
		printf("BANG!\n");
	}
	return (0);
}

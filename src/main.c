/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:04:36 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/20 15:07:57 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycast	raycast(void)
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

t_mlx	init_mlx(void)
{
	t_mlx	m;

	m.mlx = mlx_init();
	m.window = mlx_new_window(m.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	m.img = mlx_new_image(m.mlx, WIN_WIDTH, WIN_HEIGHT);
	m.addr = mlx_get_data_addr(m.img, &m.bit_x_pixl, &m.l_length, &m.endian);
	return (m);
}

void	init_game(t_cub3d *cub3d)
{
	cub3d->mlx = init_mlx();
	cub3d->images = images(cub3d);
	cub3d->player = player(cub3d);
	cub3d->raycast = raycast();
	cub3d->run = 0;
	cub3d->bang = 0;
	cub3d->minmap = 0;
}

int	ft_close(t_cub3d *cub)
{
	if (!cub)
		return (1);
	if (cub->mlx.window)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.window);
	if (cub->mlx.img)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	exit_game(cub, EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (!parse_args(argc, argv))
		print_error("Los argumentos no son validos");
	cub3d = init_cub3d(argv[1]);
	init_game(cub3d);
	start_game(cub3d);
	mlx_hook(cub3d->mlx.window, 2, 1L << 0, ft_key_press_handler, cub3d);
	mlx_hook(cub3d->mlx.window, 3, 1L << 1, ft_key_rel_handler, cub3d);
	mlx_hook(cub3d->mlx.window, 17, 1L << 17, ft_close, cub3d);
	mlx_mouse_hook(cub3d->mlx.window, ft_mouse_handler, cub3d);
	mlx_loop_hook(cub3d->mlx.mlx, render, cub3d);
	mlx_loop(cub3d->mlx.mlx);
}

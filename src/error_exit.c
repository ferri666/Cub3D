/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:18 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/24 11:56:29 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(t_cub3d *cub, int ext_n)
{
	if (cub)
	{
		if (cub->map->matrix)
			ft_free_matrix((void **)cub->map->matrix);
		if (cub->map->textures)
			ft_free_matrix((void **)cub->map->textures);
		if (cub->map)
			free(cub->map);
		if (cub->images.walls)
			free(cub->images.walls);
		free(cub);
	}
	exit(ext_n);
}

void	print_map_error(char *err_msg, t_map *map)
{
	printf("Error: %s\n", err_msg);
	if (map->matrix)
		ft_free_matrix((void **)map->matrix);
	if (map->textures)
	{
		if (map->textures[SOUTH])
			free(map->textures[SOUTH]);
		if (map->textures[NORTH])
			free(map->textures[NORTH]);
		if (map->textures[WEST])
			free(map->textures[WEST]);
		if (map->textures[EAST])
			free(map->textures[EAST]);
		free(map->textures);
	}
	if (map)
		free(map);
	exit(EXIT_FAILURE);
}

void	print_error(char *err_msg)
{
	printf("Error: %s\n", err_msg);
	exit(EXIT_FAILURE);
}

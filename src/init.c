/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:56:30 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/20 15:08:17 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	imprimir_estructura_mapa(t_map *map)
{
	int	i;

	printf("ceiling: %x\n", map->ceiling);
	printf("floor: %x\n", map->floor);
	printf("texture: %s\n", map->textures[NORTH]);
	printf("texture: %s\n", map->textures[SOUTH]);
	printf("texture: %s\n", map->textures[WEST]);
	printf("texture: %s\n", map->textures[EAST]);
	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->matrix[i]);
		i++;
	}
	printf("height: %d\n", map->height);
	printf("width: %d\n", map->width);
	printf("player_x: %d\n", map->player_x);
	printf("player_y: %d\n", map->player_y);
	printf("player_dir: %c\n", map->player_dir);
}

t_cub3d	*init_cub3d(char *path)
{
	t_cub3d	*cub3d;
	t_map	*mymap;

	mymap = map(path);
	cub3d = ft_calloc(1, sizeof(t_cub3d));
	if (!cub3d)
	{
		print_map_error("Fallo en malloc", mymap);
	}
	cub3d->map = mymap;
	return (cub3d);
}

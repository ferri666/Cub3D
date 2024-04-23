/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:07:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/27 11:44:35 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_size(t_map *map)
{
	if (map->width < 3 || map->height < 3)
		print_map_error("The map must be at least 3x3", map);
}

static void	floodfill(t_map *map, int **visited, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
	{
		ft_free_matrix((void **)visited);
		print_map_error("The map is not closed", map);
	}
	if (map->matrix[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	floodfill(map, visited, x + 1, y);
	floodfill(map, visited, x - 1, y);
	floodfill(map, visited, x, y + 1);
	floodfill(map, visited, x, y - 1);
}

void	map_closed(t_map *map)
{
	int	**visited;
	int	i;

	visited = ft_calloc(map->height + 1, sizeof(int *));
	if (!visited)
		print_map_error("The matrix could not be created", map);
	i = 0;
	while (i < map->height)
	{
		visited[i] = ft_calloc(map->width + 1, sizeof(int));
		if (!visited[i])
		{
			ft_free_matrix((void **)visited);
			print_map_error("The matrix could not be created", map);
		}
		i++;
	}
	floodfill(map, visited, map->player_x, map->player_y);
	ft_free_matrix((void **)visited);
}

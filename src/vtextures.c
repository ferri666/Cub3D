/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtextures.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:08:48 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/19 16:23:59 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_this_valid(char *line, char letter)
{
	if (line[0] != letter)
		return (1);
	if (line[1] == ' ')
		return (0);
	if (letter == 'N' || letter == 'S')
	{
		if (line[1] != 'O')
			return (1);
		return (0);
	}
	else if (letter == 'W')
	{
		if (line[1] != 'E')
			return (1);
		return (0);
	}
	else if (letter == 'E')
	{
		if (line[1] != 'A')
			return (1);
		return (0);
	}
	return (1);
}

void	fill_texture(t_map *map, char *line)
{
	while (*line == ' ')
		line++;
	if (!is_this_valid(line, 'N') && map->textures[NORTH] == NULL)
		map->textures[NORTH] = ft_strtrim(line, "NO \t");
	else if (!is_this_valid(line, 'S') && map->textures[SOUTH] == NULL)
		map->textures[SOUTH] = ft_strtrim(line, "SO \t");
	else if (!is_this_valid(line, 'W') && map->textures[WEST] == NULL)
		map->textures[WEST] = ft_strtrim(line, "WE \t");
	else if (!is_this_valid(line, 'E') && map->textures[EAST] == NULL)
		map->textures[EAST] = ft_strtrim(line, "EA \t");
	else
		print_map_error("La textura solo se puede definir una vez", map);
}

void	validate_text(char **textures_arr, t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(textures_arr[i] + ft_strlen(textures_arr[i]) - 4,
				".xpm", 4))
		{
			print_map_error("Las texturas deben ser archivos .xpm", map);
		}
		if (open(textures_arr[i], O_RDONLY) < 0)
		{
			close(open(textures_arr[i], O_RDONLY));
			print_map_error("No se ha podido abrir el archivo de textura", map);
		}
		i++;
	}
}

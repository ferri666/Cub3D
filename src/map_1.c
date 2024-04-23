/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:31 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/27 11:46:06 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_errors(t_map *map)
{
	if (map->ceiling < 0)
		printf("Error: Ceiling color not defined\n");
	if (map->floor < 0)
		printf("Error: Floor color not defined\n");
	if (ft_arraylen(map->textures) < 4)
		printf("Error: Not all textures have been defined\n");
	if (map->end)
		print_map_error("The map must be the last element", map);
	else
		print_map_error("Not all elements are present before the map", map);
}

static void	validate_chars(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->matrix[i]);
		j = 0;
		while (j < len)
		{
			if (map->matrix[i][j] == ' ')
				map->matrix[i][j] = '1';
			if (map->matrix[i][j] != '1' && map->matrix[i][j] != '0'
				&& map->matrix[i][j] != 'N'
				&& map->matrix[i][j] != 'S' && map->matrix[i][j] != 'E'
				&& map->matrix[i][j] != 'W')
				print_map_error("The map contains invalid characters", map);
			j++;
		}
		i++;
	}
}

static void	fill_map_append(t_map *map, char *line)
{
	if ((*line == 'N' || *line == 'S' || *line == 'E'
			|| *line == 'W'))
		fill_texture(map, line);
	else if ((*line == 'C' || *line == 'F'))
		fill_color(map, line);
	else if (only_matrix(map) && !map->end)
	{
		map->begin = 1;
		map->matrix = ft_arraypush(map->matrix, ft_strdup(line));
		if (!map->matrix)
			print_map_error("The matrix could not be created", map);
		if ((int)ft_strlen(line) > map->width)
			map->width = (int)ft_strlen(line);
		map->height++;
	}
	else
		print_errors(map);
}

static void	fill_map(t_map *map, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (only_matrix(map))
			line = ft_strtrim2(line, "\t\n");
		else
			line = ft_strtrim2(line, " \t\n");
		if (*line == '\0')
		{
			free(line);
			if (only_matrix(map) && map->begin)
				map->end = 1;
			continue ;
		}
		fill_map_append(map, line);
		free(line);
	}
	close(fd);
}

t_map	*map(char *path)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->player_dir = '0';
	map->ceiling = -1;
	map->floor = -1;
	map->end = 0;
	map->begin = 0;
	map->textures = ft_calloc(5, sizeof(char *));
	if (!map->textures)
		print_map_error("The texture array could not be created", map);
	map->matrix = ft_calloc(1, sizeof(char *));
	if (!map->matrix)
		print_map_error("The matrix could not be created", map);
	fill_map(map, path);
	fill_player_vars(map);
	validate_player(map);
	validate_text(map->textures, map);
	validate_chars(map);
	validate_size(map);
	map_closed(map);
	return (map);
}

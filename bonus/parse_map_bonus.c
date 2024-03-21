/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:31 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/20 12:02:23 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_chars(t_map *map)
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
				&& map->matrix[i][j] != 'W' && map->matrix[i][j] != 'D')
				print_map_error("El mapa contiene caracteres invalidos", map);
			j++;
		}
		i++;
	}
}

void	fill_map_append(t_map *map, char *line)
{
	if ((*line == 'N' || *line == 'S' || *line == 'E'
			|| *line == 'W'))
		fill_texture(map, line);
	else if ((*line == 'C' || *line == 'F'))
		fill_color(map, line);
	else if (solo_falta_matrix(map))
	{
		map->matrix = ft_arraypush(map->matrix, ft_strdup(line));
		if (!map->matrix)
			print_map_error("No se ha podido crear la matriz", map);
		if ((int)ft_strlen(line) > map->width)
			map->width = (int)ft_strlen(line);
		map->height++;
	}
	else
	{
		if (map->ceiling < 0)
			printf("Error: No se ha definido el color del techo\n");
		if (map->floor < 0)
			printf("Error: No se ha definido el color del suelo\n");
		if (ft_arraylen(map->textures) < 4)
			printf("Error: No se han definido todas las texturas\n");
		print_map_error("El mapa debe ser el ultimo elemento\n", map);
	}
}

void	fill_map(t_map *map, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_map_error("No se pudo abrir el archivo", map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (solo_falta_matrix(map))
			line = ft_strtrim2(line, "\t\n");
		else
			line = ft_strtrim2(line, " \t\n");
		if (*line == '\0')
		{
			free(line);
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
	map->textures = ft_calloc(5, sizeof(char *));
	if (!map->textures)
		print_map_error("No se ha podido crear el array de texturas", map);
	map->matrix = ft_calloc(1, sizeof(char *));
	if (!map->matrix)
		print_map_error("No se ha podido crear la matriz", map);
	fill_map(map, path);
	fill_player_vars(map);
	validate_text(map->textures, map);
	validate_chars(map);
	validate_player(map);
	validate_size(map);
	map_closed(map);
	return (map);
}

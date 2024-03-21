/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:08:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/19 18:31:35 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_color(char **strs, char *line, int *rgb)
{
	if (strs)
		ft_free_matrix((void **)strs);
	if (line)
		free(line);
	if (rgb)
		free(rgb);
}

int	rgb_range(int rgb)
{
	if (rgb < 0 || rgb > 255)
		return (1);
	return (0);
}

int	*take_rgb(char *line, t_map *map)
{
	int		*rgb;
	char	**strs;

	rgb = ft_calloc(sizeof(int), 4);
	if (!rgb)
		return (NULL);
	strs = ft_split(line, ',');
	if (!strs)
		return (NULL);
	if (ft_arraylen(strs) != 3 || !ft_ids2(strs[0])
		|| !ft_ids2(strs[1]) || !ft_ids2(strs[2]))
	{
		free_color(strs, line, rgb);
		print_map_error("El color debe tener 3 componentes numéricos", map);
	}
	rgb[0] = ft_atoi(strs[0]);
	rgb[1] = ft_atoi(strs[1]);
	rgb[2] = ft_atoi(strs[2]);
	if (rgb_range(rgb[0]) || rgb_range(rgb[1]) || rgb_range(rgb[2]))
	{
		free_color(strs, line, rgb);
		print_map_error("Debe ser rgb valido, 255 < 0", map);
	}
	free_color(strs, line, NULL);
	return (rgb);
}

int	rgb_to_hex(int *rgb)
{
	int	hex;

	hex = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	free(rgb);
	return (hex);
}

void	fill_color(t_map *map, char *line)
{
	int	*rgb;

	if (line[0] == 'C')
	{
		if (map->ceiling < 0)
		{
			line = ft_strtrim(line, "CF \t");
			rgb = take_rgb(line, map);
			map->ceiling = rgb_to_hex(rgb);
		}
		else
			print_map_error("Definido el color del techo más de una vez", map);
	}
	else if (line[0] == 'F')
	{
		if (map->floor < 0)
		{
			line = ft_strtrim(line, "CF \t");
			rgb = take_rgb(line, map);
			map->floor = rgb_to_hex(rgb);
		}
		else
			print_map_error("Definido el color del suelo más de una vez", map);
	}
}

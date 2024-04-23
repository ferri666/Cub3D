/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:08:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/27 11:50:47 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_color(char **strs, char *line, int *rgb)
{
	if (strs)
		ft_free_matrix((void **)strs);
	if (line)
		free(line);
	if (rgb)
		free(rgb);
}

static int	rgb_range(int rgb)
{
	if (rgb < 0 || rgb > 255)
		return (1);
	return (0);
}

static int	*take_rgb(char *line, t_map *map)
{
	int		*rgb;
	char	**strs;

	rgb = ft_calloc(sizeof(int), 4);
	if (!rgb)
		return (NULL);
	strs = ft_split(line, ',');
	if (!strs)
		return (NULL);
	if (ft_arraylen(strs) != 3 || !ft_idos(strs[0])
		|| !ft_idos(strs[1]) || !ft_idos(strs[2]))
	{
		free_color(strs, line, rgb);
		print_map_error("The color must have 3 numerical components", map);
	}
	rgb[0] = ft_atoi(strs[0]);
	rgb[1] = ft_atoi(strs[1]);
	rgb[2] = ft_atoi(strs[2]);
	if (rgb_range(rgb[0]) || rgb_range(rgb[1]) || rgb_range(rgb[2]))
	{
		free_color(strs, line, rgb);
		print_map_error("It must be a valid RGB, 0 < 255", map);
	}
	free_color(strs, line, NULL);
	return (rgb);
}

static int	rgb_to_hex(int *rgb)
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
			print_map_error("Ceiling color defined more than once", map);
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
			print_map_error("Floor color defined more than once", map);
	}
}

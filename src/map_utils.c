/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:47:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/19 17:57:51 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strtrim2(char *s1, char *set)
{
	char	*tmp;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	tmp = ft_strtrim(s1, set);
	if (s1)
		free(s1);
	return (tmp);
}

int	is_empty_line_and_free(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	free(line);
	return (1);
}

int	solo_falta_matrix(t_map *map)
{
	if (ft_arraylen(map->textures) < 4 || map->ceiling < 0 || map->floor < 0)
		return (0);
	return (1);
}

int	ft_ids2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

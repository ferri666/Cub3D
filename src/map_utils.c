/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:47:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/26 13:04:13 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* LIKE STRTRIM, BUT IT FREES THE ORIGINAL STRING*/
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

int	only_matrix(t_map *map)
{
	if (ft_arraylen(map->textures) < 4 || map->ceiling < 0 || map->floor < 0)
		return (0);
	return (1);
}

/* FUNCTION IS DIGIT OR SPACE
Takes an string and returns 1 if all characters in it
are digits or spaces and 0 if they are not*/
int	ft_idos(char *str)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:56:30 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/27 11:38:14 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	*init_cub3d(char *path)
{
	t_cub3d	*cub3d;
	t_map	*mymap;

	mymap = map(path);
	cub3d = ft_calloc(1, sizeof(t_cub3d));
	if (!cub3d)
	{
		print_map_error("Malloc failure", mymap);
	}
	cub3d->map = mymap;
	return (cub3d);
}

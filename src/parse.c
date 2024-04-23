/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:21:16 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/27 11:37:44 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		print_error("The arguments must be 2");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
	{
		print_error("The map must be a .cub file");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("The file could not be opened");
	if (ft_nlines(argv[1]) <= 0)
		print_error("Empty file");
	close(fd);
	return (1);
}

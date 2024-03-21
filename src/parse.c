/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:21:16 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/18 12:36:00 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		print_error("Los argumentos deben ser 2");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
	{
		print_error("el mapa debe ser un archivo .cub");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("No se pudo abrir el archivo");
	if (ft_nlines(argv[1]) <= 0)
		print_error("Archivo vacío");
	close(fd);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:46:42 by vpeinado          #+#    #+#             */
/*   Updated: 2022/10/19 16:46:32 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n--)
	{
		*s++ = 0;
	}
	str = s;
}
/*
int	main(void)
{
	char	str[50];

	strcpy(str, "This is string.h library function");
	puts(str);

	bzero(str, 7);
	puts("esta es la funcion de c");
	puts(str);
	
	puts("Esta es la funcion 42");
	ft_bzero(str, 7);
	puts(str);

	return (0);
}*/

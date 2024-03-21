/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:50:34 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/13 18:32:49 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	char			*string;
	unsigned char	chr;

	if (!str)
		return (NULL);
	string = (char *)str;
	chr = (unsigned char)c;
	while (*string)
	{
		if (*string == chr)
			return (string);
		string++;
	}
	if (*string == chr)
	{
		return (string);
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("Funcion propia: %s\n", ft_strchr("holo", '\0'));
	printf("Funcion original: %s", strchr("holo", '\0'));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:52:14 by vpeinado          #+#    #+#             */
/*   Updated: 2022/12/20 20:19:20 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	ch;

	dst = (unsigned char *)str;
	ch = (unsigned char)c;
	while (n--)
	{
		*dst++ = ch;
	}
	return (str);
}
/*
int	main (void)
{
	char	str[50];

	strcpy(str, "This is string.h library function");
	puts(str);

	memset(str, '$', 7);
	puts(str);

	ft_memset(str, '$', 7);
	puts(str);
	
	return (0);
}*/

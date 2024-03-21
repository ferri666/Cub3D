/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:03:14 by vpeinado          #+#    #+#             */
/*   Updated: 2022/12/22 01:36:28 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	if (!str1 && !str2)
		return (str1);
	dst = (unsigned char *)str1;
	src = (unsigned char *)str2;
	if (dst == src || !n)
		return (dst);
	if (src < dst)
	{
		while (n--)
		{
			*(dst + n) = *(src + n);
		}
		return (str1);
	}
	while (n--)
	{
		*dst++ = *src++;
	}
	return (str1);
}
/*
#include <stdio.h>

int	main(void)
{
	char dest[50] = "aguacate";
	char src[50] = "hello world";
	char destt[50] = "aguacate";
	char srcc[50] = "hello world";

	memmove(destt, srcc, 50);
	ft_memmove(dest, src, 50);

	printf("%s", dest);
	printf("\n----------\n");
	printf("%s", destt);
}*/

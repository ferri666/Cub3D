/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:35:59 by vpeinado          #+#    #+#             */
/*   Updated: 2022/12/21 11:25:45 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*destiny;
	unsigned char	*source;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	destiny = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n--)
	{
		*destiny++ = *source++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:09:37 by vpeinado          #+#    #+#             */
/*   Updated: 2022/12/01 18:30:38 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	index_src;
	size_t	end_dst;

	if ((!dst || !src) && size == 0)
		return (0);
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	end_dst = len_dst;
	index_src = 0;
	if (len_dst < size - 1 && size > 0)
	{
		while (src[index_src] && len_dst + index_src < size -1)
		{
			dst[end_dst] = src[index_src];
			end_dst++;
			index_src++;
		}
		dst[end_dst] = '\0';
	}
	if (len_dst >= size)
		len_dst = size;
	return (len_dst + len_src);
}

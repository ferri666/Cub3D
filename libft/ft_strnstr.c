/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:38:43 by vpeinado          #+#    #+#             */
/*   Updated: 2023/03/23 18:08:19 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	n = ft_strlen(little);
	if (n == 0)
		return ((char *)big);
	while (*big && n <= len)
	{
		if (ft_strncmp(big, little, n) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

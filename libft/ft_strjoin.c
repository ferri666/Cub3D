/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:02:56 by vpeinado          #+#    #+#             */
/*   Updated: 2023/01/11 12:13:36 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index_s1;
	size_t	index_s2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	index_s1 = 0;
	while (s1[index_s1])
	{
		s3[index_s1] = s1[index_s1];
		index_s1++;
	}
	index_s2 = 0;
	while (s2[index_s2])
	{
		s3[index_s1 + index_s2] = s2[index_s2];
		index_s2++;
	}
	s3[index_s1 + index_s2] = '\0';
	return (s3);
}

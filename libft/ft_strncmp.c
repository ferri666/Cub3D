/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:22:05 by vpeinado          #+#    #+#             */
/*   Updated: 2022/10/03 16:20:07 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[50] = "aet";
	char	str2[50] = "aetqert141wertwrtwretrt";
	
	printf("%d\n", strncmp(str1, str2, 5));
	printf("%d\n", ft_strncmp(str1, str2, 5));
	return (0);
}*/

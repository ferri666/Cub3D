/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraypush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:47:21 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/19 18:03:37 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_arraypush(char **strs, char *str)
{
	int		i;
	char	**new_strs;

	i = 0;
	new_strs = malloc(sizeof(char *) * (ft_arraylen(strs) + 2));
	if (!new_strs)
		return (NULL);
	while (strs[i])
	{
		new_strs[i] = strs[i];
		i++;
	}
	new_strs[i] = str;
	new_strs[i + 1] = NULL;
	if (strs)
		free(strs);
	return (new_strs);
}

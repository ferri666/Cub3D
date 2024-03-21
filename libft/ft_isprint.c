/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:55:32 by vpeinado          #+#    #+#             */
/*   Updated: 2022/12/03 17:05:53 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int argument)
{
	if (argument < 32 || argument > 126)
	{
		return (0);
	}
	return (1);
}
/*
int	main(void)
{
	int i = '\n';
	printf("%d\n", ft_isprint(i));
	return (0);
}*/

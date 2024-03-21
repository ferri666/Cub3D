/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:55:36 by vpeinado          #+#    #+#             */
/*   Updated: 2022/09/20 21:03:32 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int argument)
{
	if (argument < '0' || argument > '9')
	{
		return (0);
	}
	return (1);
}
/*
int	main(void)
{
	int i = '3';
	printf("%d\n", ft_isalnum(i));
	return (0);
}*/
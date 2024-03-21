/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:28:38 by vpeinado          #+#    #+#             */
/*   Updated: 2022/09/23 18:18:14 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int argument)
{
	if (argument < 0 || argument > 127)
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

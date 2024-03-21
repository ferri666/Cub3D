/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:13:26 by vpeinado          #+#    #+#             */
/*   Updated: 2022/09/23 19:19:06 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int argument)
{
	if ((argument < 'A' || argument > 'Z')
		&& (argument < 'a' || argument > 'z')
		&& (argument < '0' || argument > '9'))
	{
		return (0);
	}
	return (1);
}
/*
int	main(void)
{
	int i = '9';
	printf("%d\n", ft_isalnum(i));
	return (0);
}*/

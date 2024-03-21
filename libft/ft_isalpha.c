/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:01:13 by vpeinado          #+#    #+#             */
/*   Updated: 2022/09/20 21:22:30 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int argument)
{
	if ((argument < 'A' || argument > 'Z')
		&& (argument < 'a' || argument > 'z'))
	{
		return (0);
	}
	return (1);
}
/*
int	main(void)
{
	int i = 'a';
	printf("%d\n", ft_isalpha(i));
	printf("%d\n", isalpha(i));
	return (0);
}*/

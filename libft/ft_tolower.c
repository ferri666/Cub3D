/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:27:49 by vpeinado          #+#    #+#             */
/*   Updated: 2022/09/17 12:39:46 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch += 32;
		return (ch);
	}
	return (ch);
}
/*
int		main(void)
{
	printf("%i", ft_tolower('b'));
}*/

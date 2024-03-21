/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:00:46 by vpeinado          #+#    #+#             */
/*   Updated: 2022/12/15 21:48:36 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_count_digit(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char	*ft_zero(char *str)
{
	if (str)
	{
		str[0] = 48;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			i;

	nb = n;
	i = ft_count_digit(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		return (ft_zero(str));
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}

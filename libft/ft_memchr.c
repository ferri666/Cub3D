/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:44:54 by vpeinado          #+#    #+#             */
/*   Updated: 2022/10/18 17:51:07 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*ptr == ch)
		{
			return ((void *)ptr);
		}
		ptr++;
	}
	return (NULL);
}
/*
int	main(void)
{ 
   const char	s[50] = "Esta es unra cadena";
 
  puts(memchr( s, 'r', 16 ));

  puts(ft_memchr( s, 'r', 16 ));
 
   return (0);
 
}*/

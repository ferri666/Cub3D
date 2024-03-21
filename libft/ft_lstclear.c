/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:06:27 by vpeinado          #+#    #+#             */
/*   Updated: 2022/12/16 10:48:41 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*slst;
	t_list	*i;

	if (lst != NULL && del != NULL)
	{
		slst = *lst;
		while (slst)
		{
			i = slst->next;
			ft_lstdelone(slst, del);
			slst = i;
		}
		*lst = NULL;
	}
}

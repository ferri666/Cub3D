/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:00:39 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/17 12:00:45 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_del(void (*del)(void *), void	*content)
{
	del(content);
	return (NULL);
}

static t_list	*ft_clear(t_list *save, void (*del)(void *), void	*content)
{
	del(content);
	ft_lstclear(&save, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	new_list = ft_lstnew(content);
	if (!new_list)
		return (ft_del(del, content));
	save = new_list;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		new_list->next = ft_lstnew(content);
		if (!new_list->next)
			return (ft_clear(save, del, content));
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (save);
}

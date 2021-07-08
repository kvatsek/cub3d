/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:36:04 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/12 20:41:49 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *head;
	t_list *tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	new = ft_lstnew((*f)(tmp->content));
	if (!new)
		return (NULL);
	head = new;
	while (tmp->next)
	{
		tmp = tmp->next;
		new->next = ft_lstnew((*f)(tmp->content));
		if (!new)
		{
			ft_lstclear(&head, (*del));
			return (NULL);
		}
		new = new->next;
	}
	return (head);
}

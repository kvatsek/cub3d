/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:59:41 by aantonin          #+#    #+#             */
/*   Updated: 2020/11/12 17:30:41 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *d;

	if (!(*lst) || !del)
		return ;
	if (del != NULL)
	{
		d = *lst;
		while (d)
		{
			tmp = d->next;
			ft_lstdelone(d, (*del));
			d = tmp;
		}
	}
	*lst = NULL;
}

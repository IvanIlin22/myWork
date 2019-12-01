/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_SortedInsert.c		                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2019/11/12 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_SortedInsert(t_list **list, t_list *new)
{
	if (!(*list) || (*list)->data >= new->data)
	{
		new->next = *list;
		*list = new;
	}
	else
	{
		t_list *cur;
		cur = *list;
		while (cur->next && cur->next->data < new->data)
			cur = cur->next;
		new->next = cur->next;
		cur->next = new;
	}
}
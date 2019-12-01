/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_CopyList.c		                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2019/11/12 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_CopyList(t_list	*list)
{
	t_list	*cur;
	t_list	*head;
	t_list	*tail;
	
	cur = list;
	head = NULL;
	while (cur)
	{
		if (!head)
		{
			head = (t_list*)malloc(sizeof(t_list));
			head->data = cur->data;
			head->next = NULL;
			tail = head;
		}
		else
		{
			tail->next = (t_list*)malloc(sizeof(t_list));
			tail = tail->next;
			tail->data = cur->data;
			tail->next = NULL;
		}
		cur = cur->next;
	}
	return (head);
}

t_list		*ft_RecCopyList(t_list *list)
{
	t_list*	cur;
	t_list* new;
	
	cur = list;
	if (!list)
		return (NULL);
	else
	{
		new = (t_list*)malloc(sizeof(t_list));
		new->data = cur->data;
		new->next = ft_RecCopyList(cur->next);
		return (new);
	}
}
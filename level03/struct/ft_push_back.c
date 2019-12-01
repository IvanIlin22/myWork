/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c		                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2019/11/12 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_len(t_list *list)
{
	t_list	*cur;
	int		i;
	
	i = 0;
	cur = list;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

void		ft_push_back(t_list **list, int num)
{
	t_list	*last;
	t_list	*new;
	int		i;
	
	new = (t_list*)malloc(sizeof(t_list));
	new->data = num;
	new->next = NULL;
	last = *list;
	if (last == NULL)
		last = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}	
}

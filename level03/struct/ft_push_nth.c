/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_nth.c		                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2019/11/12 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_push_nth(t_list **list, int index, int num)
{
	t_list	*new;
	t_list	*cur;
	int		i;
	
	i = 0;
	cur = *list;
	new = (t_list*)malloc(sizeof(t_list));
	new->data = num;
	while (i < index - 1)
	{	
		cur = cur->next;
		i++;
	}
	if (index == 0)
	{
		new->next = *list;
		*list = new;
	}
	else
	{
		new->next = cur->next;
		cur->next = new;
	}
}
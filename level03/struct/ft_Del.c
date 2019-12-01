/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Del.c		                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2019/11/12 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_Del(t_list **list, int index)
{
	int		i;
	int		num;
	t_list	*cur;
	t_list	*del;
	
	cur = *list;
	if (index == 0)
	{
		num = cur->data;
		*list = cur->next;
		free(cur);
	}
	else
	{
		i = 0;
		while (i < index - 1)
		{
			cur = cur->next;
			i++;
		}
		del = cur->next;
		num = del->data;
		cur->next = del->next;
		free(del);
	}
	return (num);	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_RemoveDuplicates.c		                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2019/11/12 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_RemoveDuplicates(t_list* list)
{
	t_list	*cur;
	t_list	*nextnext;
	
	cur = list;
	if (!cur)
		return;
	while (cur->next)
	{
		if (cur->data == cur->next->data)
		{
			nextnext = cur->next->next;
			free(cur->next);
			cur->next = nextnext;
		}
		else
			cur = cur->next;		
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Push.c		                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_push(t_list **list, int num)
{
	t_list	*new;
	int		i;
	
	new = (t_list*)malloc(sizeof(t_list));
	new->data = num;
	new->next = *list;
	*list = new;
}

int			main()
{
	int		i;
	
	i = 0;
	t_list *p;
	t_list *list;
	
	list = NULL;
	while (i < 5)
	{
		ft_push(&list, i);
		i++;
	}
	p = list;
	while (p->next)
	{
		printf("%i\t", p->data);
		p = p->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c		                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list)
		return ;
	t_list	*cur;
	
	cur = begin_list;
	while (cur)
	{
		(*f)(cur->data);
		cur = cur->next;
	}
}

void		ft_mult(void *a)
{
	*((int*)a) = *((int*)a) * 3;
}

int			main()
{
	t_list *list;
	t_list *list1;
	int		a = 5;
	int		b = 10;
	
	list = malloc(sizeof(t_list));
	list1 = malloc(sizeof(t_list));
	list->data = &a;
	list->next = list1;
	list1->data = &b;
	list1->next = NULL;
	ft_list_foreach(list, &ft_mult);
	while (list)
	{
		printf("%d\n", *((int*)list->data));
		list = list->next;
	}
	free(list);
	free(list1);
}
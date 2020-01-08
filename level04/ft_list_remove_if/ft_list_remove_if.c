/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c		                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			cmp(void *num1, void *num2)
{
	return *((int*)num1) == *((int*)num2) ? 0 : 1;
}

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cur;
	t_list	*del;
	
	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		del = *begin_list;
		*begin_list = (*begin_list)->next;
		free(del);
	}
	cur = *begin_list;
	while (cur->next)
	{
		if (!cmp(cur->next->data, data_ref))
		{
			del = cur->next;
			cur->next = del->next;
			free(del);
		}
		if (cur->next)
			cur = cur->next;
	}
}

int			main()
{
	t_list *list;
	t_list *list1;
	t_list *list2;
	int		a = 5;
	int		b = 8;
	int		c = 10;
	int		num = 5;
	
	list = malloc(sizeof(t_list));
	list1 = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	list->data = &a;
	list->next = list1;
	list1->data = &b;
	list1->next = list2;
	list2->data = &c;
	list2->next = NULL;
	
	ft_list_remove_if(&list, &num, &cmp);
	while (list)
	{
		printf("%d\n", *((int*)list->data));
		list = list->next;
	}
}
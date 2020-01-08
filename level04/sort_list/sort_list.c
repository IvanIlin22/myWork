/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c		                         		 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		add_list(t_list	**list, int num)
{
	t_list	*new;
	t_list	*cur;
	
	new = (t_list*)malloc(sizeof(t_list));
	new->data = num;
	new->next = NULL;
	cur = *list;
	if (*list == NULL)
		*list = new;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

void		ft_list_print(t_list *list)
{
	t_list*	cur;
	
	cur = list;
	while (cur)
	{
		printf("%i\t", cur->data);
		cur = cur->next;
	}
}

int			cmp(int	a, int b)
{
	return (a >= b);
}

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cur;
	t_list	*p;
	int		swap;
	
	cur = lst;
	p = NULL;
	while (cur->next)
	{
		p = cur->next;
		while (p)
		{
			if (cmp(cur->data, p->data))
			{
				swap = cur->data;
				cur->data = p->data;
				p->data = swap;
			}
			p = p->next;
		}
		cur = cur->next;
	}
	return (lst);
}

void		ft_free(t_list **list)
{
	t_list	*cur;
	
	cur = *list;
	while (cur)
	{
		free(*list);
		cur = cur->next;
	}
	*list = NULL;
}

int			main()
{
	t_list	*list;
	int		i;
	
	list = NULL;
	i = 0;
	while (i < 5)
	{
		add_list(&list, rand() / 10);
		i++;
	}
	ft_list_print(list);
	printf("\nAfter sort\n");
	list = sort_list(list, &cmp);
	ft_list_print(list);
	free(list);
}
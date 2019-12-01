/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*p;
		
	p = begin_list;
	i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

void		ft_push(t_list **list, int num)
{
	t_list	*new;
	int		i;
	
	i = num;
	//printf("%i\t", i);
	new = (t_list*)malloc(sizeof(t_list));
	new->data = &num;
	//printf("%i\n", *((int*) new->data));
	new->next = *list;
	*list = new;
}

int			main()
{
	int		i;
	
	i = 0;
	t_list *list;
	list = NULL;
	while (i < 5)
	{
		ft_push(&list, i);
		i++;
	}
	/*t_list *ptr;
	ptr = list;
	while (ptr)
	{
		printf("%i\n", *((int*)ptr->data));
		ptr = ptr->next;
	}*/
	t_list *p;
	p = list;
	printf("list_size = %i\n", ft_list_size(p));
}

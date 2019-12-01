/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c		                                         :+:      :+:    :+:  */
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

void		ft_push(t_list **list, int num)
{
	t_list	*new;
	int		i;
	
	new = (t_list*)malloc(sizeof(t_list));
	new->data = num;
	new->next = *list;
	*list = new;
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

void		ft_push_nth1(t_list **list, int index, int num)
{
	t_list	*cur;
	int		i;
	
	i = 0;
	cur = *list;
	if (index <= ft_len(cur))
	{
		if (index == 0)
			ft_push(list, num);
		else
		{
			while (i < index - 1)
			{
				cur = cur->next;
				i++;
			}
			ft_push(&(cur->next), num);
		}
	}
	else
		printf("ERROR\n");
}

int			ft_Pop(t_list **list)
{
	int		num;
	t_list	*cur;
	
	cur = *list;
	num = cur->data;
	*list = cur->next;
	free(cur);
	return (num);
}

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

void		ft_SortedInsert(t_list **list, t_list *new)
{
	if (!(*list) || (*list)->data >= new->data)
	{
		new->next = *list;
		*list = new;
	}
	else
	{
		t_list *cur;
		cur = *list;
		while (cur->next && cur->next->data < new->data)
			cur = cur->next;
		new->next = cur->next;
		cur->next = new;
	}
}

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

int			main()
{
	int		i;
	
	i = 0;
	t_list *p;
	t_list *new;
	t_list *list;
	t_list	*head;
	
	new = (t_list*)malloc(sizeof(t_list));
	new->data = 4;
	list = NULL;
	i = 5;
	while (i)
	{
		ft_push(&list, i);
		i--;
	}
	//ft_push_nth1(&list, 6, 5);
	//ft_Pop(&list);
	//ft_Del(&list, 5);
	//ft_SortedInsert(&list, new);
	//ft_RemoveDuplicates(list);
	head = ft_RecCopyList(list);
	//p = list;
	p = head;
	//printf("len = %i\n", ft_len(p));
	while (p)
	{
		printf("%i\t", p->data);
		p = p->next;
	}
}

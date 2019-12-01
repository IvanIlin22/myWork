/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Pop.c		                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2019/11/12 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

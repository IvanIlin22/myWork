/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c		                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int	i;
	int	j;
	int	*mas;
	
	if (start > end)
		i = start - end + 1;
	else
		i = end - start + 1;
	mas = (int*)malloc(sizeof(int) * (i + 1));
	j = 0;
	while (j < i)
	{
		mas[j] = start;
		start += (start > end ) ? -1 : 1;
		j++;
	}
	return (mas);
}
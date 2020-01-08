/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c		                         		 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <stdlib.h>

void				sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				swap;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

void				sort(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				swap;
	
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				swap = tab[j];
				tab[j] = tab[i];
				tab[i] = swap;
			}
			j++;
		}
		i++;
	}
}

int					main()
{
	int				mas[6] = {0, 5, 300, 10, 200, -50};
	int			i;
	
	i = 0;
	printf("Before sort\n");
	while (i < 6)
	{
		printf("%i ", mas[i]);
		i++;
	}
	sort_int_tab(mas, 6);
	i = 0;
	printf("\nAfter sort\n");
	while (i < 6)
	{
		printf("%i ", mas[i]);
		i++;
	}
}
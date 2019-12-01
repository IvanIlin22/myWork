/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c				                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*int		main(int argc, char **argv)
{
	int	i;
	
	i = 1;
	if (argc == 3)
	{
		while (i <= atoi(argv[1]) || i <= atoi(argv[2]))
		{
			if (!(atoi(argv[1]) % i) && !(atoi(argv[2]) % i))
				del = i;
			i++;
		}
		printf("%i", del);
	}
	printf("\n");
}*/

int		main(int argc, char **argv)
{
	int	a;
	int	b;
	int	hcd;
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	if (argc == 3)
	{
		while (1)
		{
			if (!b)
				break;
			a %= b;
			if (!a)
				break;
			b %= a;
			
		}
		hcd = (b) ? b : a;
		printf("%i", hcd);
	}
	printf("\n");
}
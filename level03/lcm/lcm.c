/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c				                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int			i;
	int			hcf;
	int			lcm;
	
	i = 1;
	while (i <= b || i <= a)
	{
		if (!(a % i) && !(b % i))
			hcf = i;
		i++;
	}
	lcm = (a * b) / hcf;
	return (lcm);
	
}

int		main()
{
	printf("%i\n", lcm(36, 9));
}
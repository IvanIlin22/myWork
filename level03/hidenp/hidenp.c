/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c			                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argv, char **argc)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (argv == 3)
		while (argc[1][i])
		{
			while (argc[2][j++])
				if (argc[1][i] == argc[2][j])
					i++;
			if (!argc[1][i])
			{
				write(1, "1\n", 2);
				break;
			}
			else
			{
				write(1, "0\n", 2);
				break;
			}
		}
	else 
		write(1, "\n", 1);
}
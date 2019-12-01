/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                     	 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int	i;
	int	fl;
	
	i = 0;
	fl = 0;
	while (argv[1][i] == ' ' || argv[1][i] == '\t'
	|| argv[1][i] == '\n')
		i++;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t'
			|| argv[1][i] == '\n')
				fl = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'
			|| argv[1][i] == '\n'))
			{
				if (fl)
					write(1, "   ", 3);
				fl = 0;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

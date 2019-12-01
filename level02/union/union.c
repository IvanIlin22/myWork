/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c			                            	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_union(char *str, char c, int len)
{
	int	i;
	
	i = 0;
	while (str[i] && (i < len || len == -1))
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}


int		main(int argc, char **argv)
{
	int	i;
	
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (ft_union(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (ft_union(argv[2], argv[2][i], i) && ft_union(argv[1], argv[2][i], -1))
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}
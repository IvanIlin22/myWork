/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c			                            	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


int		main(int argc, char **argv)
{
	int	i;
	int	j;
	
	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i])
		{
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
					i++;
				j++;
			}
			if (!argv[2][j] && argv[1][i])
				break;
			else if (!argv[1][i])
				ft_putchar(argv[1]);
		}
	}
	write (1, "\n", 1);
}
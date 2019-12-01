/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c									 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if ((argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				&& !(argv[1][i + 1] == ' ' || argv[1][i + 1] == '\t'
				|| argv[1][i + 1] == '\0'))
				ft_putchar(argv[1][i] - 'A' + 'a');
			else if ((argv[1][i] >= 'a' && argv[1][i] <= 'z')
				&& (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\t'
				|| argv[1][i + 1] == '\0'))
				ft_putchar(argv[1][i] - 'a' + 'A');
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
}
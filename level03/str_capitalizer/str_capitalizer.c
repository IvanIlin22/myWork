/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c									 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2019/11/07 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	str_capitalizer(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') && i &&
		!(str[i - 1] == ' ' || str[i - 1] == '\t' ||
		str[i - 1] == '\n' || str[i - 1] == '\v'))
			ft_putchar(str[i] - 'A' + 'a');
		else if ((str[i] >= 'a' && str[i] <= 'z') &&
		(str[i - 1] == ' ' || str[i - 1] == '\t' ||
		str[i - 1] == '\n' || str[i - 1] == '\v'))
			ft_putchar(str[i] - 'a' + 'A');
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = 0;
		while(++i < argc)
		{
			str_capitalizer(argv[i]);
			ft_putchar('\n');
		}			
	}
	else
		ft_putchar('\n');
}
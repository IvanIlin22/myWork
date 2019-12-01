/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_repeat(char *str, char c, int len)
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

void	ft_inter(char *str, char *str1)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (ft_repeat(str, str[i], i) && !ft_repeat(str1, str[i], -1))
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
}

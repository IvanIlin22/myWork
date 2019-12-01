/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print   .c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_stlen(char *str)
{
	int	len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_rev_print(char *str)
{
	int	i;
	
	i = ft_stlen(str) - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_rev_print(argv[1]);
	write(1, "\n", 1);
}
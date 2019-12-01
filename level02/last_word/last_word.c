/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c	                                	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_word(char *str, int *i)
{
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
		(*i) += 1; 
}

void	print_word(char *str, int start, int end)
{
	while (str[start] && str[start] != ' ' && str[start] != '\t')
		write(1, &str[start++], 1);
}

int		main(int argv, char **argc)
{
	int	i;
	int	start;
	int end;
	
	i = 0;
	if (argv == 2)
	{
		while (argc[1][i])
		{
			start = i;
			ft_word(argc[1], &i);
			end = i; 
			while (argc[1][i] && (argc[1][i] == ' ' || argc[1][i] == '\t'))
				i++;
			if (!argc[1][i])
				print_word(argc[1], start, end);
		}
	}
	write(1, "\n", 1);
}

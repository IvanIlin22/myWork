/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c		                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_atoi(char *str)
{
	int	znak;
	int	i;
	int num;
	
	i = 0;
	znak = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
	|| str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		znak = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	return (num * znak);
}

void	ft_mult_prime(int num)
{
	int	i;
	
	i = 2;
	if (num == 1)
		printf("1");
	while (i <= num)
	{
		if (!(num % i))
		{
			printf("%i", i);
			num /= i;
			if (num == 1)
				break;
			printf("*");
			i = 1;
		}	
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_mult_prime(ft_atoi(argv[1]));
	}
	write(1, "\n", 1);
}

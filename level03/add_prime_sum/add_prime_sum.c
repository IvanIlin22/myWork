/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c , 1);
}

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

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		write(1, "2147483648", 10);
	}
	else 
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * (-1);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(nb % 10 + '0');
	}
}

int		ft_prime(int num)
{
	int	i;
	
	i = 2;
	while (i <= num / 2)
	{
		if (!(num % i))//непростое
			return (0);
		i++;
	}
	return (1);//prime
}


int		main(int argc, char **argv)
{
	int	num;
	int	i;
	
	i = 2;
	num = 0;
	if (argc == 2 && ft_atoi(argv[1]) > 0)
	{
		while (i <= ft_atoi(argv[1]))
		{
			if (ft_prime(i))
				num += i;
			i++;
		}
		ft_putnbr(num);
	}
	else
		write(1, "0\n", 1);
}

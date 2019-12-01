/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'a' + base - 10) ||
	(c >= 'A' && c <= 'A' + base - 10));
}

int		ft_atoi_base(const char *str, int base)
{
	int	i;
	int	num;
	int znak;
	
	if (!str[0] || (base < 2 || base > 16))
		return (0);
	znak = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' ||
	str[i] == '\n' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		znak = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_base(str[i], base))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			num = num * base + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'F')
			num = num * base + (str[i] - 'a' + 10);
		else
			num = num * base + str[i] - '0';
		i++;
	}
	return (num * znak);
}

int		main()
{
	char *str = "1111";
	printf("atoi_base = %i\n", ft_atoi_base(str, 2));
}

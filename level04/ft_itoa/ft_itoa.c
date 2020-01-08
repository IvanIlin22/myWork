/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c		                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			ft_count(int num)
{
	int		i;
	
	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int nbr)
{
	int		len;
	char	*mas;
	
	len = ft_count(nbr);
	mas = (char*)malloc(sizeof(char) * (len + 1));
	if (nbr < 0)
	{
		nbr *= -1;
		mas[0] = '-';
	}
	mas[len] = '\0';
	len -= 1;
	if (nbr == 0)
		mas[0] = '0';
	while (nbr)
	{
		mas[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;		
	}
	return (mas);
}

int			main()
{
	char	*mas;
	
	mas = ft_itoa(-525);
	printf("%s\n", mas);
	free (mas);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c		                         			 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_is_word(char *str)
{
	int	i;
	int	fl;
	int	count;
	
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	fl = 1;
	count = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			fl = 1;
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i + 1] == '\0') && fl)
		{
			count++;
			fl = 0;
		}
		i++;
	}
	return (count);
}

int		ft_len(char *str)
{
	int	len;
	int	fl;
	
	
	len = 0;
	while (str[len] && !(str[len] == ' ' || str[len] == '\t' || str[len] == '\n'))
		len++;
	return (len);
}

char 		*ft_copy(char *str, int len)
{
	int		i;
	char	*tmp;
	
	i = 0;
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		**ft_rostring(char *str)
{
	int		i;
	int		k;
	int		fl;
	int		len;
	char	**mas;
	
	mas = (char**)malloc(sizeof(char*) * (ft_is_word(str) + 1));
	k = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	fl = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && !fl)
		{
			len = ft_len(&str[i]);
			fl = 1;
			mas[k] = ft_copy(&str[i], len);
			i = i + len;
			k++;
		}
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			fl = 0;
			i++;
		}
	}
	mas[k] = NULL;
	return (mas);
}

void		ft_free(char **str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		ft_putchar(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int			main(int argc, char **argv)
{
	char	**tmp;
	int		i;
	int		j;
	
	i = 1;
	if (argc == 2)
	{
		tmp = ft_rostring(argv[1]);
		while (tmp[i])
		{
			ft_putchar(tmp[i]);
			write(1, " ", 1);
			i++;
		}
		ft_putchar(tmp[0]);
		ft_free(tmp);
	}
	write(1, "\n", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c		                         			 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int			ft_len(char *str)
{
	int		i;
	
	i = 0;
	while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	return (i);
}

int			ft_count(char *str)
{
	int		i;
	int		len;
	
	i = 0;
	len = 1;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			&& !(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n'))
		len++;
		i++;
	}
	return len;
}

char		*ft_copy(char *str, int len)
{
	int		i;
	char	*new;
	
	i = 0;
	new = (char*)malloc(sizeof(char) * (ft_len(str) + 1));
	while (str[i] && i < len)
	{
		new[i] = str[i];
		i++;
		}
		new[i] = '\0';
		return (new);
}

char		**rev_wstr(char *tmp)
{
	int		i;
	int		j;
	int		len;
	char	**str;
	
	i = 0;
	j = 0;
	str = (char**)malloc(sizeof(char*) * (ft_count(tmp) + 1));
	while (tmp[i])
	{
		if (!(tmp[i] == ' ' || tmp[i] == '\n' || tmp[i] == '\t') || i == 0)
		{
			len = ft_len(&tmp[i]);
			str[j] = ft_copy(&tmp[i], len);
			j++;
			i += len;
		}
		i++;
	}
	return (str);
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

int			main(int argc, char **argv)
{
	char	**new;
	int		i;
	int		j;

	if (argc == 2)
	{
		new = rev_wstr(argv[1]);
		i = ft_count(argv[1]) - 1;
		while (i >= 0)
		{
			j = 0;
			while (new[i][j])
			{
				write(1, &new[i][j], 1);
				j++;
			}
			if (i > 0)
				write(1, " ", 1);
			i--;
		}
		ft_free(new);
	}
	write(1, "\n", 1);
}
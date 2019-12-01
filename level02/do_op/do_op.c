/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == '*')
			printf("%d", atoi(argv[1]) * atoi(argv[3]));
		if (argv[2][0] == '/')
			printf("%i", atoi(argv[1]) / atoi(argv[3]));
		if (argv[2][0] == '+')
			printf("%i", atoi(argv[1]) + atoi(argv[3]));
		if (argv[2][0] == '-')
			printf("%i", atoi(argv[1]) - atoi(argv[3]));
		if (argv[2][0] == '%')
			printf("%i", atoi(argv[1]) % atoi(argv[3]));	
	}
	printf("\n");
}

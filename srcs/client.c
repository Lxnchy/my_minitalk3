/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:53:39 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 23:04:18 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

// static void	charbit(char c, char *avone)
// {
// 	int		bits[9];
// 	int		i;

// 	i = -1;
// 	while (++i < 9)
// 	{
// 		bits[i] = c % 2;
// 		c /= 2;
// 	}
// 	i = -1
// 	while (++i < 9)
// 	{
// 		if (bits[i] == 1)
// 			kill(ft_atoi(avone), SIGUSR1);
// 		else
// 			kill(ft_atoi(avone), SIGUSR2);
// 		usleep(40);
// 	}
// 	return ;
// }

static void	charbit(char c, char *avone)
{
	int		bits[9];
	int		i;

	i = -1;
	while (++i < 9)
	{
		if (c % 2 == 1)
			kill(ft_atoi(avone), SIGUSR1);
		else
			kill(ft_atoi(avone), SIGUSR2);
		usleep(100);
		c /= 2;
	}
	return ;
}

static void	received(int sign)
{
	if (sign == SIGUSR2)
		ft_printf("MESSAGE RECEIVED");
		exit ;
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (ft_printf("2 args only !\n"));
	i = -1;
	while (++i < (int)ft_strlen(av[2]))
		charbit(av[2][i], av[1]);
	while(1)
		;
}

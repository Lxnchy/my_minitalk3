/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:53:39 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/21 17:51:26 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_finished = 0;

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

static void	pingpong(int sign, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)sign;
	usleep(180);
	if (!g_finished)
		kill(siginfo->si_pid, SIGUSR1);
	else
		kill(siginfo->si_pid, SIGUSR2);
}

static void	checkserv()
{
	struct sigaction	sa;

	sa.sa_sigaction = &pingpong;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	usleep(1000);
}

static void	charbit(char tosend, char *serverpid)
{
	int		i;

	i = -1;
	while (++i < 9)
	{
		if (tosend % 2 == 1)
			kill(ft_atoi(serverpid), SIGUSR1);
		else
			kill(ft_atoi(serverpid), SIGUSR2);
		usleep(500);
		tosend /= 2;
	}
}

int	main(int ac, char **av)
{
	int					ts_len;

	ts_len = -1;
	if (ac != 3)
		return (ft_printf("2 args only !\n"));
	kill(ft_atoi(av[1]), SIGUSR1);
	usleep(500);
	while (++ts_len < (int)ft_strlen(av[2]))
	{
		charbit(av[2][ts_len], av[1]);
		checkserv();
	}
	g_finished = 1;
	checkserv();
}

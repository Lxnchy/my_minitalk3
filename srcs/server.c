/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:07 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 23:04:58 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int client_pid = 0;

static void	readbit(int b[9])
{
	int			res;
	int			i;

	kill(client_pid, SIGUSR1);
	usleep(500);
	kill(client_pid, SIGUSR2);
	i = -1;
	res = 0;
	while (++i < 9)
		res = res * 2 + b[i];
	ft_printf("%c", res);
	return ;
}

static void	receive(int sign)
{
	static int	i = -1;
	static int	g_i[9];

	if (++i < 8)
	{
		if (sign == SIGUSR1)
			g_i[8 - i] = 1;
		else
			g_i[8 - i] = 0;
	}
	else
	{
		i = -1;
		readbit(g_i);
	}
}

static void	manage(int sign, siginfo_t *siginfo, void *context)
{
	struct sigaction	sa;

	if (sign == SIGUSR1)
	{
		client_pid = siginfo->si_pid;
		sa.sa_handler = &receive;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	(void)context;
	(void)(sign);
	while (1)
		;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &manage;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	signal(SIGUSR2, SIG_IGN);
	ft_printf("%d\n", getpid());
	while (1)
		;
}

// static void	sigusrone(int sg, siginfo_t *siginfo, void *context)
// {
// 	receive(1);
// 	(void)siginfo;
// 	(void)context;
// 	(void)sg;
// }

// static void	sigusrtwo(int sg)
// {
// 	receive(0);
// 	(void)sg;
// }
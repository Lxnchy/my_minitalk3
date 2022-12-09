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

static void	sendmsg()
{
	kill(client_pid, SIGUSR2);
	//Print msg
	//exit
}

static void	check_end(void)
{
	struct sigaction	sa;
	struct sigaction	sb;

	sa.sa_handler = &sendmsg;
	sb.sa_handler = &check;
	sigaction(SIGUSR1, &sb, NULL);
}

static void	readbit(int b[9])
{
	int			res;
	int			i;

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
		readbit(g_i);
		check_end();
		i = -1;
	}
}

static void	manage(int sign, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
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

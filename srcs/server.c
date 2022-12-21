/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:07 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/21 13:15:13 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	client_pid = 0;

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

	// if (!client_pid)
	// 	client_pid = siginfo->si_pid;
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
		i = -1;
	}
}

// static void	test(int sign)
// {
// 	sign == SIGUSR1 ? ft_printf("B1") : ft_printf("B2");
// }

static void	manage(int sign, siginfo_t *siginfo, void *context)
{
	struct sigaction	sa;
	(void)context;
	(void)sign;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	sa.sa_handler = &receive;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &manage;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("%d\n", getpid());
	while (1)
		;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:07 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/06 22:27:20 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int client_pid = 0;

// static void	readbit(int b[9])
// {
// 	int			res;
// 	int			i;

// 	i = -1;
// 	res = 0;
// 	while (++i < 9)
// 		res = res * 2 + b[i];
// 	ft_printf("%c", res);
// 	return ;
// }

// static void	receive(int sign)
// {
// 	static int	i = -1;
// 	static int	g_i[9];

// 	if (++i < 8)
// 	{
// 		if (sign == 1)
// 			g_i[8 - i] = 1;
// 		else
// 			g_i[8 - i] = 0;
// 	}
// 	else
// 	{
// 		i = -1;
// 		readbit(g_i);
// 	}
// }

static	void	start_handler(int sign, siginfo_t *siginfo, void *context)
{
	client_pid = siginfo->si_pid;
	printf("%d\n", client_pid);
	(void)context;
	(void)(sign);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &start_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
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
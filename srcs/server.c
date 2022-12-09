/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:07 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/09 21:03:00 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// static void	sendmsg()
// {
// 	kill(client_pid, SIGUSR2);
// 	//Print msg
// 	//exit
// }

// static void	check_end(void)
// {
// 	struct sigaction	sa;
// 	struct sigaction	sb;

// 	sa.sa_handler = &sendmsg;
// 	sb.sa_handler = &check;
// 	sigaction(SIGUSR1, &sb, NULL);
// }

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

static void	receive(int sign, siginfo_t *siginfo, void *context)
{
	static int	i = -1;
	static int	g_i[9];

	// ft_printf("\n%d : %d ou %d \n", sign, SIGUSR1, SIGUSR2);
	(void)siginfo;
	(void)context;
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
		// check_end();
		i = -1;
	}
}

static void	manage(int sign, siginfo_t *siginfo, void *context)
{
	struct sigaction	sa2;
	// struct sigaction	sa3;
	int					client_pid;

	client_pid = siginfo->si_pid;
	ft_printf("client pid : %d \n", client_pid);
	sa2.sa_sigaction = &receive;
	// sa3.sa_sigaction = &receive;
	sigaction(SIGUSR1, &sa2, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	// signal(SIGUSR1, &receive);
	// signal(SIGUSR2, &receive);
	(void)sign;
	(void)context;
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

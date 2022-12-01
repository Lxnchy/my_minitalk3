/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:07 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/01 17:03:06 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_i[9];

static void	readbit(int b[9])
{
	int		res;
	int		i;

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

	if (++i < 8)
	{
		if (sign == 1)
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

static void	sigusrone(int sg)
{
	receive(1);
	(void)sg;
}

static void	sigusrtwo(int sg)
{
	receive(0);
	(void)sg;
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	saone;
	struct sigaction	satwo;

	server_pid = getpid();
	saone.sa_handler = &sigusrone;
	satwo.sa_handler = &sigusrtwo;
	sigaction(SIGUSR1, &saone, NULL);
	sigaction(SIGUSR2, &satwo, NULL);
	ft_printf("%d\n", server_pid);
	while (1)
		;
}

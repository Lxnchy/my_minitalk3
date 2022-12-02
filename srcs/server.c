/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:07 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/02 12:36:00 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	readbit(int b[9])
{
	int			res;
	int			i;

	i = -1;
	res = 0;
	while (++i < 9)
		res = res * 2 + b[i];
	ft_printf("%c\n", res);
	return ;
}

static void	receive(int sign)
{
	static int	i = -1;
	static int	g_i[9];

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

static void	sigusrone(int sg, siginfo_t *siginfo, void *context)
{
	receive(1);
	(void)siginfo;
	(void)context;
	(void)sg;
}

static void	sigusrtwo(int sg)
{
	receive(0);
	(void)sg;
}

int	main(void)
{
	struct sigaction	saone;
	struct sigaction	satwo;

	saone.sa_sigaction = &sigusrone;
	saone.sa_flags = SA_SIGINFO;
	satwo.sa_handler = &sigusrtwo;
	sigaction(SIGUSR1, &saone, NULL);
	sigaction(SIGUSR2, &satwo, NULL);
	ft_printf("%d\n", getpid());
	while (1)
		;
}

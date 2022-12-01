/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:00:33 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/01 17:04:04 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>

size_t		ft_strlen(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_printf(const char *av, ...);
int			checkflag(char flag, va_list*args);
int			hexmaster(unsigned long long nb, int size, int isptr);
void		putnbrhex(unsigned long long nb, int *i, int size);
int			ftputnbr(int nb);
int			ftputstr(char *str);
int			ftputchar(char c);
int			uintmaster(unsigned int nb);
void		put_uint(unsigned int nb, int *i);

#endif
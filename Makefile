# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:55:54 by jehubert          #+#    #+#              #
#    Updated: 2022/11/30 18:58:39 by jehubert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERV_NAME = server

CLIENT_NAME = client

HEAD = includes/

SRCS = srcs

OBJS = objs

SERV_SRCS = $(SRCS)/server.c

CLIENT_SRCS = $(SRCS)/client.c

P_SRCS = $(SRCS)/ft_printf.c $(SRCS)/ft_printf_utils.c $(SRCS)/ft_putchar_fd.c \
$(SRCS)/ft_putnbr_fd.c $(SRCS)/ft_putstr_fd.c $(SRCS)/ft_strlen.c

P_OBJS = $(patsubst %,$(OBJS)/%,$(notdir ${P_SRCS:.c=.o}))

SERV_OBJS = $(patsubst %,$(OBJS)/%,$(notdir ${SERV_SRCS:.c=.o}))

CLIENT_OBJS = $(patsubst %,$(OBJS)/%,$(notdir ${CLIENT_SRCS:.c=.o}))

CFLAGS = -Wall -Wextra -Werror

$(OBJS)/%.o : $(SRCS)/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${P_OBJS} ${SERV_OBJS} $(CLIENT_OBJS)
	$(CC) ${CFLAGS} -o $(SERV_NAME) $(SERV_OBJS) $(P_OBJS)
	$(CC) ${CFLAGS} -o $(CLIENT_NAME) $(CLIENT_OBJS) $(P_OBJS)

all: $(NAME) $(SERV_NAME) $(CLIENT_NAME)

clean:
	rm -f $(SERV_OBJS) $(CLIENT_OBJS) $(P_OBJS)

fclean:	clean
	rm -f $(SERV_NAME) $(CLIENT_NAME) 

re: fclean all

.PHONY: all clean fclean re
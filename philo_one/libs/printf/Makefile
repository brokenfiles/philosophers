# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:15:39 by llaurent          #+#    #+#              #
#    Updated: 2019/11/26 13:37:14 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC		= 	libft/ft_atoi.c\
				libft/ft_bzero.c\
				libft/ft_isdigit.c\
				libft/ft_strchr.c\
				libft/ft_strlen.c\
				srcs/ft_handlers.c\
				srcs/ft_handlers_2.c\
				srcs/ft_printf.c\
				srcs/ft_strjoin_c.c\
				srcs/handler_c.c\
				srcs/handler_diu.c\
				srcs/handler_o.c\
				srcs/handler_px.c\
				srcs/handler_s.c\
				srcs/handler_struct.c\
				srcs/handler_utils.c\
				srcs/handler_utils_2.c\
				libft/ft_strdup.c
SRCSH		= includes/printf.h
OBJS		= $(SRCSC:%.c=%.o)
NAME		= libftprintf.a
CC			= gcc
AR			= ar rc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o: ${OBJS}
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@echo "\033[1;32m"
			@echo "┌─┐┬ ┬┌─┐┌─┐┌─┐┌─┐┌─┐"
			@echo "└─┐│ ││  │  ├┤ └─┐└─┐"
			@echo "└─┘└─┘└─┘└─┘└─┘└─┘└─┘"
			@echo "libftprintf.a generated successfully.\033[0;0m"
			@${AR} ${NAME} ${OBJS} ${SRCSH}

all:		${NAME}

clean:
			@echo "Deleting .o files.."
			@${RM} ${OBJS}

fclean:		clean
			@echo "Deleting binary files.."
			@${RM} ${NAME}

re:			fclean all

test-a:		all
			@${CC} ${NAME} ${LIBFT} ../testers/main.c -o printf
			@make clean
			@./printf a

test:		all
			${CC} ${NAME} ${CFLAGS} ${LIBFT} ../testers/main.c -o printf
			@make clean
			@./printf

.PHONY:		all clean fclean re
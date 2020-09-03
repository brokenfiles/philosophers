
NAME		= philo_one
CC			= gcc
RM			= rm -f
OBJS_DIR	= ./objects/
HEADERS		= ./includes/
START		= 1
CFLAGS		= -I${HEADERS} -Wall -Wextra -Werror

SRCSC		=	srcs/philo_one.c\
				srcs/errors/errors.c\
				srcs/execution/execute_thread.c\
				srcs/philosophers/philo_handler.c\
				srcs/parsing/parse_arguments.c\
				srcs/parsing/utils.c

OBJS		= ${SRCSC:%.c=${OBJS_DIR}/%.o}

${OBJS_DIR}/%.o: %.c
			@mkdir -p ${@D}
			@printf "\033[2K\033[0;35mPHILO_ONE\033[0;0m:    \033[0;33mCompilation...    \033[0;31m%-15.15s\033[0;0m\r" $(notdir ${<})
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	header ${OBJS}
			@make -C libs/printf
			@printf "\033[2K\033[0;35mPHILO_ONE\033[0;0m:    \033[0;32mCompleted         \033[0;31m----\033[0;0m          \r"
			@printf "\n\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mPHILO_ONE\033[0;0m:    \033[0;32mReady             \033[0;31m----          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"
			@${CC} ${CFLAGS} ${OBJS} libs/printf/libftprintf.a -o ${NAME}

run:		${NAME}
			@echo "\033[0;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

header:
			@printf "\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mNAME          \033[0;0mSTATUS            \033[0;31mFILE          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

all:		${NAME}

clean:
			@${RM} ${OBJS}
			@printf "\033[0;35mPROJECT\033[0;0m:      \033[0;32mCleaned\033[0;0m\n"

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

silent:
			@:

bonus:		${NAME}

.PHONY:		all clean fclean re bonus rc

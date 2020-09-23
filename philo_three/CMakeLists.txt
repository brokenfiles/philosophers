cmake_minimum_required(VERSION 3.15)
project(philo_three C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(philo_three
        srcs/philo_three.c includes/structures.h srcs/errors/errors.c includes/declarations.h srcs/parsing/parse_arguments.c srcs/parsing/utils.c srcs/philosophers/philo_handler.c srcs/execution/execute_thread.c srcs/messages/alert.c srcs/philosophers/philo_handler_2.c srcs/philosophers/philo_handler_3.c)

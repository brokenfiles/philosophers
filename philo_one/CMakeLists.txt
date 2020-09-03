cmake_minimum_required(VERSION 3.15)
project(philo_one C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(philo_one
        srcs/philo_one.c includes/structures.h srcs/errors/errors.c includes/declarations.h srcs/parsing/parse_arguments.c srcs/parsing/utils.c includes/error_codes.hpp srcs/philosophers/philo_handler.c srcs/execution/execute_thread.c srcs/messages/alert.c srcs/philosophers/philo_handler_2.c)

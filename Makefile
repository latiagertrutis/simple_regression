#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 11:09:41 by mrodrigu          #+#    #+#              #
#    Updated: 2018/10/30 15:05:09 by mrodrigu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

SHELL = /bin/bash

NAME = reg

C_FLAGS = -Wall -Werror -Wextra -lboost_iostreams -lboost_system -lboost_filesystem

CC = g++

FUNCS = main.cpp \
		data_reader.cpp

SRCS_DIR = srcs/

INC_DIR = includes/

OBJ_DIR = objects/

OBJ = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(FUNCS))

INC = $(wildcard $(INC_DIR)*.h)

I := 1

N_SRCS = $(shell ls srcs | wc -l)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(C_FLAGS)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	@echo -n "Compiling [$(shell echo ${I})/${N_SRCS}] => $(@F)"
	@if $(CC) -c -I $(INC_DIR) $< -o $@ $(C_FLAGS) ; then \
		 echo	" ===>[OK]"; \
	 fi
	@$(eval I=$(shell echo $$(($(I)+1))))

clean:
	@echo "***Cleaning Objects***"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "***Cleaning Executables & Libraries***"
	@rm -f $(NAME)

re: fclean
	@make

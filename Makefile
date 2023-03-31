# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2023/03/31 12:57:36 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES

NAME	= minishell
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATHS

SRC_PTH	= srcs/
OBJ_PTH	= objs/
LIB_PTH	= libs/
INC_PTH	= includes/
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES

LIB_SRC	= $(shell find $(LIB_PTH) -mindepth 1 -maxdepth 1 -type d)
SRCS	= $(shell find srcs -type f | tr ' ' '\n' | grep \\.c)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -I$(INC_PTH)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CODES 

NULL			= \e[m
RED				= \e[38;5;9m
YELLOW			= \e[38;5;11m
GREEN			= \e[38;5;2m
BLUE			= \e[38;5;6m
PURPLE			= \e[38;5;5m
PINK			= \e[38;5;13m
WHITE			= \e[38;5;15m

BOLD			= \e[1m
SHADOW			= \e[2m
ITALIC			= \e[3m
UNDLINE			= \e[4m
UPPLINE			= \e[53m
DUNDLINE		= \e[21m
CENSORED		= \e[9m
UPALIGN			= \e[73m
DWALIGN			= \e[74m
FULLER			= \e[7m
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     RULES

all: $(OBJ_PTH) lib_update $(NAME)

lib_update:
	$(foreach libs, $(LIB_SRC), make -C $(libs);)

$(OBJ_PTH):
	mkdir -p $(subst $(SRC_PTH), $(OBJ_PTH), $(shell find $(SRC_PTH) -type d))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

$(NAME):
	echo "src = \"$(SRCS)\""

mclean:
ifneq (,$(shell ls $(OBJ_PTH) 2> /dev/null))
	rm -rf $(OBJ_PTH)
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CLEAN 

clean:	mclean

fclean:	clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	rm -rf $(NAME)
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

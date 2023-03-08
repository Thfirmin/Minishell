# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2023/03/08 00:04:49 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES

NAME	= minishell

LIBFT	= libft/libft.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATHS

SRC_PTH	= srcs/

# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES

MAIN_SRC	= msh_main.c

SRCS	= $(addprefix $(SRC_PTH)main/,$(MAIN_SRC))

OBJS	= $(SRCS:.c=.o)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

CC			= cc
CFLAGS		= -Wall -Wextra -Werror $(DEBUG)
INCLUDE		= -I ./includes -I ./libft
LNKFLAGS	= -L ./libft -lft -lreadline
MAKEFLAGS	+= --no-print-directory
ifneq ($(VERBOSE),1)
MAKEFLAGS	+= --silent
endif

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

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

.PHONY:		all debug mclean clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

all:		update_libft $(NAME)

update_libft:
	make -C libft

$(NAME):	$(OBJS)
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Compiling$(NULL) $(NAME) library"
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(LNKFLAGS) $(OBJS)
	@echo "[$(GREEN)$(BOLD)INFO$(NULL)] $(BOLD)Compiled $(NAME) library$(NULL)"

mclean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) objects"
	rm -rf $(OBJS)
	@echo "[$(BLUE)$(BOLD)INFO$(NULL)] $(BOLD)Deleted $(NAME) objects$(NULL)"
endif

re:			fclean all
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CLEAN 

clean: 		mclean
	make -C libft clean

fclean:		clean
	make -C libft fclean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) library$(NULL)"
	@rm -rf $(NAME)
	@echo "[$(RED)$(BOLD)INFO$(NULL)] $(BOLD)Deleted $(NAME) library$(NULL)"
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2023/03/09 11:51:28 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES

NAME	= minishell

LIBFT	= libft/libft.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATHS

SRC_PTH			= srcs/

LST_PTH	= main/

OBJ_PTH			= objs/

# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES

MAIN_SRC	= msh_main.c

SRCS	= $(addprefix $(SRC_PTH)main/,$(MAIN_SRC))

OBJS	= $(subst $(SRC_PTH),$(OBJ_PTH),$(subst .c,.o,$(SRCS)))

OBJTOSRC	= $(subst $(OBJ_PTH),$(SRC_PTH),$(subst .o,.c,$@))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

CC			= cc
CFLAGS		= -Wall -Wextra -Werror $(DEBUG)
INCLUDE		= -Iincludes -Ilibft
LNKFLAGS	= -Llibft -lft -lreadline
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

.PHONY:		all objdir update_libft mclean clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

all:		objdir $(NAME)

$(LIBFT): update_libft

update_libft:
	make -C libft

$(NAME):	$(LIBFT) $(OBJS)
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Compiling$(NULL) $(NAME) binary"
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LNKFLAGS) -o $(NAME)
	@echo "[$(GREEN)$(BOLD)INFO$(NULL)] $(BOLD)Compiled $(NAME) binary$(NULL)"

objdir:
	mkdir -p $(OBJ_PTH)
	mkdir -p $(addprefix $(OBJ_PTH), $(LST_PTH))

$(OBJS):	$(SRCS)
	@if [ "$(OBJTOSRC)" = "$(findstring $(OBJTOSRC),$?)" ]; then \
		if [ "$(VERBOSE)" = "1" ]; then \
			echo "$(CC) $(CFLAGS) $(INCLUDE) -c $(OBJTOSRC) -o $@"; \
		fi; \
		$(CC) $(CFLAGS) $(INCLUDE) -c $(OBJTOSRC) -o $@; \
	else \
		touch $@; \
	fi
	
mclean:
ifneq (,$(shell ls $(OBJ_PTH) 2> /dev/null))
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) objects"
	rm -rf $(OBJ_PTH)
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
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) binary$(NULL)"
	rm -rf $(NAME)
	@echo "[$(RED)$(BOLD)INFO$(NULL)] $(BOLD)Deleted $(NAME) binary$(NULL)"
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

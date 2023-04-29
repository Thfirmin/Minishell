# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2023/04/29 11:57:13 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES

NAME	= minishell
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATHS

SRC_PTH	= srcs
OBJ_PTH	= objs
LIB_PTH	= libs
INC_PTH	= includes

SRC_TREE	= $(shell echo $(SRCS) | tr ' ' '\n' | sed "s/[^/]*\.c$$//g" | uniq)
OBJ_TREE	= $(subst $(SRC_PTH),$(OBJ_PTH),$(SRC_TREE))
INC_TREE	= $(shell ls -d $(INC_PTH) 2> /dev/null) $(shell find $(LIB_PTH) -type f 2> /dev/null | tr ' ' '\n' | grep \\.h$$ | sed "s/[^/]*\.h$$//g" | uniq)
LIB_TREE	= $(shell ls $(LIB_PTH)/ 2> /dev/null)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES

SRCS	= $(shell find $(SRC_PTH) -type f 2> /dev/null | tr ' ' '\n' | grep \\.c$$)

OBJS	= $(subst $(SRC_PTH),$(OBJ_PTH),$(subst .c,.o,$(SRCS)))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES
CC			= cc

CFLAGS		= -Wall -Wextra -Werror $(DEBUG)
LFLAGS		= $(foreach lib, $(LIB_TREE), -L$(LIB_PTH)/$(lib) -l$(subst lib,,$(lib))) -L ~/.brew/opt/readline/lib -lreadline
IFLAGS		= $(foreach inc, $(INC_TREE), -I$(inc)) $(CPPFLAGS) -I ~/.brew/opt/readline/include
MAKEFLAGS	+= --no-print-directory
ifneq (1,$(LOG))
	MAKEFLAGS += --silent
endif
ifneq (,$(LOG))
	export REDIR = > /dev/null
endif
OTOC		= $(subst $(OBJ_PTH),$(SRC_PTH),$(subst .o,.c,$@))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CODES

NULL		= \e[m
RED			= \e[38;5;9m
YELLOW		= \e[38;5;11m
GREEN		= \e[38;5;2m
BLUE		= \e[38;5;6m
PURPLE		= \e[38;5;5m
PINK		= \e[38;5;13m
WHITE		= \e[38;5;15m

BOLD		= \e[1m
SHADOW		= \e[2m
ITALIC		= \e[3m
UNDLINE		= \e[4m
UPPLINE		= \e[53m
DUNDLINE	= \e[21m
CENSORED	= \e[9m
UPALIGN		= \e[73m
DWALIGN		= \e[74m
FULLER		= \e[7m
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     RULES

all:	$(OBJ_TREE) lib_update $(NAME)

lib_update:
	$(foreach libs, $(LIB_TREE), make -C $(LIB_PTH)/$(libs);)

$(OBJ_TREE):
	mkdir -p $@

re:	fclean all

help:
	printf "| MINISHELL COMPILE HELP |\n";
	printf "| > To compile use 'make'\n";
	printf "| > To compile with debug flags use {DFLAGS} var\n\tex: make re DFLAGS=\"-g -fsanitize=address\"\n";
	printf "| > To compile with otimization flags use {OFLAGS} var\n\tex: make re DFLAGS=\"-g -fsanitize=address\" OFLAGS=-o3\n";
	printf "| > To control verbose mode use {LOG} var\n\tex: make LOG=0\n\tLOG => { null = std | 0 = silent | 1 = full log }\n";
	printf "| * If you'll use a flag repetitively, you can set this flag in Makefile in \"ALIASES\" field\n";
	printf "| * (be careful with the flag name)\n";

.PHONY: all lib_update mclean clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

$(NAME):	$(OBJS)
ifneq (,$(OBJS))
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Compiling${NULL} ${NAME}\n" $(REDIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(OFLAGS) $(OBJS) -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -lreadline $(LFLAGS) -o $(NAME) 
	@printf "[${GREEN}${BOLD}INFO${NULL}] ${BOLD}Compiled ${NAME}${NULL}\n" $(REDIR)
endif

$(OBJS):	$(SRCS)
	@if [ "$(OTOC)" = "$(findstring $(OTOC),$?)" ]; then \
		if [ "$(LOG)" = "1" ]; then \
			printf "$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(OFLAGS) -c $(OTOC) -o $@\n"; \
		fi; \
		$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(OFLAGS) -c $(OTOC) -o $@; \
	else \
		touch $@; \
	fi

mclean:
ifneq (,$(shell ls $(OBJ_PTH) 2> /dev/null))
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Deleting${NULL} ${NAME} objects\n" $(REDIR)
	rm -rf $(OBJ_PTH)
	@printf "[${BLUE}${BOLD}INFO${NULL}] ${BOLD}Deleted ${NAME} objects${NULL}\n" $(REDIR)
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CLEAN

clean:	mclean
	#$(foreach libs, $(LIB_TREE), make -C $(LIB_PTH)/$(libs) clean;)

fclean:	clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	@printf "[${YELLOW}${BOLD}INFO${NULL}] ${UNDLINE}Deleting${NULL} ${NAME} library\n" $(REDIR)
	rm -rf $(NAME)
	@printf "[${RED}${BOLD}INFO${NULL}] ${BOLD}Deleted ${NAME} library${NULL}\n" $(REDIR)
endif
	#$(foreach libs, $(LIB_TREE), make -C $(LIB_PTH)/$(libs) fclean;)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2023/04/14 03:36:43 by thfirmin         ###   ########.fr        #
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
LFLAGS		= $(foreach lib, $(LIB_TREE), -L$(LIB_PTH)/$(lib) -l$(subst lib,,$(lib)))
IFLAGS		= $(foreach inc, $(INC_TREE), -I$(inc))
MAKEFLAGS	+= --no-print-directory
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

iall:	$(OBJ_TREE) lib_update $(NAME)

lib_update:
	$(foreach libs, $(LIB_TREE), make -C $(LIB_PTH)/$(libs);)

$(OBJ_TREE):
	mkdir -p $@

re:	fclean all

.PHONY: all lib_update mclean clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

$(NAME):	$(OBJS)
ifneq (,$(OBJS))
	$(CC) $(CFLAGS) $(DFLAGS) $(OFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
endif

$(OBJS):	$(SRCS)
	@if [ "$(OTOC)" = "$(findstring $(OTOC),$?)" ]; then \
		printf "$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(OFLAGS) -c $(OTOC) -o $@\n"; \
		$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(OFLAGS) -c $(OTOC) -o $@; \
	else \
		touch $@; \
	fi

mclean:
ifneq (,$(shell ls $(OBJ_PTH) 2> /dev/null))
	rm -rf $(OBJ_PTH)
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CLEAN

clean:	mclean
	$(foreach libs, $(LIB_TREE), make -C $(LIB_PTH)/$(libs) clean;)

fclean:	clean
	$(foreach libs, $(LIB_TREE), make -C $(LIB_PTH)/$(libs) fclean;)
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	rm -rf $(NAME)
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2023/04/01 15:55:23 by thfirmin         ###   ########.fr        #
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

SRCS	= $(shell find $(SRC_PTH) -type f | tr ' ' '\n' | grep \\.c)

OBJS	= $(subst $(SRC_PTH),$(OBJ_PTH),$(subst .c,.o,$(SRCS)))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES

CC			= cc

CFLAGS		= -Wall -Wextra -Werror $(DEBUG)
LFLAGS		= $(foreach lib, $(LIB_SRC), -L$(LIB_PTH)$(lib) -l$(subst lib,,$(subst .a,,$(lib))))
IFLAGS		= -I$(INC_PTH)$(foreach header, $(INC_SRC), -I$(header))
MAKEFLAGS	+= --no-print-directory
OTOC		= $(subst $(OBJ_PTH),$(SRC_PTH),$(subst .o,.c,$@))
LIB_SRC		= $(shell ls $(LIB_PTH))
INC_SRC		= $(shell find $(LIB_PTH) -type f | tr ' ' '\n' | grep \\.h$$ | sed "s/[^/]*\.h$$//g" | uniq)
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

all:	$(OBJ_PTH) lib_update $(NAME)

lib_update:
	$(foreach libs, $(LIB_SRC), make -C $(LIB_PTH)$(libs);)

$(OBJ_PTH):
	mkdir -p $(subst $(SRC_PTH), $(OBJ_PTH), $(shell find $(SRC_PTH) -type d))

re:	fclean all

.PHONY: all lib_update mclean clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

$(NAME):	$(OBJS)
	echo "src = \"$(SRCS)\""

$(OBJS):	$(SRCS)
	@if [ "$(OTOC)" = "$(findstring $(OTOC),$?)" ]; then \
		printf "$(CC) $(CFLAGS) $(IFLAGS) -c $(OTOC) -o $@\n"; \
		$(CC) $(CFLAGS) $(IFLAGS) -c $(OTOC) -o $@; \
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

fclean:	clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	rm -rf $(NAME)
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 21:07:07 by thfirmin          #+#    #+#              #
#    Updated: 2023/03/08 00:02:27 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAME 

NAME	= libft.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     PATHS 

PTH_SRCS	= srcs/
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS	= ft

LIBS	= $(addprefix $(PTH_SRCS),$(SRCS))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

MAKEFLAGS	+= --no-print-directory
ifneq ($(VERBOSE),1)
	MAKEFLAGS += --silent
endif
MAKE	= make -C
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CODES 

BLANK			= \e[m
RED				= \e[38;5;9m
YELLOW			= \e[38;5;11m
GREEN			= \e[38;5;2m
BLUE			= \e[38;5;6m
PURPLE			= \e[38;5;5m
PINK			= \e[38;5;13m
WHITE			= \e[38;5;15m

STRONG			= \e[1m
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

all:		$(NAME)

$(NAME):	update_libs

update_libs:
	$(foreach libs,$(LIBS),$(MAKE) $(libs);)

bonus:
	$(foreach libs,$(LIBS),$(MAKE) $(libs) bonus;)

mclean:
	$(foreach libs,$(LIBS),$(MAKE) $(libs) mclean;)

bclean:
	$(foreach libs,$(LIBS),$(MAKE) $(libs) bclean;)

clean:
	$(foreach libs,$(LIBS),$(MAKE) $(libs) clean;)

fclean:
	$(foreach libs,$(LIBS),$(MAKE) $(libs) fclean;)
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	rm -rf $(NAME)
endif

re:			fclean all

bre:		fclean bonus

.PHONY:		all update_libs bonus mclean bclean clean fclean re bre
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

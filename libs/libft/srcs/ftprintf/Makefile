# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2023/03/09 17:56:08 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES 

NAME	= libftprintf.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS	= ft_printf.c \
		  ft_puthex_fd.c \
		  ft_putunbr_fd.c \

OBJS	= $(SRCS:.c=.o)

# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

CC			= cc
CFLAGS		= -Wall -Wextra -Werror $(DEBUG)
INCLUDE		= -I ../../ -I ../../includes
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

.PHONY:		all mclean clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

all:		$(NAME)

$(NAME):	$(OBJS)
	@printf "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Compiling$(NULL) $(NAME) library\n"
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)
	@printf "[$(GREEN)$(BOLD)INFO$(NULL)] $(BOLD)Compiled $(NAME) library$(NULL)\n"
	@printf "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Exporting$(NULL) $(NAME) library\n"
	ar -rcs $(MASTERLIB) $(OBJS)
	ranlib $(MASTERLIB)
	@printf "[$(GREEN)$(BOLD)INFO$(NULL)] $(BOLD)Exported $(NAME) library$(NULL)\n"
	
mclean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	@printf "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) objects\n"
	rm -rf $(OBJS)
	@printf "[$(BLUE)$(BOLD)INFO$(NULL)] $(BOLD)Deleted $(NAME) objects$(NULL)\n"
endif

re:			fclean all
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     BONUS

bonus:	all

bre:	fclean bonus
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CLEAN 

clean: 		mclean

fclean:		clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	@printf "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) library$(NULL)\n"
	rm -rf $(NAME)
	@printf "[$(RED)$(BOLD)INFO$(NULL)] $(BOLD)Deleted $(NAME) library$(NULL)\n"
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:23:56 by thfirmin          #+#    #+#              #
#    Updated: 2023/03/07 20:55:28 by thfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES 

NAME	= libft.a
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    SOURCES 

SRCS	= ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_atoi.c \
		  ft_itoa.c \
		  ft_strlen.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strnstr.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_striteri.c \
		  ft_strmapi.c \
		  ft_memset.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c

BN_SRCS	= ft_lstadd_back_bonus.c \
		  ft_lstadd_front_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstdelone_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstlast_bonus.c \
		  ft_lstmap_bonus.c \
		  ft_lstnew_bonus.c \
		  ft_lstsize_bonus.c \

OBJS	= $(SRCS:.c=.o)

BN_OBJS	= $(subst .c,.o,$(BN_SRCS))
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

CC			= cc
CFLAGS		= -Wall -Wextra -Werror $(DEBUG)
INCLUDE		= -I ./
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

.PHONY:		all bonus mclean bclean clean fclean re bre
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   MANDATORY

all:		$(NAME) mexport_lib

$(NAME):	$(OBJS)
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Compiling$(NULL) $(NAME) library"
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "[$(GREEN)$(BOLD)INFO$(NULL)] $(BOLD)Compiled $(NAME) library$(NULL)"
	
mexport_lib:
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Exporting$(NULL) $(NAME) library"
	ar -rcs ../../libft.a $(OBJS)
	ranlib ../../libft.a
	@echo "[$(GREEN)$(BOLD)INFO$(NULL)] $(BOLD)Exported $(NAME) library$(NULL)"

mclean:
ifneq (,$(shell ls $(OBJS) 2> /dev/null))
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) objects"
	rm -rf $(OBJS)
	@echo "[$(BLUE)$(BOLD)INFO$(NULL)] $(BOLD)Deleted $(NAME) objects$(NULL)"
endif

re:			fclean all
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     BONUS

bonus:	all $(BN_OBJS) bexport_lib

$(BN_OBJS): $(BN_SRCS)
	@if [ "$(BN_OBJSRC)" = "$(findstring $(BN_OBJSRC),$?)" ]; then \
		if [ "$(VERBOSE)" = "1" ]; then \
			echo "$(CC) $(CFLAGS) $(INCLUDE) -c $*.c -o $@"; \
		fi; \
		$(CC) $(CFLAGS) $(INCLUDE) -c $*.c -o $@; \
	else \
		touch $@; \
	fi
	@if [ "$@" = "$(lastword $(BN_OBJS))" ]; then \
		echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Compiling$(NULL) $(NAME) bonus"; \
		if [ "$(VERBOSE)" = "1" ]; then echo "ar -rcs $(NAME) $(BN_OBJS)"; fi; \
		ar -rcs $(NAME) $(BN_OBJS); \
		if [ "$(VERBOSE)" = "1" ]; then echo "ranlib $(NAME)"; fi; \
		ranlib $(NAME); \
		echo "[$(GREEN)$(BOLD)INFO$(NULL)] $(BOLD)Compiled $(NAME) bonus$(NULL)"; \
	fi

bexport_lib:
	@echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Exporting$(NULL) $(NAME) bonus"
	ar -rcs ../../libft.a $(BN_OBJS)
	ranlib ../../libft.a
	@echo "[$(GREEN)$(BOLD)INFO$(NULL)] $(BOLD)Exported $(NAME) bonus$(NULL)"

bclean:
ifneq (,$(shell ls $(BN_OBJS) 2> /dev/null))
	echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) bonus objects"
	$(RM) $(BN_OBJS)
	echo "[$(BLUE)$(BOLD)INFO$(NULL)] $(BOLD)Deleted $(NAME) bonus objects$(NULL)"
endif

bre:	fclean bonus
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     CLEAN 

clean: 		mclean bclean

fclean:		clean
ifneq (,$(shell ls $(NAME) 2> /dev/null))
	echo "[$(YELLOW)$(BOLD)INFO$(NULL)] $(UNDLINE)Deleting$(NULL) $(NAME) library$(NULL)"
	rm -rf $(NAME)
	echo "[$(RED)$(BOLD)INFO$(NULL)] $(BOLD)Deleted $(NAME) library$(NULL)"
endif
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:

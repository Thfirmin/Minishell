/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:05:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/18 11:05:40 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Defines
# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

// Includes
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include <errno.h>

// Enums

// Structs & Unions
typedef struct s_fd
{
	char	*fnm;
	int		ffd;
}			t_fd;

typedef struct s_cmd
{
	t_fd			fdin;
	t_fd			fdout;
	char			**args;
	struct s_cmd	*next;
}					t_cmd;

// Test

// Prompt

// Data

// Utils
int	msh_skipquote(char *str);

// Lexer
int	msh_lexer(char *line);

// Parser
t_cmd	*msh_parser(char *line);
char	**msh_pipe_split(char *line);

#endif

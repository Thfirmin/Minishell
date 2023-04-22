/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:05:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:36:35 by thfirmin         ###   ########.fr       */
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

// Main
int		msh_perror(int ret, char *flag, char *msg, ...);
void	msh_print(t_cmd *cmd);

// Prompt

// Data
t_cmd	*msh_cmdnew(t_fd *in, t_fd *out, char **args);
void	msh_cmdadd_back(t_cmd **cmd, t_cmd *arg);
void	msh_cmdclean(t_cmd **cmd);
void	msh_fdclean(t_fd *fd);
void	msh_splitclean(char ***split);

// Utils
int		msh_skipquote(char *str);

// Lexer
int		msh_lexer(char *line);

// Parser
t_cmd	*msh_parser(char *line);
t_cmd	*msh_mountarg(char *line);
char	*msh_setfile(char *str);
int		msh_heredoc(char *eof);
int		msh_setredir(char *str, t_fd *in, t_fd *out);
void	msh_clean_redir(char *str);
char	**msh_prompt_split(char *line, char set);

#endif

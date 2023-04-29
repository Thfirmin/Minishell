/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:05:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 20:00:09 by thfirmin         ###   ########.fr       */
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
enum e_io
{
	IN = 0,
	OUT = 1
};

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

typedef struct s_shell
{
	char	**argv;
	char	**envp;
	t_cmd	*cmd;
	int		io[2];
	t_list	*pid;
}			t_shell;

extern int	g_rstatus;

// Main
int		msh_perror(int ret, char *context, char *msg, ...);
t_shell	msh_initshell(char **argv, char **envp);

// Data
t_cmd	*msh_cmdnew(t_fd *in, t_fd *out, char **args);
void	msh_cmdadd_back(t_cmd **cmd, t_cmd *arg);
void	msh_cmdclean(t_cmd **cmd);
void	msh_fdclean(t_fd *fd);
void	msh_splitclean(char ***split);
void	*msh_calloc(size_t count, size_t size, char *context);
void	*msh_check_alloc(void *ptr, char *context);
char	*msh_getenvp(char *key, char **envp);
char	*msh_getenv_value(char *key, char **envp);
int		msh_cmdsize(t_cmd *cmd);
void	msh_cleanshell(t_shell *sh);

// Lexer
int		msh_lexer(char *line);

// Parser
void	msh_parser(char *line, t_shell *sh);
t_cmd	*msh_mountarg(char *line, t_shell *sh);
char	**msh_prompt_split(char *line, const char *set);
int		msh_heredoc(char *eof);
int		msh_setredir(char *str, t_fd *io, t_shell *sh);
int		msh_skipquote(char *str);

// Prompt
void	msh_prompt(t_shell *sh);

// Expansion
char	*msh_expansion(char *line, char **argv, char **envp);
char	*msh_expnd_dquote(char **line, char **argv, char **envp);
char	*msh_expnd_env(char **line, char **argv, char **envp);
char	*msh_expnd_squote(char **line);
char	*msh_expnd_txt(char **line, char *eofs);
char	*msh_unify(char *s1, char *s2);
char	*msh_strunify(char *s1, char *s2);
int		msh_isolate(char **src, char **var);

// Executor
void	msh_executor(t_shell *sh);
char	*msh_getpathname(char *cmd, char **envp);
void	msh_system_call(t_cmd *cmd, t_shell *sh);

void	*msh_isbuiltin(char *cmd);
void	msh_fodase1(t_shell *sh, t_cmd *cmd, int *prevpipe, t_list **lst);
void	msh_fodase2(t_shell *sh, t_cmd *cmd, int prevpipe, t_list **lst);

void	test(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:05:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 20:16:08 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Defines
# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

// Includes
# include <stdio.h>
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
# include <fcntl.h>
# include "libft.h"
# include <errno.h>

//Global var.
extern int	g_rstatus;

// Enums
enum e_io
{
	IN = 0,
	OUT = 1
};

// Structs & Unions
typedef struct s_pid
{
	int				pid;
	struct s_pid	*next;
}					t_pid;

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

typedef struct s_env
{
	char	**var_list;
	char	*pwd;
}			t_env;

typedef struct s_shell
{
	char	**argv;
	t_cmd	*cmd;
	t_pid	*pd;
	int		io[2];
	t_env	*env;
}			t_shell;

// Main
int				msh_perror(int ret, char *context, char *msg, ...);
t_shell			msh_initshell(char **argv, char **envp);
void			msh_setsignal(void);

// Data
void			msh_shclean(t_shell *sh);
char			**msh_splitclean(char **split);
t_pid			*msh_pidnew(int pid);
void			msh_pidadd_back(t_pid **pid, t_pid *node);
void			msh_pidclear(t_pid **pid);

t_cmd			*msh_cmdnew(t_fd *in, t_fd *out, char **args);
void			msh_cmdadd_back(t_cmd **cmd, t_cmd *arg);
void			msh_cmdclean(t_cmd **cmd);
void			msh_fdclean(t_fd *fd);
void			*msh_check_alloc(void *ptr, char *context);
char			*msh_getenvp(char *key, char **envp);
char			*msh_getenv_value(char *key, char **envp);

// Lexer
int				msh_lexer(char *line);

// Parser
void			msh_parser(char *line, t_shell *sh);
t_cmd			*msh_mountarg(char *line, t_shell *sh);
char			**msh_prompt_split(char *line, const char *set);
int				msh_heredoc(char *eof);
int				msh_setredir(char *str, t_fd *io, t_shell *sh);
int				msh_skipquote(char *str);

// Prompt
void			msh_prompt(t_shell *sh);

// Expansion
char			*msh_expansion(char *line, char **argv, char **envp);
char			*msh_expnd_dquote(char **line, char **argv, char **envp);
char			*msh_expnd_env(char **line, char **argv, char **envp);
char			*msh_expnd_squote(char **line);
char			*msh_expnd_txt(char **line, char *eofs);
char			*msh_unify(char *s1, char *s2);
char			*msh_strunify(char *s1, char *s2);
int				msh_isolate(char **src, char **var);

// Executor
void			msh_executor(t_shell *sh);
char			*msh_getpathname(char *cmd, char **envp);
int				msh_isbuiltin(char *cmd);
void			msh_builtin_exec(t_shell *sh, t_cmd *cmd);
int				msh_confirmio(t_cmd *cmd);
void			msh_setfd(int fd, t_fd *file, int std);
void			msh_waitpid(t_pid **pid);
void			msh_resetsignal(void);
void			msh_so_specific(int nfd[2], int *rdpe, t_cmd *cmd, t_shell *sh);
void			msh_aux_execve_exec(t_shell *sh, t_cmd *cmd);
void			msh_aux_builtin_exec(t_shell *sh, t_cmd *cmd);

// Env && Arrray Manipulation
int				msh_arr_size(char **arr);
char			**msh_arr_cpy(char **arr, int size);
void			msh_arr_free(char **arr);
int				msh_arr_srch(char **arr, char *str);
char			*msh_find_env(char **env, char *str);
void			msh_init_env(t_env **env, char **envp);
long long int	ft_atolli(const char *str);

// Builtins
void			execute_builtins(char **args, t_env *env, t_shell *sh);
void			msh_echo(char **args);
void			msh_cd(char **args, t_env *env);
void			msh_pwd(char **args, t_env *env);
void			msh_export(char **args, t_env *env);
void			msh_unset(char **args, t_env *env);
void			msh_env(char **args, t_env *env);
void			msh_exit(char **args, t_env *env, t_shell *sh);

#endif

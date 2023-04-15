/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:05:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/15 16:33:10 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Defines

// Includes
# include "libft.h"
# include <readline/readline.h>
# include <errno.h>

// Enums

// Structs & Unions
typedef struct s_cmd
{
	char			**arg;
	int				fdin;
	int				fdout;
	struct s_cmd	*next;
}					t_cmd;

// Test
void	test(void);

// Prompt
t_cmd	*msh_prompt(void);
int		msh_lexer(char *line);
t_cmd	*msh_parser(char *line);

// Data
t_cmd	*msh_cmdnew(char **arg, int fdin, int fdout);
void	msh_cmdadd_back(t_cmd **cmd, t_cmd *arg);

#endif

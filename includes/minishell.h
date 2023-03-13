/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:51:38 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/11 19:01:15 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Includes
# include "libft.h"
# include <readline/readline.h>
# include <stdio.h>
# include <errno.h>

// Structs
typedef struct s_env
{
	char			*key;
	char			*vlue;
	struct s_env	*next;
}					t_env;

// msh_prompt
char	*msh_prompt(char *envp[]);

// msh_env
t_env	*msh_initenv(char *envp[]);

// msh_envutils
t_env	*msh_envnew(char *key, char *vlue);
void	msh_envadd_back(t_env **env, t_env *var);
void	msh_envclear(t_env **env);

// Binutils

#endif

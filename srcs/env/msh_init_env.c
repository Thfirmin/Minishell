/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:53:45 by llima             #+#    #+#             */
/*   Updated: 2023/04/29 15:02:20 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_init_env(t_env **env, char **envp)
{
	char	*pwd;

	(*env) = malloc (sizeof(t_env));
	if (!(*env))
		return ;
	(*env)->var_list = msh_arr_cpy(envp, 0);
	pwd = msh_find_env((*env)->var_list, "PWD");
	if (pwd)
		(*env)->pwd = ft_strdup(pwd + 4);
	else
		(*env)->pwd = getcwd(NULL, 0);
}

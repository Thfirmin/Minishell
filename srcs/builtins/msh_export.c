/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 07:04:29 by llima             #+#    #+#             */
/*   Updated: 2023/04/29 20:01:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//This function will instead check the string and return if it's valid
//Check if it's present in the current env before adding to the total 
//new arguments I'll count how many valid arguments there are and transform 
//my arr_cpy so it can take a number to add to te malloc Then I'll use the 
//function again to check for the argumentsn in a way that they gotta be 
//valid and the arr_srch, if valid, will substitute but if not valid, 
//will create a new spot.
static void	msh_export_var(char *arg, t_env *env)
{
	char	**new_var;
	char	**new_env;
	int		index;

	index = 0;
	new_var = ft_split(arg, '=');
	index = msh_arr_srch(env->var_list, new_var[0]);
	msh_arr_free(new_var);
	if (index != -1)
	{
		free(env->var_list[index]);
		env->var_list[index] = ft_strdup(arg);
	}
	else
	{
		new_env = msh_arr_cpy(env->var_list, 1);
		new_env[msh_arr_size(env->var_list)] = ft_strdup(arg);
		msh_arr_free(env->var_list);
		env->var_list = new_env;
	}
}

static int	msh_check_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) || arg[i] == '_')
	{
		while (ft_isalnum(arg[++i]) || arg[i] == '_')
			;
		if (arg[i] == '=')
			return (0);
		if (arg[i] == '\0')
			return (1);
	}
	ft_printf("export: `%s': not a valid identifier\n", arg);
	g_rstatus = 1;
	return (1);
}

static void	msh_empty_arg(t_env *env)
{
	char	**vars;
	int		i;

	i = 0;
	while (env->var_list[i])
	{
		vars = ft_split(env->var_list[i], '=');
		ft_printf("declare -x %s=\"%s\"\n", vars[0], vars[1]);
		msh_arr_free(vars);
		i++;
	}
}

void	msh_export(char **args, t_env *env)
{
	int	i;

	i = 0;
	g_rstatus = 0;
	if (msh_arr_size(args) == 1)
		msh_empty_arg(env);
	while (args[++i])
	{
		if (!msh_check_arg(args[i]))
			msh_export_var(args[i], env);
	}	
}

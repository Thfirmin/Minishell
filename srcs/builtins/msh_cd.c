/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:35:09 by llima             #+#    #+#             */
/*   Updated: 2023/04/28 20:35:49 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_update_env(char *path, t_env *env)
{
	char	**pwd_update;

	pwd_update = malloc (sizeof(void *) * 3);
	pwd_update[0] = ft_strdup("export");
	pwd_update[2] = NULL;
	if (msh_arr_srch(env->var_list, "OLDPWD") != -1)
	{
		pwd_update[1] = ft_strjoin("OLDPWD=", env->pwd);
		msh_export(pwd_update, env);
	}
	free(env->pwd);
//Gotta test this to check if it actually receives path or getcwd path
	if (!path)
		env->pwd = "memes";
	else
		env->pwd = ft_strdup(path);
//Remove the printf later
	ft_printf("%s\n", env->pwd);
	if (msh_arr_srch(env->var_list, "PWD") != -1)
	{
		pwd_update[1] = ft_strjoin("PWD=", env->pwd);
		msh_export(pwd_update, env);
	}
	msh_arr_free(pwd_update);
}

static void	msh_follow_path(char *path, t_env *env)
{
	if (!path || !ft_strncmp(path, "~", 2))
	{
		if (chdir(msh_find_env(env->var_list, "HOME") + 5))
		{
			ft_printf("cd: HOME not set\n");
			g_rstatus = 1;
			return ;
		}
	}
	else if (!ft_strncmp(path, "-", 2))
	{
		if (chdir(msh_find_env(env->var_list, "OLDPWD") + 7))
		{
			ft_printf("cd: OLDPWD not set\n");
			g_rstatus = 1;
			return ;
		}
	}	
	else if (chdir(path))
	{
		ft_printf("cd: %s: No such file or directory\n", path);
		g_rstatus = 1;
		return ;
	}
}

//static void	msh_follow_path(char *path)
//{
//	msh_case_paths(path, env);
//	if (g_rstatus)
//		return ;
//	else if (chdir(path))
//	{
//		ft_printf("cd: %s: No such file or directory\n", path);
//		g_rstatus = 1;
//		return ;
//	}
//}

void	msh_cd(char **args, t_env *env)
{	
	char	*new_path;

	g_rstatus = 0;
	if (msh_arr_size(args) > 2)
	{
		ft_printf("cd: too many arguments\n");
		g_rstatus = 1;
		return ;
	}	
	msh_follow_path(args[1], env);
	if (!g_rstatus)
	{
		new_path = getcwd(NULL, 0);
// 	Gotta test if pwd gets new_path or path. I'm guessin the first one, since pwd has to display a full path. If it's the second, gotta free new_path.
		if (!new_path)
		{	
			ft_printf("cd: error retrieving current directory: "
				"getcwd: cannot access parent directories: "
				"No such file or directory");
		}
		msh_update_env(new_path, env);
	}

	//[X]Check for number of arguments
	//[X]Check if path is empty
	//[X]	-Check if home is set
	//[X]Check if path is valid
	//[X]In case of successfully changing dir:
	//[X]	-Set OLDPWD to current dir
	//[X]	-Set PWD to new dir.
	//[X]Check possible chdir and getcwd errors?
	//		-Some appear when deleting dirs
	//[]Not a directory error?
	//cd with broken paths updates PWD and OLDPWD
	//(And it also adds the new path you tried to access)
	//cd updates the PWD and OLDPWD envs if they exist, but uses the path given as pwd if it works

	//Use getcwd to check the path beforehand? And then update accordingly
	//I think chdir uses relative path, starting where you are, while getcwd uses absolute path.
	//I think it updates the readline thing for the prompt
}

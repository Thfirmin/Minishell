/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:24:35 by llima             #+#    #+#             */
/*   Updated: 2023/04/29 13:30:14 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_end(t_env *env, t_shell *sh)
{
	msh_shclean(sh);
	msh_arr_free(env->var_list);
	free(env->pwd);
	free(env);
}

static int	msh_is_overflow(char *arg)
{
	char	*lint;
	char	*str;

	str = arg;
	lint = "9223372036854775807";
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			lint = "9223372036854775808";
	while (*str == '0')
		str++;
	if (ft_strlen(str) != ft_strlen(lint))
		return (ft_strlen(str) > ft_strlen(lint));
	while (*str >= *lint)
	{
		str++;
		lint++;
	}
	if (*str == '\0')
		return (0);
	return (1);
}

static int	msh_is_all_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

void	msh_exit(char **args, t_env *env, t_shell *sh)
{
	unsigned char	ret;

	g_rstatus = 0;
	ft_printf("exit\n");
	if (msh_arr_size(args) == 2)
	{
		if (msh_is_all_digit(args[1]) || msh_is_overflow(args[1]))
		{
			ft_printf("exit: %s: numeric argument required\n", args[1]);
			g_rstatus = 2;
		}
		else
		{
			ret = ft_atolli(args[1]);
			g_rstatus = ret;
		}
	}
	else if (msh_arr_size(args) > 2)
	{
		ft_printf("exit: too many arguments\n");
		return ;
	}
//	Add the frees to function here	
	msh_end(env, sh);
	exit(g_rstatus);
}

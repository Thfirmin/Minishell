/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expnd_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:30:49 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/26 11:13:38 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*msh_getbracket(char **line, char **envp);

static char	*msh_getargv(char **line, char **argv);

static char	*msh_gettxt(char **line, char **envp);

static char	*msh_getint(char **line, int i);

char	*msh_expnd_env(char **line, char **argv, char **envp)
{
	char	*ret;

	if (*(*line + 1) == '$')
		ret = msh_getint(line, getpid());
	else if (*(*line + 1) == '?')
		ret = msh_getint(line, 0);
	else if (*(*line + 1) == '{')
		ret = msh_getbracket(line, envp);
	else if (ft_isdigit(*(*line + 1)))
		ret = msh_getargv(line, argv);
	else if (ft_isalpha(*(*line + 1)) || (*(*line + 1) == '_'))
		ret = msh_gettxt(line, envp);
	else
	{
		ret = msh_check_alloc(ft_strdup("$"), "expansion");
		*line += 1;
	}
	return (ret);
}

static char	*msh_getint(char **line, int i)
{
	char	*ret;

	ret = msh_check_alloc(ft_itoa(i), "expansion");
	*line += 2;
	return (ret);
}

static char	*msh_gettxt(char **line, char **envp)
{
	int		i;
	char	*var;
	char	*ret;

	i = 0;
	*line += 1;
	while (ft_isalnum(*(*line + i)) || (*(*line + i) == '_'))
		i ++;
	var = msh_check_alloc(ft_substr(*line, 0, i), "expansion");
	if (!var)
		return (0);
	ret = msh_getenv_value(var, envp);
	*line += i;
	if (!ret)
		ret = ft_calloc(1, 1);
	free (var);
	return (msh_check_alloc(ret, "expansion"));
}

static char	*msh_getargv(char **line, char **argv)
{
	int		i;
	int		end;
	char	*str;
	char	*num;

	*line += 1;
	i = -1;
	num = msh_check_alloc(ft_substr(*line, 0, 1), "expansion");
	if (!num)
		return (0);
	end = ft_atoi(num);
	str = 0;
	while (*(argv + ++i))
	{
		if (i == end)
		{
			str = ft_strdup(*(argv + i));
			break ;
		}
	}
	if (!str)
		str = ft_calloc(1, 1);
	*line += 1;
	free (num);
	return (msh_check_alloc(str, "expansion"));
}

static char	*msh_getbracket(char **line, char **envp)
{
	char	*env;
	char	*tmp;
	int		ret;

	(void) envp;
	ret = msh_isolate(line, &tmp);
	if (!ret)
	{
		free (tmp);
		msh_perror(0, tmp, "bad substitution");
		return (0);
	}
	env = ft_strtrim(tmp, "${}");
	free (tmp);
	tmp = msh_getenv_value(env, envp);
	free (env);
	if (!tmp)
		tmp = ft_calloc(1, 1);
	return (msh_check_alloc(tmp, "expansion"));
}

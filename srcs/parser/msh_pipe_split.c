/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pipe_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:14:47 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 10:38:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_iterpipe(char *line);

static int	msh_pipelen(char *line);

static char	**msh_spliterr(char **ptr);

static char	*msh_getpipe(char *line, char *set, int len);

// Split string into pieces of args split by pipes
// * Put error message
char	**msh_pipe_split(char *line)
{
	char	**str;
	int		pipes;
	int		aux;
	int		i;

	if (!line)
		return (0);
	pipes = msh_iterpipe(line);
	str = ft_calloc(sizeof(char *), pipes + 1);
	if (!str)
	{
		errno = ENOMEM;
		return (0);
	}
	i = -1;
	while (++i < pipes)
	{
		aux = msh_pipelen(line);
		*(str + i) = msh_getpipe(line, " \t\n\r\f\v", aux);
		if (!*(str + i))
			return (msh_spliterr(str));
		line += (aux + 1);
	}
	*(str + i) = (void *) 0;
	return (str);
}

static char	*msh_getpipe(char *line, char *set, int len)
{
	char	*pipe;
	char	*aux;

	aux = ft_substr(line, 0, len);
	pipe = ft_strtrim(aux, set);
	free(aux);
	return (pipe);
}

static char	**msh_spliterr(char **ptr)
{
	int	i;

	if (ptr)
	{
		i = -1;
		while ((*ptr + ++i))
			free (*(ptr + i));
		free (ptr);
	}
	errno = ENOMEM;
	return (0);
}
// Take len of peaced arg
static int	msh_pipelen(char *line)
{
	int		i;

	i = 0;
	while (*(line + i) && (*(line + i) != '|'))
	{
		i += msh_skipquote((line + i));
		i++;
	}
	return (i);
}

// Take count of total peaced args
static int	msh_iterpipe(char *line)
{
	int		i;

	i = 1;
	while (*line)
	{
		if (*line == '|')
			i ++;
		line += msh_skipquote(line);
		line ++;
	}
	return (i);
}

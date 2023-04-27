/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt_split2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:53:11 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/27 15:48:13 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**msh_splterr(char **split);

static char	*msh_subword(char *line, int len);

static int	msh_wordlen(char *line, const char *set);

static int	msh_wordcount(char *line, const char *set);

char	**msh_prompt_split(char *line, const char *set)
{
	int		words;
	int		i;
	int		len;
	char	**split;

	if (!line || !set)
		return (0);
	words = msh_wordcount(line, set);
	split = msh_check_alloc(ft_calloc ((words + 1), sizeof(char *)), "split");
	if (!split)
		return (0);
	i = -1;
	while (++i < words)
	{
		while (ft_strchr(set, *line))
			line ++;
		len = msh_wordlen(line, set);
		*(split + i) = msh_subword(line, len);
		if (!*(split + i))
			return (msh_splterr(split));
		line += len;
	}
	*(split + i) = (void *)0;
	return (split);
}

static int	msh_wordcount(char *line, const char *set)
{
	int	words;
	int	aux;

	words = 0;
	if (!line || !set)
		return (0);
	while (*line)
	{
		if (*line && !ft_strchr(set, *line))
		{
			words ++;
			while (*line && !ft_strchr(set, *line))
			{
				aux = msh_skipquote(line);
				if (aux)
					line += (aux + 1);
				else
					line ++;
			}
		}
		while (*line && ft_strchr(set, *line))
			line ++;
	}
	return (words);
}

static int	msh_wordlen(char *line, const char *set)
{
	int	len;

	if (!line || !set)
		return (0);
	len = 0;
	while (*(line + len) && !ft_strchr(set, *(line + len)))
	{
		len += msh_skipquote(line + len);
		len ++;
	}
	return (len);
}

static char	*msh_subword(char *line, int len)
{
	char	*word;
	char	*tmp;

	if (!line)
		return (0);

	tmp = ft_substr(line, 0, len);
	word = ft_strtrim(tmp, " \t\n\v\f\r");
	free (tmp);
	return (msh_check_alloc(word, "split"));
}

static char	**msh_splterr(char **split)
{
	int	i;

	if (!split)
		return (0);
	i = -1;
	while (*(split + ++i))
		free (*(split + i));
	return (0);
}

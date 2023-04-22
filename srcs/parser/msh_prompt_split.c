/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:55:03 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:31:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**msh_spliterr(char **split);

static char	*msh_getword(char *str, int len);

static int	msh_wordlen(char *str, char set);

static int	msh_wordcount(char *str, char set);

// Split a prompt string based by a set character
char	**msh_prompt_split(char *line, char set)
{
	char	**split;
	int		words;
	int		i;
	int		len;

	if (!line)
		return (0);
	words = msh_wordcount(line, set);
	split = ft_calloc(sizeof(char *), words + 1);
	if (!split)
		return (msh_spliterr(split));
	i = -1;
	while (++i < words)
	{
		while (*line == set)
			line ++;
		len = msh_wordlen(line, set);
		*(split + i) = msh_getword(line, len);
		if (!*(split + i))
			return (msh_spliterr(split));
		line += len;
	}
	*(split + i) = (void *)0;
	return (split);
}

// Take count of words that will be splitted
static int	msh_wordcount(char *str, char set)
{
	int	count;
	int	aux;

	count = 0;
	while (*str)
	{
		if (*str && (*str != set))
		{
			count ++;
			while (*str && (*str != set))
			{
				aux = msh_skipquote(str);
				if (aux)
					str += (aux + 1);
				else
					str ++;
			}
		}
		while (*str && (*str == set))
			str++;
	}
	return (count);
}

// Take len of word to be cropped
static int	msh_wordlen(char *str, char set)
{
	int	len;

	len = 0;
	while (*(str + len) && (*(str + len) != set))
	{
		len += msh_skipquote(str + len);
		len ++;
	}
	return (len);
}

// Take allocated word to string array
static char	*msh_getword(char *str, int len)
{
	char	*word;
	char	*tmp;

	tmp = ft_substr(str, 0, len);
	word = ft_strtrim(tmp, " \t\n\v\f\r");
	free (tmp);
	return (word);
}

// take error demand before returning
static char	**msh_spliterr(char **split)
{
	msh_splitclean(&split);
	errno = ENOMEM;
	return (0);
}

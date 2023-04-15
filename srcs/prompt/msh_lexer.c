/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:44:38 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/15 00:47:48 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Analisar o ridiculo
// cmd  [arg]* [| cmd [arg]]*
// [[ ]>[ ]file]* [[ ]<[ ]file]* [[ ]>>[ ]file]* [[ ]<< eof]*

// "< file cat >file2 | echo oi>> file2"

static short	msh_redirsyntax(char *str, char opt);

static short	msh_pipesyntax(char *str);

int	msh_lexer(char *line)
{
	if (!msh_pipesyntax(line))
		return (0);
	else if (!msh_redirsyntax(line, '<'))
		return (0);
	else if (!msh_redirsyntax(line, '>'))
		return (0);
	return (1);
}

static short	msh_pipesyntax(char *str)
{
	short	arg;

	arg = 0;
	while (*str)
	{
		if (*str == '"' && str++)
		{
			while (*str && (*str != '"'))
				str ++;
			arg = '|';
		}
		if (!arg && (!isspace(*str) && (*str != '|')))
			arg = '|';
		if (*str == '|')
		{
			if (!arg)
				return (0);
			arg -= *str;
		}
		str ++;
	}
	return (arg);
}

static short	msh_redirsyntax(char *str, char opt)
{
	short	redir;

	redir = 0;
	while (*str)
	{
		if (*str == '"' && str ++)
			while (*str && (*str != '"'))
				str ++;
		if (*str == opt)
		{
			while (*(str + redir) == opt)
				redir ++;
			if (redir > 2)
				return (0);
			str += redir;
			while (isspace(*str))
				str ++;
			if (!*str || *str == '|' || *str == '>' || *str == '<')
				return (0);
		}
		redir = 0;
		str ++;
	}
	return (1);
}

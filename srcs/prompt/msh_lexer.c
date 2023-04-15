/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:44:38 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/15 17:24:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_lexerror(char c);

static short	msh_skipquote(char **str);

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
		if (!msh_skipquote(&str))
			return (msh_lexerror(*str));
		if (!arg && (!ft_isspace(*str) && (*str != '|')))
			arg = '|';
		if (*str == '|')
		{
			if (!arg)
				return (msh_lexerror(*str));
			arg -= *str;
		}
		str ++;
	}
	if (!arg)
		return (msh_lexerror(*str));
	return (arg);
}

static short	msh_redirsyntax(char *str, char opt)
{
	short	redir;

	redir = 0;
	while (*str)
	{
		if (!msh_skipquote(&str))
			return (msh_lexerror(*str));
		if (*str == opt)
		{
			while (*(str + redir) == opt)
				redir ++;
			if (redir > 2)
				return (msh_lexerror(*str));
			str += redir;
			while (ft_isspace(*str))
				str ++;
			if (!*str || *str == '|' || *str == '>' || *str == '<')
				return (msh_lexerror(*str));
		}
		redir = 0;
		str ++;
	}
	return (1);
}

static short	msh_skipquote(char **str)
{
	char	opt;

	if ((**str == '\'') || (**str == '\"'))
		opt = **str;
	else
		return (1);
	*str += 1;
	while (**str && (**str != opt))
		*str += 1;
	if (!**str)
		return (0);
	return (1);
}

static int	msh_lexerror(char c)
{
	ft_putstr_fd("-bash: syntax error near unexpected token \'", 2);
	if (!c)
		ft_putstr_fd("newline", 2);
	else
		ft_putchar_fd(c, 2);
	ft_putendl_fd("\'", 2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:53:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/18 15:32:20 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		msh_lexerror(char c);

static short	msh_redirsyntax(char *str, char opt);

static short	msh_pipesyntax(char *str);

// Lexer algorithm: analisys of prompt syntax
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

// Verify syntax of pipe operator (non-portable)
static short	msh_pipesyntax(char *str)
{
	short	arg;

	arg = 0;
	while (*str)
	{
		str += msh_skipquote(str);
		if (!*str)
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

// Verify syntax of redirects operators (non-portable)
static short	msh_redirsyntax(char *str, char opt)
{
	short	redir;

	redir = 0;
	while (*str)
	{
		str += msh_skipquote(str);
		if (!*str)
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

// Display error message (change to unique function)
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

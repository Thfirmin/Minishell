/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:53:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 20:08:42 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		msh_lexerror(char c, int n);

static short	msh_redirsyntax(char *str, char opt);

static short	msh_pipesyntax(char *str);

static short	msh_closedop(char *str);

// Lexer algorithm: analisys of prompt syntax
int	msh_lexer(char *line)
{
	if (!line)
		return (0);
	while (ft_isspace(*line))
		line ++;
	if (!*line)
		return (0);
	if (!msh_closedop(line))
		return (0);
	else if (!msh_pipesyntax(line))
		return (0);
	else if (!msh_redirsyntax(line, '<'))
		return (0);
	else if (!msh_redirsyntax(line, '>'))
		return (0);
	return (1);
}

// Verify syntax os unclosed operators
static short	msh_closedop(char *str)
{
	char	opt;

	while (*str)
	{
		if ((*str == '\'') || (*str == '\"'))
		{
			opt = *str++;
			while (*str && (*str != opt))
				str ++;
			if (!*str)
				return (msh_lexerror(*str, 1));
		}
		str ++;
	}
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
			return (msh_lexerror(*str, 2));
		if (!arg && (!ft_isspace(*str) && (*str != '|')))
			arg = '|';
		if (*str == '|')
		{
			if (!arg)
				return (msh_lexerror(*str, 3));
			arg -= *str;
		}
		str ++;
	}
	if (!arg)
		return (msh_lexerror(*str, 4));
	return (arg);
}

// Verify syntax of redirects operators (non-portable)
static short	msh_redirsyntax(char *str, char opt)
{
	short	redir;

	while (*str)
	{
		redir = 0;
		if ((*str == '\'') || (*str == '\"'))
			str += (msh_skipquote(str) + 1);
		else if (*str == opt)
		{
			while ((*(str + redir) == opt) && (redir < 4))
				redir ++;
			if (redir > 2)
				return (msh_lexerror(*str, 5));
			str += redir;
			while (ft_isspace(*str))
				str ++;
			if (!*str || *str == '|' || *str == '>' || *str == '<')
				return (msh_lexerror(*str, 6));
		}
		str ++;
	}
	return (1);
}

// Display error message (change to unique function)
static int	msh_lexerror(char c, int n)
{
	printf ("aqui %d\n", n);
	if (!c)
		g_rstatus = msh_perror(2, "lexer", \
			"syntax error near unexpected token \'newline\'");
	else
		g_rstatus = msh_perror(2, "lexer", \
			"syntax error near unexpected token \'%c\'", c);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_skipquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:24:02 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:41:13 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Verify if string's a quote (double/single) and return the quote field len
int	msh_skipquote(char *str)
{
	int		len;
	char	opt;

	if (!str)
		return (0);
	len = 0;
	if ((*(str + len) == '\'') || (*(str + len) == '\"'))
	{
		opt = *str;
		len ++;
		while (*(str + len) && (*(str + len) != opt))
			len ++;
	}
	return (len);
}

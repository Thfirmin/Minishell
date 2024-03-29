/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expnd_squote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:05:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 12:48:08 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_expnd_squote(char **line)
{
	char	*str;
	int		i;

	if (*line)
		*line += 1;
	i = 0;
	while (*(*line + i) && (*(*line + i) != '\''))
		i ++;
	if (!*(*line + i))
	{
		msh_perror(0, "expansion", "unterminated single quote");
		return (0);
	}
	str = ft_substr(*line, 0, i);
	if (!str || !*str)
	{
		free (str);
		str = ft_calloc(1, 1);
	}
	*line += (i + 1);
	return (str);
}

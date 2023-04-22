/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:29:13 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 17:37:14 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_setfile(char *str)
{
	char	*file;
	int		i;
	char	opt;

	i = 0;
	while (ft_isspace(*str))
		str ++;
	if ((*(str + i) == '\'') || (*(str + i) == '\"'))
	{
		opt = *(str + i++);
		while (*(str + i) != opt)
			i ++;
	}
	else
		while (*(str + i) && !ft_strchr("<>| \t\n\v\r\f", *(str + i)))
			i ++;
	file = ft_substr(str, 0, i);
	if (!file)
		errno = ENOMEM;
	return (file);
}

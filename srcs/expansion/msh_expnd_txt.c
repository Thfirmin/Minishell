/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expnd_txt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:25:25 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/27 17:14:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_expnd_txt(char **line, char *eofs)
{
	char	*str;
	int		i;

	if (!line)
		return (0);
	i = 0;
	while (*(*line + i) && !ft_strchr(eofs, *(*line + i)))
		i ++;
	str = ft_substr(*line, 0, i);
	*line += i;
	return (str);
}

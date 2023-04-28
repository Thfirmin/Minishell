/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:55:56 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 00:23:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs50.h"

char	*cs_get_line(char *prompt)
{
	char	*str;
	char	*tmp;
	int		i;

	tmp = cs_get_str(prompt);
	if (!tmp)
		return (0);
	str = malloc(cs_strlen(tmp));
	if (!str)
	{
		free (tmp);
		return (0);
	}
	i = -1;
	while (*(tmp + ++i) != '\n')
		*(str + i) = *(tmp + i);
	*(str + i) = '\0';
	free (tmp);
	return (str);
}

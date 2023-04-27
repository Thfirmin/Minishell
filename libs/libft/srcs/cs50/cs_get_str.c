/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:30:25 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/27 10:38:49 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs50.h"

char	*cs_get_str(char *prompt)
{
	char	*str;
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];
	int		blen;

	if (prompt)
		cs_putstr_fd(prompt, 1);
	str = 0;
	blen = 0;
	while (*(buff + (blen - 1)) != '\n')
	{
		blen = read (0, buff, BUFFER_SIZE);
		*(buff + blen) = '\0';
		tmp = cs_strjoin(str, buff);
		if (!tmp)
		free (str);
		if (!tmp)
			return (0);
		str = tmp;
	}
	return (str);
}

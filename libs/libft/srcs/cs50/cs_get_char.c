/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:24:04 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/27 10:27:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs50.h"

char	cs_get_char(char *prompt)
{
	char	c;
	char	jnk;

	c = '\0';
	jnk = '\0';
	if (prompt)
		cs_putstr_fd(prompt, 1);
	read (0, &c, 1);
	if (c)
		while (jnk != '\n')
			read (0, &jnk, 1);
	return (c);
}

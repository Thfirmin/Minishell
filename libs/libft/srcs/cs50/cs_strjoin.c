/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:34:56 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/27 10:38:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs50.h"

char	*cs_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		len;

	ret = malloc(cs_strlen(s1) + cs_strlen(s2) + 1);
	if (!ret)
		return (0);
	len = 0;
	if (s1)
		while (*s1)
			*(ret + len++) = *s1++;
	if (s2)
		while (*s2)
			*(ret + len++) = *s2++;
	*(ret + len) = '\0';
	return (ret);
}

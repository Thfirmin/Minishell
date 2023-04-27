/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:27:14 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/27 11:20:52 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cs50.h"

int	cs_putstr_fd(char *str, int fd)
{
	int	len;

	len = 0;
	if (str)
	{
		while (*(str + len))
			len ++;
		write (fd, str, len);
	}
	return (len);
}

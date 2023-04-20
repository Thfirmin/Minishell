/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:19:36 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 10:53:23 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_perror(char *flag, char *msg, ...)
{
	va_list	ap;

	ft_putstr_fd("bash:", 2);
	ft_putstr_fd(flag, 2);
	if (errno)
		perror(flag);
	else if (msg)
	{
		ft_putchar_fd(':', 2);
		va_start(ap, msg);
		while (*msg)
		{
			if (*msg == '%' && msg++)
			{
				if ((*(msg + 1) == 's') && msg++)
					ft_putstr_fd (va_arg(ap, char *), 2);
				else if ((*(msg + 1) == '%') && msg++)
					ft_putchar_fd ('%', 2);
			}
			else
				ft_putchar_fd (*msg++, 2);
		}
		va_end(ap);
	}
	return (0);
}

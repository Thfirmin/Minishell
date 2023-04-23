/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:19:36 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/23 11:33:46 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_initmsg(char *sh, char *context, char *msg);

int	msh_perror(int ret, char *context, char *msg, ...)
{
	va_list	ap;

	msh_initmsg("bash", context, msg);
	if (msg)
	{
		va_start(ap, msg);
		while (*msg)
		{
			if (*msg == '%')
			{
				if (*(msg + 1) == 's')
					ft_putstr_fd(va_arg(ap, char *), 2);
				else
					ft_putchar_fd(*(msg + 1), 2);
				msg += 2;
			}
			else
				ft_putchar_fd (*msg++, 2);
		}
		ft_putchar_fd('\n', 2);
		va_end(ap);
	}
	else
		perror (context);
	return (ret);
}

static void	msh_initmsg(char *sh, char *context, char *msg)
{
	if (!sh)
		return ;
	ft_putstr_fd(sh, 2);
	if (context && *context)
	{
		ft_putchar_fd(':', 1);
		if (msg)
			ft_putstr_fd(context, 1);
	}
	if (msg && *msg)
		ft_putchar_fd(':', 1);
}

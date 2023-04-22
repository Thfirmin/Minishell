/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:19:36 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:39:45 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_initmsg(char *sh, char *prog, char *msg);

int	msh_perror(int ret, char *flag, char *msg, ...)
{
	va_list	ap;

	msh_initmsg("bash", flag, msg);
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
		perror (flag);
	return (ret);
}

static void	msh_initmsg(char *sh, char *prog, char *msg)
{
	if (!sh)
		return ;
	ft_putstr_fd(sh, 2);
	if (prog && msg)
	{
		ft_putchar_fd(':', 2);
		ft_putstr_fd(prog, 2);
	}
	ft_putchar_fd(':', 2);
}

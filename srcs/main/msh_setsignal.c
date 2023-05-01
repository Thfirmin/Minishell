/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setsignal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 07:44:17 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 19:08:21 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_error_handler(int sig);

void	msh_setsignal(void)
{
	signal (SIGQUIT, SIG_IGN);
	signal (SIGINT, msh_error_handler);
}

static void	msh_error_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_rstatus = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

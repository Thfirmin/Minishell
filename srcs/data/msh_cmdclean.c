/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmdclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:48 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 10:52:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_cmdclean(t_cmd **cmd)
{
	t_cmd	*nxt;
	int		aux;

	if (!cmd)
		return ;
	while (*cmd)
	{
		aux = -1;
		nxt = (**cmd).next;
		free ((**cmd).fdin.fnm);
		free ((**cmd).fdout.fnm);
		if (((**cmd).fdin.ffd != -2) && ((**cmd).fdin.ffd != -2))
			close ((**cmd).fdin.ffd);
		if (((**cmd).fdout.ffd != -2) && ((**cmd).fdout.ffd != -2))
			close ((**cmd).fdout.ffd);
		if ((**cmd).args)
		{
			while (*((**cmd).args + ++aux))
				free (*((**cmd).args + aux));
			free ((**cmd).args + aux);
			(**cmd).args = 0;
		}
		free (*cmd);
		*cmd = nxt;
	}
}

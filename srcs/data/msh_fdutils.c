/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_fdutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:48 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 00:28:46 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_fdclean(t_fd *fd)
{
	if (!fd)
		return ;
	if ((fd->ffd != -1) && (fd->ffd != -2))
	{
		close(fd->ffd);
		fd->ffd = -2;
	}
	if (fd->fnm)
	{
		free (fd->fnm);
		fd->fnm = 0;
	}
}

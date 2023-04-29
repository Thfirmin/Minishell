/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shellutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:00:43 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 07:35:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_shclean(t_shell *sh)
{
	/* free in envp */
	close(sh->io[IN]);
	close(sh->io[OUT]);
	msh_cmdclean(&sh->cmd);
}

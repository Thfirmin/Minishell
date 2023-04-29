/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_shellutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:00:43 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 20:03:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_shclean(t_shell *sh)
{
	close(sh->io[IN]);
	close(sh->io[OUT]);
	msh_cmdclean(&sh->cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmdadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:08:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 10:11:29 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_cmdadd_back(t_cmd **cmd, t_cmd *arg)
{
	t_cmd	*lst;

	if (!*cmd)
		*cmd = arg;
	else
	{
		lst = *cmd;
		while (lst->next)
			lst = lst->next;
		lst->next = arg;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmdadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:31:07 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/15 16:32:57 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_cmdadd_back(t_cmd **cmd, t_cmd *arg)
{
	t_cmd	*lst;

	lst = *cmd;
	if (lst)
		while (lst->next)
			lst = lst->next;
	if (!lst)
		*cmd = arg;
	else
		lst->next = arg;
}

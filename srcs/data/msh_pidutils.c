/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pidutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:44:32 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 20:02:35 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pid	*msh_pidnew(int pid)
{
	t_pid	*node;

	node = ft_calloc(sizeof(t_pid), 1);
	if (node)
	{
		node->pid = pid;
		node->next = (void *)0;
	}
	return (msh_check_alloc(node, "pidnew"));
}

void	msh_pidadd_back(t_pid **pid, t_pid *node)
{
	t_pid	*lst;

	lst = *pid;
	if (lst)
		while (lst->next)
			lst = lst->next;
	if (!lst)
		*pid = node;
	else
		lst->next = node;
}

void	msh_pidclear(t_pid **pid)
{
	t_pid	*nxt;

	if (!pid)
		return ;
	while (*pid)
	{
		nxt = (**pid).next;
		free (*pid);
		*pid = nxt;
	}
}

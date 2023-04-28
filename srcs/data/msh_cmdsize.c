/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmdsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:51:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 12:04:47 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_cmdsize(t_cmd *cmd)
{
	int		len;

	len = 0;
	while (cmd)
	{
		len ++;
		cmd = cmd->next;
	}
	return (len);
}

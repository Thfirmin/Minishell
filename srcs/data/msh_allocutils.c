/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_allocutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:30:20 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 00:31:16 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*msh_check_alloc(void *ptr, char *context)
{
	if (!ptr)
	{
		errno = ENOMEM;
		msh_perror(0, context, 0);
	}
	return (ptr);
}

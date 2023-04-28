/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_check_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:31:38 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/26 11:58:50 by thfirmin         ###   ########.fr       */
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

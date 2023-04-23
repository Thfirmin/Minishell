/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:19:17 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/23 11:22:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*msh_calloc(size_t count, size_t size, char *context)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		errno = ENOMEM;
		msh_perror(0, context, 0);
	}
	return (ptr);
}

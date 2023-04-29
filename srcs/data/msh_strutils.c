/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:24:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 00:25:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**msh_splitclean(char **split)
{
	int	i;

	if (!split)
		return (0);
	i = -1;
	while (*(split + ++i))
		free (*(split + i));
	free (split);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:45:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/09 18:53:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_prompt(char *envp[])
{
	int	i;

	i = 0;
	while (*(envp + i) && ft_strncmp(*(envp + i), "PS1=", 4))
	{
		printf ("%s\n", *(envp + i));
		i ++;
	}
	//if (!*(envp + i))
	//	errno = ENOATTR;
	return (*(envp + i));
}

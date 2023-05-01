/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_find_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:09:26 by llima             #+#    #+#             */
/*   Updated: 2023/04/28 20:45:53 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_find_env(char **env, char *str)
{
	int	i;
	int	srch_len;

	i = 0;
	srch_len = ft_strlen(str);
	if (env && str)
	{
		while (env[i])
		{
			if (!ft_strncmp(env[i], str, srch_len))
			{
				if (str[srch_len - 1] == '=' || env[i][srch_len] == '=')
					return (env[i]);
			}
			i++;
		}
	}
	return (NULL);
}

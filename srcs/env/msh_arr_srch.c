/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_arr_srch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:09:26 by llima             #+#    #+#             */
/*   Updated: 2023/04/24 10:12:17 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_arr_srch(char **arr, char *str)
{
	int	i;
	int	srch_len;

	i = 0;
	srch_len = ft_strlen(str);
	if (arr && str)
	{
		while (arr[i])
		{
			if (!ft_strncmp(arr[i], str, srch_len))
			{
				if (arr[i][srch_len] == '=')
					return (i);
			}
			i++;
		}
	}
	return (-1);
}

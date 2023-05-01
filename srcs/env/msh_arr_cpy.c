/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_arr_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:44:59 by llima             #+#    #+#             */
/*   Updated: 2023/04/26 22:03:57 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**msh_arr_cpy(char **arr, int size)
{
	int		arr_size;
	int		i;
	char	**arr_cpy;

	i = 0;
	arr_size = msh_arr_size(arr);
	if (arr_size)
	{
		arr_cpy = malloc(sizeof(void *) * (arr_size + 1 + size));
		if (!arr_cpy)
			return (NULL);
		while (arr[i])
		{
			arr_cpy[i] = ft_strdup(arr[i]);
			i++;
		}
		arr_cpy[i + size] = NULL;
		return (arr_cpy);
	}
	return (NULL);
}

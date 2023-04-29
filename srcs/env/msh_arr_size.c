/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_arr_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:50:05 by llima             #+#    #+#             */
/*   Updated: 2023/04/24 08:14:51 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_arr_size(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:41:40 by llima             #+#    #+#             */
/*   Updated: 2023/04/25 15:34:19 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_echo(char **args)
{
	int	i;
	int	k;
	int	n;

	i = 0;
	n = 0;
	while (args[++i] && args[i][0] == '-')
	{
		k = 0;
		while (args[i][++k] == 'n')
			;
		if (args[i][k] == '\0')
			n++;
		else
			break ;
	}
	while (args[i])
	{
		ft_printf("%s", args[i]);
		if (args[++i])
			ft_printf(" ");
	}
	if (!n)
		ft_putchar_fd('\n', 1);
	g_rstatus = 0;
}

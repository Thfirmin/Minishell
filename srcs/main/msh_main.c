/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:53:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/09 18:53:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*prompt;
	
	(void) argc;
	(void) argv;
	prompt = msh_prompt(envp);
	(void) prompt;
	//printf ("prompt = %s\n", prompt);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:53:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/10 02:35:54 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	
	(void) argc;
	(void) argv;
	(void) env;
	env = msh_initenv(envp);
	//printf ("prompt = %s\n", prompt);
	msh_envclear(&env);
	return (0);
}

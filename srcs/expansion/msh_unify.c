/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 07:25:15 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/26 11:59:29 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_unify(char *s1, char *s2)
{
	if (!s2)
	{
		free (s1);
		return (0);
	}
	s1 = msh_strunify(s1, s2);
	return (s1);
}

char	*msh_strunify(char *s1, char *s2)
{
	char	*tmp;

	tmp = msh_check_alloc(ft_strjoin(s1, s2), "expansion");
	free (s1);
	free (s2);
	return (tmp);
}

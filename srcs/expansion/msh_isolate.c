/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_isolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:41:11 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/26 11:58:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_isolate(char **src, char **var)
{
	int		i;
	int		ret;

	i = 2;
	ret = 1;
	while (*(*src + i) && (*(*src + i) != '}'))
	{
		if (!ft_isalnum(*(*src + i)) && (*(*src + i) != '_'))
			ret = 0;
		i ++;
	}
	if (!*(*src + i))
		ret = 0;
	*var = msh_check_alloc(ft_substr(*src, 0, (i + 1)), "expansion");
	*src += i;
	if (**src)
		*src += 1;
	return (ret);
}

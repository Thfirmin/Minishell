/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_clean_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:12:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 09:52:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_clean_redir(char *str)
{
	int	i;

	while (*str)
	{
		i = 0;
		str += msh_skipquote(str);
		if ((*str == '<') || (*str == '>'))
		{
			while ((*(str + i) == '<') || (*(str + i) == '>'))
				i ++;
			while (ft_isspace(*(str + i)))
				i ++;
			while (*(str + i) && !ft_strchr("<>| \t\n\v\r\f", *(str + i)))
				i ++;
			ft_memset(str, ' ', i);
			str += i;
		}
		else if (*str >= 9 && *str <= 13)
			*str++ = ' ';
		else if (*str)
			str ++;
	}
}

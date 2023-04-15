/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:05:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/14 23:45:20 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Defines

// Includes
# include "libft.h"
# include <readline/readline.h>
# include <ctype.h>

// Enums

// Structs & Unions
typedef struct s_cmd
{
	char			**cmd;
	int				fdin;
	int				fdout;
	struct s_cmd	*next;
}					t_cmd;

// Test
void	test(void);

// Prompt
t_cmd	*msh_prompt(void);
int		msh_lexer(char *line);
t_cmd	*msh_parser(char *line);

#endif

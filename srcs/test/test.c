#include "minishell.h"

// Only for unit test
void	test(void)
{
	char	*line = "| mundo";

	ft_printf ("line = %s\nret = %d\n", line, msh_lexer(line)); // jogar pra main em loop
}

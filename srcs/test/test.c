#include "minishell.h"

// Only for unit test
void	test(void)
{
	char	*line = ">> > echo | echo oi>> file2";

	ft_printf ("line = %s\nret = %d\n", line, msh_lexer(line)); // jogar pra main em loop
}

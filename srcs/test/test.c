#include "minishell.h"

// Only for unit test
//static void	debug_cmd(t_cmd *cmd);

// >[>] arg (>, <, |, (null))

void	test(void)
{
	//t_cmd	*cmd;
	char	*line = "ola | echo ola > ";

	ft_printf ("line: %s\nret: %d\n", line, msh_lexer(line));
	//if (!msh_lexer(line))
	//	return ;
	/*cmd = msh_parser(line);
	ft_printf ("cmd: %p\n", cmd);
	if (cmd)
		debug_cmd(cmd);
	free (cmd);*/
}

/*
static void	debug_cmd(t_cmd *cmd)
{
	int	node;
	int	i;

	node = 0;
	while (cmd)
	{
		ft_printf ("node[%d]:\n{\n\t", node++);
		i = 0;
		if (!cmd->arg)
			ft_printf("(null)");
		else
			while (*(cmd->arg + i))
				ft_printf ("\"%s\" ", *(cmd->arg + i++));
		ft_printf ("\n\tfdin: %d\n\tfdout: %d\n}\n", cmd->fdin, cmd->fdout);
		cmd = cmd->next;
	}
}
*/

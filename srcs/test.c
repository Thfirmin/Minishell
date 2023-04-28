#include "minishell.h"

void	test(void)
{
	char	*bin;
	char	*tmp;
	int		ret;

	tmp = cs_get_line("file: ");
	bin = ft_strtrim(tmp, " \t\n\v\f\r");
	free (tmp);
	ret = 0;
	if (bin)
	{
		if ((*bin == '.') || (*bin == '/'))
			ret = access(bin, X_OK);
		else
			printf ("builtin or relative path\n");
		if (ret)
			perror(bin);
	}
	free (bin);
	exit(0);
}


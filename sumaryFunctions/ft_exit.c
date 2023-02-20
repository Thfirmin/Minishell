#include <stdlib.h>
#include <stdio.h>

/*
 * exit
 * Exit the program. you can use constant EXIT_FAILURE  or EXIT_SUCCESS to say 
 * if program is success or failure exited
 *
 * Header: stdlib.h
 * Prototype: void	exit(int status);
 *
 * status -> status of program that exited
 *
 * Return: Non-return function
 */

void	ft_success(void);

void	ft_failure(void);

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		while (1)
			ft_failure();
	}
	else
	{
		while (1)
			ft_success();

	}
	return (0);
}

void	ft_failure(void)
{
	printf ("Failure exit (confirm it in bash using 'echo $?' command)\n");
	exit(EXIT_FAILURE);
}

void	ft_success(void)
{
	printf ("Success exit (confirm it in bash using 'echo $?' command)\n");
	exit(EXIT_SUCCESS);
}

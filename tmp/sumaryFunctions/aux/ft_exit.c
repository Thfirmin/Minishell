#include <stdlib.h>

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

void	ft_exit(int ext)
{
	exit(ext);
}

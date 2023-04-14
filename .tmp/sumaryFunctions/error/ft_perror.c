#include <stdio.h>
#include <errno.h>

/* 
 * perror 
 * Print a system error message
 *
 * Header: stdio.h & errno.h
 * Prototype: void	perror(const char *s);
 *
 * s -> Error message that will outputted in STDERR
 *
 * Return: Non-returning function
 */

void	ft_perror(const char *s)
{
	perror(s);
}


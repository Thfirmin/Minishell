#include <unistd.h>

/*
 * access
 * check user's permission from a file
 *
 * Header: unistd.h
 * Prototype: int	access(const char *pathname, int mode);
 *
 * pathname -> is the path of file who you want to check
 * mode -> is the flags XORed '|' with the permissions you want to check. (F_OK | X_OK | R_OK | W_OK)
 *
 * Return: zero (0) in sucess, -1 in error and errno will be setted
 */

int	ft_access(const char *pathname, int mode)
{
	return (acces(pathname, mode));
}

#include <fcntl.h>

/* 
 * open 
 * open and possibly create a file
 *
 * Header: fcntl.h
 * Prototype: int	open(const char *pathname, int flags, mode_t mode)
 *
 * pathname -> path of file to open/create
 * flags -> flags to open/create a file with a status
 * mode -> *(optional) (mode_t == int): file permission to be setted
 *
 * Return: the fd of opened file or -1 in error and errno will be setted
 */

int	ft_open(char *pathname, int flags, mode_t mode)
{
	if (!mode)
		return (open(pathname, flags));
	return (open(pathname, flags, mode));
}


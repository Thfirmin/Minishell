#include <unistd.h>

/*
 * close
 * close a file descriptor and delete your reference to the file
 *
 * Header: unistd.h
 * Prototype: int	close(int fd);
 *
 * fd -> The file descriptor that will be closed
 *
 * Return: zero (0) in sucess, -1 in error and errno will be setted
 */

int	ft_close(int fd)
{
	return (close(fd));
}

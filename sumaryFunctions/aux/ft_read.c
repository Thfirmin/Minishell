#include <unistd.h>

/* 
 * read 
 * Reads from a file
 *
 * Header: unistd.h
 * Prototype: ssize_t	read(int fd, void *buf, size_t count);
 *
 * fd -> File descriptor to read
 * buf -> block of address that will take the read
 * count -> buffer to read
 *
 * Return: Return readed bytes
 */

ssize_t	ft_read(int fd, void *buf, size_t count)
{
	return (read(fd, buf, count));
}


#include <unistd.h>

/*
 * write
 * Write a buffer in file descriptor
 *
 * Header: unistd.h
 * Prototype: ssize_t	write(int fd, const void *buf, size_t count);
 *
 * fd -> file descriptor that write will.... write
 * buf -> string address that write will use as source
 * count -> bytes of buffer that will be writed
 *
 * Return: write return the number of byte that he writed, in case of error write return -1
 */

ssize_t	ft_write(int fd, const void *buf, size_t count)
{
	return (write(fd, buf, count));
}

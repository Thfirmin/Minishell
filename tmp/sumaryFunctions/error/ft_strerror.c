#include <string.h>

/* 
 * strerror 
 * Return a string describing error number 
 *
 * Header: string.h
 * Prototype: char	*strerror(int errnum);
 *
 * errnum -> errno number in 'errno.h' header that countain a error describe
 *
 * Return: Return the appropiate error description string,
 * or an "Unknown error nnn" message if the error number is unknown.
 */

char	*ft_strerror(int errnum)
{
	return (strerror(errnum));
}


#include <stdio.h>

/* 
 * printf 
 * formatted output conversion
 *
 * Header: stdio.h
 * Prototype: int	printf(const char *restrict format, ...);
 *
 * format -> string with placeholders to be outputted
 * ... -> data to be converted and replaced in format
 *
 * Return: Retturn the number of characters printed
 */

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		ret;

	va_start (ap, format);
	ret = vprintf(format, ap);
	va_end(ap);
	return (ret);
}


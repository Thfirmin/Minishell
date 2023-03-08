#include <stdlib.h>

/* 
 * free 
 * Free's an allocated block of memory
 *
 * Header: stdlib.h
 * Prototype: void	free(void *ptr);
 *
 * ptr -> head of allocated block of memory.
 *
 * Return: Non-return functions
 */

void	ft_free(void *ptr)
{
	free(ptr);
}

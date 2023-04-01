#include <stdlib.h>

/* 
 * malloc 
 * Alloc a block of dynamic memory
 *
 * Header: stdlib.h
 * Prototype: void	*malloc(size_t size)
 *
 * seze -> size of memory's block to be allocated
 *
 * Return: head address of allocated memory in success, or NULL in failure
 */

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

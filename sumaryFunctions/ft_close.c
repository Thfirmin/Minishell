#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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

int	main(int argc, char *argv[])
{
	int		ret;
	int		fd;
	char	str[5];

	if (argc != 2)
	{
		printf ("Usage: %s <filepath>\n", argv[0]);
		return (2);
	}

	// Opening a file
	fd = open(argv[1], O_RDONLY);
	for (int i = 0; i < 5; i ++)
	{
		ret = read(fd, str, 4);
		str[ret] = '\0';
		printf ("read[%d]: %s\n", i, str);
	}

	// close file
	ret = close(fd);
	if (ret < 0)
	{
		printf ("Error in close file step\n");
		return (2);
	}
	else
		printf ("File closed\n");

	// Reopen a file
	fd = open(argv[1], O_RDONLY);
	for (int i = 5; i < 10; i ++)
	{
		ret = read(fd, str, 4);
		str[ret] = '\0';
		printf ("read[%d]: %s\n", i, str);
	}
}

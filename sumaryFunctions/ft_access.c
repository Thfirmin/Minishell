#include <unistd.h>
#include <stdio.h>

/*
 * access
 * check user's permission from a file
 *
 * Header: unistd.h
 * Prototype: int	access(const char *pathname, inr mode);
 *
 * pathname -> is the path of file who you want to check
 * mode -> is the flags XORed '|' with the permissions you want to check. (F_OK | X_OK | R_OK | W_OK)
 *
 * Return: zero (0) in sucess, -1 in error and errno will be setted
 */

static void	validation(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int	ret = 0;

	validation(argc, argv);

	// Verify Existent file
	ret = access(argv[1], F_OK);
	printf ("File exist: %s\n", !ret ? "Yes" : "No");
	if (!ret)
	{
		// Verify execute access
		ret = access(argv[1], X_OK);
		printf ("Execute: %s\n", !ret ? "Yes" : "No");

		// Verify read access
		ret = access(argv[1], R_OK);
		printf ("Read: %s\n", !ret ? "Yes" : "No");

		// Verify write access
		ret = access(argv[1], W_OK);
		printf ("Write: %s\n", !ret ? "Yes" : "No");

		// Verify all access
		ret = access(argv[1], F_OK | X_OK | R_OK | W_OK);
		printf ("All permissions: %s\n", !ret ? "Yes" : "No");
	}
	return (0);
}

static void	validation(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <filepath>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
}

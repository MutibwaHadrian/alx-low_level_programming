#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_error_and_exit(int exit_code, const char *error_message, const char
*file_name)
{
	dprintf(STDERR_FILENO, error_message, file_name);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_error_and_exit(97, "Usage: cp file_from file_to\n", NULL);
	}

	const char *file_from = argv[1];
	const char *file_to = argv[2];

	int fd_src = open(file_from, O_RDONLY);

	if (fd_src == -1)
	{
		print_error_and_exit(98, "Error: Can't read from file %s\n", file_from);
	}

	int fd_dest = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_dest == -1)
	{
		print_error_and_exit(99, "Error: Can't write to %s\n", file_to);
	}

	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_src, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_dest, buffer, bytes_read);
		if (bytes_written == -1)
		{
			print_error_and_exit(99, "Error:
					Can't write to %s\n", file_to);
		}
	}

	if (bytes_read == -1)
	{
		print_error_and_exit(98, "Error:
				Can't read from file %s\n", file_from);
	}

	if (close(fd_src) == -1 || close(fd_dest) == -1)
	{
		print_error_and_exit(100, "Error:
				Can't close fd %d\n", errno);
	}

	return (0);
}

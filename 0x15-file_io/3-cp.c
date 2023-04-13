#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "main.h"

#define BUF_SIZE 1024

void error_exit(int exit_code, const char *error_message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", error_message);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t num_read, num_written;
	char buf[BUF_SIZE];

	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to");
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		error_exit(98, strerror(errno));
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		error_exit(99, strerror(errno));
	}

	while ((num_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		num_written = write(fd_to, buf, num_read);
		if (num_written != num_read)
		{
			error_exit(99, strerror(errno));
		}
	}

	if (num_read == -1)
	{
		error_exit(98, strerror(errno));
	}

	if (close(fd_from) == -1)
	{
		error_exit(100, strerror(errno));
	}

	if (close(fd_to) == -1)
	{
		error_exit(100, strerror(errno));
	}

	return (0);
}

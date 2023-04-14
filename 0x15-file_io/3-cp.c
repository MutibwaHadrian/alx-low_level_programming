#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * print_error_exit - Prints an error message to the POSIX standard error
 * stream
 *
 * @code: The exit code to be used when exiting the program.
 * @message: The format string for the error message
 *
 * Return Value: None. The function exits the program with the specified exit
 * code.
 */
void print_error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(code);
}

/**
 *copy_file - Copies the content of one file to another file
 *@file_from: The pointer to the source file from which to copy the content.
 *file_to: the pointer to the destination file to which to copy the content.
 *
 * Return Value: None. The function exits the program with the appropriate
 * exit code if any errors occur during the file copy operation.
 */


void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		print_error_exit(98, file_from);
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |
			S_IRGRP | S_IROTH);
	if (fd_to == -1)
	{
		print_error_exit(99, file_to);
	}

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			print_error_exit(99, file_to);
		}
	}

	if (bytes_read == -1)
	{
		print_error_exit(98, file_from);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		print_error_exit(100, "");
	}

}
/**
 * main - The entry point of the program
 * @argc: The number of command-line arguments.
 * @argv[]: a pointer to An array of strings containing the command-line
 *  arguments.
 *
 * Return: int. The exit code to be returned by the program
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_error_exit(97, "Usage: cp file_from file_to");
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

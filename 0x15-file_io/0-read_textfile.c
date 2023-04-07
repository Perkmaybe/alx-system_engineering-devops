#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints its contents to stdout.
 *
 * @filename: Name of the file to read.
 * @letters: Maximum number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 if an error occurred.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
        char *buf;
        ssize_t file_descriptor, bytes_read, bytes_written;

        if (!filename)
                return (0);

        buf = malloc(letters * sizeof(char));
        if (!buf)
                return (0);

        file_descriptor = open(filename, O_RDONLY);
        if (file_descriptor == -1)
        {
                free(buf);
                return (0);
        }

        bytes_read = read(file_descriptor, buf, letters);
        bytes_written = write(STDOUT_FILENO, buf, bytes_read);

        free(buf);
        close(file_descriptor);

        return (bytes_written);
}


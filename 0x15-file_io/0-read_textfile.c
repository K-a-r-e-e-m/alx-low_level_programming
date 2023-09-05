#include "main.h"

/**
 * read_textfile - Textfile
 *
 * @filename: The name of file passed to function.
 * @letters: The number of letters it should read and print.
 *
 * Description: This function reads a text file and prints it to
 * the POSIX standard output.
 *
 * Return: The actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fileDescr, sz;
	char *buff; 
	
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL || filename == NULL)
		return (0);
		
	fileDescr = open("filename", O_RDONLY);
	if (fileDescr < 0)
	{
		free(buff);
		return (0);		
	}


	sz = read(fileDescr, buff, letters);
	sz = write(STDOUT_FILENO, buff, sz);
	if (sz < 0)
	{
		close(fileDescr);
		free(buff);
		return (0);		
	}

	free(buff);
	close(fileDescr);
	return (sz);
}
#include "main.h"

/**
 * puts_half - Entery point
 *
 * @str: char pointer parameter.
 *
 * Description: print a string.
 *
 * Return: nothing it is a void function.
 */
void puts_half(char *str)
{
	int i, length;

	length = 0;
	while (str[length] != '\0')
		length++;

	for (i = ((length - 1) / 2) + 1; i < length; i++)
		_putchar (str[i]);

	_putchar ('\n');
}

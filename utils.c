#include "asm.h"

int			count_digits(int value, int n)
{
	int 	count;

	count = 0;
	if (value == 0)
		return (1);
	if (value < 0)
		count++;
	while (value != 0)
	{
		value /= n;
		count++;
	}
	return (count);
}

char		*reverse_string(char *str, int n)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < n)
	{
		tmp = str[i];
		str[i] = str[n];
		str[n] = tmp;
		i++;
		n--;
	}
	return (str);
}
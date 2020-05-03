#include "asm.h"

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

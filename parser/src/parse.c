#include <ctype.h>
#include <stdio.h>
#include <libft.h>

char * parse(char *s)
{
	while (isspace(*s))
		s++;
	return (s);
}

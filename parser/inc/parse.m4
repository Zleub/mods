#include <ctype.h>
#include <string.h>
#include <stdio.h>

char *parse_EOP(char *s)
{
	(void)s;
	return (0);
}

define(parse, parse_$1)
define(prototype, char *`parse($1)'(char*);)
define(ref_loop, `ifelse($#, 1, `parse($1)', `parse($1)`,' ref_loop(shift($@))')')

define(token, `
char *parse_$1(char*s) {
	int i = 0;
	char *(*array[])(char*) = {
		ifelse($#, 1, parse(EOP), ref_loop(shift($@, EOP))), NULL
	};

	printf("%8d:%12s > %s\n", __LINE__, __func__, s);

	while (isspace(*s))
		s++;
	if (!strncmp(s, "$1", strlen("$1")))
		return (s + strlen("$1"));
	while(array[i])
	{
		char * _s;
		_s = array[i](s);
		if (_s)
			return (_s);
		i++;
	}
	return (s);
}
')

# define(each, `ifelse($#, 1, `token($1)
# ', `token($1)
# each(shift($@))')')

define(`test', `
	define(`each', `
		ifelse( `$#', `1', prototype($1), prototype($1) each(shift($@)) )
	')
	each($@)
')

traceon(`test')
traceon(`each')
traceon(`ifelse')
traceon(`prototype')
traceon(`shift')

test(`foo, bar', `bar, meh', `baz')

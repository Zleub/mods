
define(parse, parse_$1)
define(prototype, char *`parse($1)'(char*);)
define(ref_loop, `ifelse($#, 1, `parse($1)', `parse($1)`,' ref_loop(shift($@))')')

define(token, `
char *parse_$1(char*s) {
	char *(*array[])(char*) = {
		ifelse($#, 1, parse(EOP), ref_loop(shift($@, EOP)))
	};

	if (!strncmp(s, "$1", strlen("$1")))
		return (s + strlen("$1"));
	return (s);
}
')

define(each, `ifelse($#, 1, `prototype($1)
', `prototype($1)
each(shift($@))')')

each(`foo, bar', `bar, foo, meh', meh)

undefine(`each')

define(each, `ifelse($#, 1, `token($1)
', `token($1)
each(shift($@))')')

each(`foo, bar', `bar, foo, meh', meh)

int main(void)
{
	return (0);
}

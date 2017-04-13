#include <parse.h>

char * parse(char *s);

int main(void)
{
	char *s;

	s = parse_hello("Hello World !");
	printf("%d: %s\n", __LINE__, s);
	s = parse_world(s);
	printf("%d: %s\n", __LINE__, s);
	s = parse_exclamation(s);
	printf("%d: %s\n", __LINE__, s);

	s = parse_hello("\t\tHelloWorld!");
	printf("%d: %s\n", __LINE__, s);
	s = parse_world(s);
	printf("%d: %s\n", __LINE__, s);
	s = parse_exclamation(s);
	printf("%d: %s\n", __LINE__, s);

	return (0);
}

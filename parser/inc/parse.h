#ifndef PARSE_H
# define PARSE_H

#include <ctype.h>
#include <stdio.h>
#include <libft.h>

#define TOKEN         \
	T(hello, Hello)   \
	T(world, World)   \
	T(exclamation, !)

// Hello World !?
// Hello -> World -> !   -> EOP
//                -> EOP

char * parse_EOP(char *s) {
	(void)s;
	return (0);
}

#define P(s, ...) parse_##s
#define T(n, t) char * P(n)(char *s);
// { \
// 	while (isspace(*s)) \
// 		s++; \
// 	printf("%s %d: <%s>\n", __func__, __LINE__, s);\
// 	if (!strncmp(s, #t, strlen(#t))) \
// 		return (s + strlen(#t)); \
// 	return (s); \
// }

TOKEN

#define STATES                   \
	S(hello, world)              \
	S(world, exclamation, EOP)   \
	S(exclamation, EOP)

// #define S(sA, sB) \
// 	{ parse_##sA, parse_##sB },

#define S(a, ...) char * parse_##a(char *s) \
{ \
	char *(*states[])(char *) = { \
		P(__VA_ARGS__) \
	}; \
\
	(void)s;\
	return (0);\
} \

STATES

#endif

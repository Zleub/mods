#include <stdio.h>

#define TYPES \
	T(char, t_int8) \
	T(unsigned char, t_uint8) \
	T(short, t_int16) \
	T(unsigned short, t_uint16) \
	T(int, t_int32) \
	T(unsigned int, t_uint32) \
	T(long, t_int64) \
	T(unsigned long, t_uint64) \
	T(void *, t_uptr) \
	T(union u_value, t_value)

#define T(type, def) typedef type def;
TYPES

#undef T
#define T(type, def) printf(#def ": %zu [%zu]\n", sizeof(type), sizeof(type) * 8);

union u_value {
	t_int8 int8;
	t_int16 int16;
	t_int32 int32;
	t_int64 int64;
};

#define INT8(x) (t_value){ .int8 = x }
#define INT16(x) (t_value){ .int16 = x }
#define INT32(x) (t_value){ .int32 = x }
#define INT64(x) (t_value){ .int64 = x }

int main(void)
{
	t_value v = INT8(42);
	printf("%d\n", v.int8);
	v = INT16(1024);
	printf("%d\n", v.int16);
	return (0);
}

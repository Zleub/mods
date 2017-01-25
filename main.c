#include <stdlib.h>
#include <stdio.h>

#define VECTORS \
	T(float, float2, __attribute__((ext_vector_type(2)))) \
	T(float, float3, __attribute__((ext_vector_type(3)))) \
	T(float, float4, __attribute__((ext_vector_type(4)))) \
	T(t_int32, int2, __attribute__((ext_vector_type(2)))) \
	T(t_int32, int3, __attribute__((ext_vector_type(3)))) \
	T(t_int32, int4, __attribute__((ext_vector_type(4))))

#define TYPES \
	T(char, int8) \
	T(unsigned char, uint8) \
	T(short, int16) \
	T(unsigned short, uint16) \
	T(int, int32) \
	T(unsigned int, uint32) \
	T(long, int64) \
	T(unsigned long, uint64) \
	T(union u_value, value) \
	T(struct s_table, table) \
	T(void *, uptr) \
	VECTORS

#define T(type, def, ...) typedef type t_##def __VA_ARGS__;
TYPES

union u_value {
	t_int8	int8;
	t_int16	int16;
	t_int32	int32;
	t_int64	int64;
};

#define INT8(x) (t_value){ .int8 = x }
#define INT16(x) (t_value){ .int16 = x }
#define INT32(x) (t_value){ .int32 = x }
#define INT64(x) (t_value){ .int64 = x }

struct s_table
{
	t_table *metatable;

	t_value *table;
	t_value *array;
	t_uint64 size;
};

#undef T
#define T(type, def, ...) printf(#def ": %zu [%zu]\n", sizeof(t_##def), sizeof(t_##def) * 8);
void debug_types(void) {
	TYPES
}

#undef T
#define T(type, def, ...) t_##def * def##_alloc(void) { \
	t_##def *v = malloc(sizeof(t_##def)); \
	size_t i = 0; \
	while (i < sizeof(t_##def)) \
		((char *)v)[i] = 0; \
	return v; \
}

TYPES

unsigned int	hash(char *line)
{
	unsigned int	h;
	int				c;

	h = 5381;
	while ((c = *line++))
		h = ((h << 5) + h) ^ c;
	return (h);
}

#define HASH_TEST(key) printf("%-10s --> %10d\n", key, hash(key))
int main(void)
{
	debug_types();

	for (int i = 0; i < 255; ++i)
		for (int j = 0; j < 255; ++j)
		{
			char s[2];
			s[0] = i;
			s[1] = j;
			HASH_TEST(s);
		}

	unsigned char s[10] = { 0 };
	for (int i = 0; i < 1024 * 1024; ++i)
	{
		for (int i = 0; i < 10; i++)
		{
			s[i] += 1;
			if (s[i] < 255)
				break ;
			s[i] = 0;
		}
		for (int i = 0; i < 10; ++i)
		{
			printf("%02x", s[i]);
		}
		HASH_TEST((char*)s);
	}


	return (0);
}

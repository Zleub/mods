#ifndef TYPES_H
# define TYPES_H

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
	T(void *, uptr) \
	T(union u_value, value) \
	T(struct s_table, table) \
	VECTORS

#define T(type, def, ...) typedef type t_##def __VA_ARGS__;
TYPES

union u_value {
	t_int8	int8;
	t_int16	int16;
	t_int32	int32;
	t_int64	int64;
	t_uptr	ptr;
};

t_value nil = {
	.ptr = NULL
};

struct s_table
{
	t_uint64 size;
	t_value *table;
	t_table *metatable;
	t_uptr	*array;
};

#define INT8(x) (t_value){ .int8 = x }
#define INT16(x) (t_value){ .int16 = x }
#define INT32(x) (t_value){ .int32 = x }
#define INT64(x) (t_value){ .int64 = x }

#undef T
#define T(type, def, ...) printf(#def ": %zu [%zu]\n", sizeof(t_##def), sizeof(t_##def) * 8);
void debug_types(void) {
	TYPES
}

#undef T
#define T(type, def, ...) t_##def * def##_alloc(void) { \
	t_##def *v = malloc(sizeof(t_##def)); \
	size_t i = 0; \
	while (i < sizeof(t_##def)) { \
		((char *)v)[i] = 0; \
		i += 1; \
	} \
	return v; \
}

TYPES

#endif

struct test {
	unsigned int i;
	unsigned int j;
} t_array[1024 * 1024] = {
	#include "test_include"
};

int main() {
	return (0);
}

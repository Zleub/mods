#include <stdlib.h>
#include <stdio.h>

struct test {
	unsigned int i;
	unsigned int j;
} t_array[1024 * 1024] = {
#include "test_include"
};

struct count {
	unsigned long int i;
	unsigned long int c;
	struct count *next;
};

void add(struct count *head, unsigned long int i) {
	if (head->i == i)
		head->c += 1;
	else if (!head->next) {
		head->next = malloc(sizeof(struct count));
		head->next->i = i;
		head->next->c = 1;
		head->next->next = NULL;
	}
	else
		add(head->next, i);
}

unsigned long max = 0;
unsigned long back = 0;
void print(struct count *h) {
//	printf("%lu [%lu]\n", h->i, h->c);
	if (h->c > max) {
		back = max;
		max = h->c;
	}
	if (h->next)
		print(h->next);
	else
		printf("%lu, %lu\n", back, max);
}

int main() {
	struct count h = {
		.i = t_array[0].j,
		.c = 1,
		.next = NULL
	};

	int i = 0;
	while(i < 1024 * 1024 && t_array[i].j) {
		add(&h, t_array[i].j);
		i += 1;
	}

	print(&h);

	return (0);
}

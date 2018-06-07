#include <stdio.h>

struct	some {
	int a:11;
	int b:21;
};


int		main()
{
	struct some	s1;

	s1 = (struct some) {~0, 0};
	printf("a is : %d\n", s1.a);
	if (s1.a == ~0) { printf("hurray\n");}
	return (0);
}

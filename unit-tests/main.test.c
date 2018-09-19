#include <stdio.h>
#include "libftprintf.h"

int		main()
{
	double	a;

	printf("b conversion tests:\n\n");

	ft_printf("%b\n", (int[1]){13});
	ft_printf("%hb\n", (char[2]){0xab, 0x12});
	ft_printf("%.2hhb\n", (char[2]){0xab, 0x12});
	ft_printf("%+hhb\n", (char[2]){0xab, 0x12});
	ft_printf("%+36hhb\n", (char[2]){0xab, 0x12});
	ft_printf("%+36b\n", (int[1]){13});
	ft_printf("%#+36hhb\n", (char[2]){0xab, 0x12});
	ft_printf("%#+36b\n", (int[1]){13});
	ft_printf("%'#+36hhb\n", (char[2]){0xab, 0x12});
	ft_printf("%'#+36b\n", (int[1]){13});

	ft_printf("%B\n", (int[1]){13});
	ft_printf("%hB\n", (char[2]){0xab, 0x12});
	ft_printf("%.2hhB\n", (char[2]){0xab, 0x12});
	ft_printf("%+hhB\n", (char[2]){0xab, 0x12});
	ft_printf("%+36hhB\n", (char[2]){0xab, 0x12});
	ft_printf("%+36B\n", (int[1]){13});
	ft_printf("%#+36hhB\n", (char[2]){0xab, 0x12});
	ft_printf("%#+36B\n", (int[1]){13});
	ft_printf("%'#+36hhB\n", (char[2]){0xab, 0x12});
	ft_printf("%'#+36B\n", (int[1]){13});

	printf("e conversion tests:\n\n");

	a = 456321.456783754;
	ft_printf("a is :%'0198.100e\n", a);
	a = 123e10;
	ft_printf("a is :%e\n", a);
	ft_printf("a is :%'0e\n", a);
	ft_printf("a is :%'#e\n", a);
	ft_printf("a is :%'#0e\n", a);
	ft_printf("a is :%'#0.10e\n", a);
	ft_printf("a is :%'#-.10e\n", a);

	printf("g conversion tests:\n\n");

	a = 456321.456783754;
	ft_printf("a is :%'0198.100g\n", a);
	a = 123e10;
	ft_printf("a is :%g\n", a);
	ft_printf("a is :%'0g\n", a);
	ft_printf("a is :%'#g\n", a);
	ft_printf("a is :%'#0g\n", a);
	ft_printf("a is :%'#0.10g\n", a);
	ft_printf("a is :%'#-.10g\n", a);

	ft_printf("%{>2}this isn't really an error\n");

	return (0);
}

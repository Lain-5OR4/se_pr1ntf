
#include "ft_printf.h"

int	put_space(int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += ft_putchar(' ');
		len--;
	}
	return (count);
}


#include "ft_printf.h"

int	putzero(int len)
{
	int	count;

	count = 0;
	if (len < 0)
		return (0);
	while (len > 0)
	{
		count += ft_putchar('0');
		len--;
	}
	return (count);
}

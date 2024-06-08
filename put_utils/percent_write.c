
#include "ft_printf.h"

int	percent_writer(t_tok *flag)
{
	int	count;

	count = 0;
	if (flag->minus == 1)
	{
		count += ft_putchar('%');
		count += putspace(flag->width - count);
	}
	else
	{
		if (flag->zero == 0)
			count += putspace(flag->width - 1);
		else
			count += putzero(flag->width - 1);
		count += ft_putchar('%');
	}
	return (count);
}

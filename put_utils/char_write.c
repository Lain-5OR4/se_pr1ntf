
#include "ft_printf.h"

int	char_writer(int args, t_tok *tok)
{
	int	count;

	count = 0;
	if (tok->minus == 1)
	{
		count += ft_putchar((char)args);
		count += putspace(tok->width - 1);
	}
	else
	{
		count += putspace(tok->width - 1);
		count += ft_putchar((char)args);
	}
	return (count);
}

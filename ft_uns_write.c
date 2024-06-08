/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:16:16 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:16:17 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_minus_sign_ui(t_tok *tok, unsigned int ui)
{
	int	count;

	count = 0;
	count += putzero((tok->precision - ft_unslen(ui)) + (ui == 0
				&& tok->precision >= 0));
	ft_putnbr_base((unsigned long long)ui, "0123456789", &count, tok);
	count += putspace(tok->width - count);
	return (count);
}

int	uint_writer(unsigned int i, t_tok *flag)
{
	int	count;
	int	count_of_zero;

	count = 0;
	count_of_zero = 0;
	if (flag->minus == 1)
		count += handle_minus_sign_ui(flag, i);
	else
	{
		if (flag->zero == 0 || (flag->zero == 1 && flag->precision >= 0)
			|| (flag->zero == 0 && flag->precision == 0))
		{
			count_of_zero = flag->precision - ft_unslen(i);
			if (count_of_zero < 0)
				count_of_zero = 0;
			count += putspace(flag->width - count_of_zero - ft_unslen(i)
					+ (i == 0 && flag->precision == 0));
			count += putzero(flag->precision - ft_unslen(i) + (i == 0
						&& flag->precision >= 0));
		}
		else
			count += putzero((flag->width - ft_unslen(i)));
		ft_putnbr_base((unsigned long long)i, "0123456789", &count, flag);
	}
	return (count);
}

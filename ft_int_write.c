/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:14:20 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:14:28 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static int	handle_minus_sign(int nbr, t_tok *tok)
{
	int	count;

	count = 0;
	count += put_sign(tok, nbr);
	count += putzero((tok->precision - ft_intlen(nbr)));
	if (!(nbr == 0 && tok->precision == 0))
		ft_putnbr_fd(nbr, tok, &count);
	count += putspace(tok->width - count);
	return (count);
}

static int	handle_not_minus(int nbr, t_tok *tok)
{
	int	count;
	int	count_of_zero;

	count = 0;
	count_of_zero = 0;
	//printf("handle not minus: %d\n", tok->precision);
	if (tok->zero == 0 || (tok->zero == 1 && tok->precision >= 0)
		|| (tok->zero == 0 && tok->precision == 0))
	{
		count_of_zero = tok->precision - ft_intlen(nbr);
		if (count_of_zero < 0)
			count_of_zero = 0;
		count += putspace(tok->width - count_of_zero - ft_intlen(nbr)
				- check_sign(nbr, tok) + (tok->precision == 0 && nbr == 0));
		count += put_sign(tok, nbr);
		count += putzero((tok->precision - ft_intlen(nbr)));
	}
	else
	{
		count += put_sign(tok, nbr);
		count += putzero((tok->width - ft_intlen(nbr) - check_sign(nbr,
						tok)));
	}
	if (!(nbr == 0 && tok->precision == 0))
		ft_putnbr_fd(nbr, tok, &count);
	return (count);
}

int	int_writer(int nbr, t_tok *tok)
{
	int	count;

	count = 0;
	if (tok->minus == 1)
		count = handle_minus_sign(nbr, tok);
	else
		count = handle_not_minus(nbr, tok);
	return (count);
}

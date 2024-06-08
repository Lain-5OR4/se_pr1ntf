/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:14:11 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:14:14 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_minus_sign_hex(t_tok *tok, char *hex, unsigned int i,
		char ident)
{
	int	count;

	count = 0;
	count += put_sharp(tok, i, ident);
	count += putzero((tok->precision - getnbr_base_len(i, hex, tok)));
	ft_putnbr_base((unsigned long long)i, hex, &count, tok);
	count += putspace(tok->width - count);
	return (count);
}

static int	handle_not_minus_hex(t_tok *tok, char *hex, unsigned int i,
		char identifier)
{
	int	count;
	int	count_of_zero;

	count = 0;
	count_of_zero = 0;
	if (tok->zero == 0 || (tok->zero == 1 && tok->precision >= 0)
		|| (tok->zero == 0 && tok->precision == 0))
	{
		count_of_zero = tok->precision - getnbr_base_len(i, hex, tok);
		if (count_of_zero < 0)
			count_of_zero = 0;
		count += putspace(tok->width - count_of_zero - getnbr_base_len(i, hex,
					tok) - get_sharp(tok));
		count += put_sharp(tok, i, identifier);
		count += putzero((tok->precision - getnbr_base_len(i, hex, tok)));
	}
	else
	{
		count += put_sharp(tok, i, identifier);
		count += putzero((tok->width - getnbr_base_len(i, hex, tok)
					- get_sharp(tok)));
	}
	ft_putnbr_base(i, hex, &count, tok);
	return (count);
}

int	hex_writer(unsigned int ui, char identifier, t_tok *tok)
{
	char	*hex;
	int		count;

	count = 0;
	if (identifier == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (tok->minus == 1)
		count += handle_minus_sign_hex(tok, hex, ui, identifier);
	else
		count += handle_not_minus_hex(tok, hex, ui, identifier);
	return (count);
}

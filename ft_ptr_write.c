/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:15:01 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:15:03 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_writer(unsigned long long p, t_tok *tok)
{
	int	count;
	int	space_num;

	count = 0;
	space_num = 1;
	getnbr_base(p, "0123456789abcdef", &space_num, tok);
	if (tok->minus == 0)
		count += putspace(tok->width - space_num - 2);
	count += putstr("0x", 2);
	ft_putnbr_base(p, "0123456789abcdef", &count, tok);
	if (tok->minus == 1)
		count += putspace(tok->width - space_num - 2);
	return (count);
}

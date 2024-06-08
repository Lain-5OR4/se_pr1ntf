/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:14:46 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:14:47 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percent_writer(t_tok *tok)
{
	int	count;

	count = 0;
	if (tok->minus == 1)
	{
		count += ft_putchar('%');
		count += putspace(tok->width - count);
	}
	else
	{
		if (tok->zero == 0)
			count += putspace(tok->width - 1);
		else
			count += putzero(tok->width - 1);
		count += ft_putchar('%');
	}
	return (count);
}

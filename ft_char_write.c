/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:13:49 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:13:51 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

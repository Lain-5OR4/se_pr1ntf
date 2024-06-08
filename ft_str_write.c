/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:15:55 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:15:56 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	str_writer(char *s, t_tok *flag)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	//printf("strwriter -> s = %s\n", s);
	if (flag->precision > (int)ft_strlen(s))
		flag->precision = (int)ft_strlen(s);
	if (flag->minus == 1)
	{
		count += putstr(s, flag->precision);
		count += putspace(flag->width - count);
	}
	else
	{
		if (flag->precision == -1)
			flag->precision = (int)ft_strlen(s);
		if (flag->zero == 1)
			count += putzero(flag->width - flag->precision);
		else
			count += putspace(flag->width - flag->precision);
		count += putstr(s, flag->precision);
	}
	return (count);
}

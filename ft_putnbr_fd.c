/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:15:18 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:15:23 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, t_tok *flag, int *count)
{
	long	i;

	i = (long)n;
	if (i < 0)
		i *= -1;
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, flag, count);
		ft_putnbr_fd(i % 10, flag, count);
	}
	else
	{
		*count += ft_putchar(i + '0');
	}
}

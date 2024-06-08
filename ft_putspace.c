/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:15:43 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:15:45 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putspace(int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += ft_putchar(' ');
		len--;
	}
	return (count);
}

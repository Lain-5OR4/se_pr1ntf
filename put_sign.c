/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:16:54 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:16:55 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_sign(t_tok *flag, int nbr)
{
	int	nbr_sign;

	nbr_sign = 1;
	if (nbr < 0)
		nbr_sign = -1;
	if (flag->plus == 1)
	{
		if (nbr_sign == 1)
			return (ft_putchar('+'));
		else
			return (ft_putchar('-'));
	}
	else if (flag->space == 1)
	{
		if (nbr_sign == 1)
			return (ft_putchar(' '));
		else
			return (ft_putchar('-'));
	}
	if (nbr_sign == -1)
		return (ft_putchar('-'));
	return (0);
}

int	check_sign(int nbr, t_tok *tok)
{
	int	count;
	int	nbr_sign;

	count = 0;
	nbr_sign = 1;
	if (nbr < 0)
		nbr_sign = -1;
	if (tok->plus == 1)
	{
		if (nbr_sign == 1)
			count++;
		else
			count++;
	}
	else if (tok->space == 1)
	{
		if (nbr_sign == 1)
			count++;
		else
			count++;
	}
	else if (nbr_sign == -1)
		count++;
	return (count);
}

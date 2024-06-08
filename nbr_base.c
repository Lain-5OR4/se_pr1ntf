/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:16:35 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:16:36 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long ull, char *base, int *count,
		t_tok *tok)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (ull == 0 && tok->precision >= 0)
		return ;
	if (ull >= base_len)
		ft_putnbr_base(ull / (int)base_len, base, count, tok);
	*count += ft_putchar(base[ull % (int)base_len]);
}

void	getnbr_base(unsigned long long ull, char *base, int *num, t_tok *tok)
{
	size_t	base_len;

	if (ull == 0 && tok->precision >= 0)
		(*num)--;
	base_len = ft_strlen(base);
	if (ull >= base_len)
	{
		(*num)++;
		getnbr_base(ull / (int)base_len, base, num, tok);
	}
}

int	getnbr_base_len(unsigned int ui, char *base, t_tok *flag)
{
	int	num;

	num = 1;
	getnbr_base((unsigned long long)ui, base, &num, flag);
	return (num);
}

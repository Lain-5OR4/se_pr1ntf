/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:14:04 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:14:06 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tok(t_tok *tok)
{
	tok->minus = 0;
	tok->zero = 0;
	tok->width = 0;
	tok->precision = -1;
	tok->space = 0;
	tok->sharp = 0;
	tok->plus = 0;
}

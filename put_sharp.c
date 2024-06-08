/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sharp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:16:40 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:16:41 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_sharp(t_tok *tok, unsigned int ui, char identifier)
{
	int	count;

	count = 0;
	if (tok->sharp == 1 && ui != 0)
	{
		if (identifier == 'x')
			count += putstr("0x", 2);
		else
			count += putstr("0X", 2);
	}
	return (count);
}

int	get_sharp(t_tok *tok)
{
	int	count;

	count = 0;
	if (tok->sharp == 1)
		count += 2;
	return (count);
}

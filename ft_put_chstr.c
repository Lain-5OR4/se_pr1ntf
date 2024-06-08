/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:15:09 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:15:11 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char s)
{
	return((int)write(1, &s, 1));
}

int	putstr(char *s, int len)
{
	int	i;

	i = 0;
	if (len == -1)
		len = (int)ft_strlen(s);
	if (len < 0)
		len = len * -1;
	while (s[i] != '\0' && len > 0)
	{
		i += (int)write(1, &s[i], 1);
		len--;
	}
	return (i);
}

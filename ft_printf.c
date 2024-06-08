/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:24:31 by sebiko            #+#    #+#             */
/*   Updated: 2024/05/27 22:24:34 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	if (!str)
		return (-1);
	va_start(ap, str);
	count = parce_proc(&ap, str);
	va_end(ap);
	return (count);
}

/*
int main(void)
{
	int ft;
	int lib;
	// int asterisk = 15;
	// int as2 = 0;
	// int num = 1000;t
	// char *str = NULL;
	// char c = 1270;

	ft_printf("[");
ft = ft_printf("%8.0u",0);
	ft_printf("]\n[");
	lib = printf("%8.0u",0);
	printf("]\n");
	printf("ft :%d\n", ft);
	printf("lib:%d\n", lib);
}
*/

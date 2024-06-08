/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judgment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:14:35 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:14:40 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*flag_handler(const char *str, t_tok *tok)
{
	int	i;

	i = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i + 1] == '-')
			tok->minus = 1;
		else if (str[i + 1] == ' ')
			tok->space = 1;
		else if (str[i + 1] == '#')
			tok->sharp = 1;
		else if (str[i + 1] == '+')
			tok->plus = 1;
		else if (str[i + 1] == '0')
			tok->zero = 1;
		else
			break ;
		i++;
	}
	return ((char *)&str[i + 1]);
}

static char	*width_handler(const char *str, t_tok *flag)
{
	int		i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	flag->width = ft_atoi(str);
	//printf("width = %d\n", flag->width);
	//printf("str = %s\n", &str[i]);
	return ((char *)&str[i]);
}

static char	*precision_handler(const char *str, t_tok *tok)
{
	int		i;

	i = 0;
	if (str[i] == '.')
	{
		/*
		if (format[i + 1] == '*')
		{
			flag->precision = va_arg(*ap, int);
			if (flag->precision < 0)
				flag->precision = -1;
			return ((char *)&format[i + 2]);
		}
		*/
		i++;
		//while(str[i + 1] == '.')
			//i++;
		//while ('0' <= str[i] && str[i] <= '9')
			//i++;
		while(str[i] == '0')
			i++;
		tok->precision = ft_atoi(&str[i]);
		//printf("precision = %d\n", tok->precision);
		//printf("str = %s\n", &str[i]);
		if(!tok->precision)
			return ((char *)&str[i]);
		// intlenがprecisionが0の時１を返してしまう。
		return ((char *)&str[i + ft_intlen(tok->precision)]);
	}
	return ((char *)&str[i]);
}

static int	token_handler(char identifier, va_list *args, t_tok *flag)
{
	int	count;

	count = 0;
	if (identifier == 'c')
		count = char_writer(va_arg(*args, int), flag);
	else if (identifier == 's')
		count = str_writer(va_arg(*args, char *), flag);
	else if (identifier == 'd' || identifier == 'i')
		count = int_writer(va_arg(*args, int), flag);
	else if (identifier == 'p')
		count = ptr_writer((unsigned long long)va_arg(*args, void *), flag);
	else if (identifier == 'u')
		count = uint_writer(va_arg(*args, unsigned int), flag);
	else if (identifier == 'x' || identifier == 'X')
		count = hex_writer(va_arg(*args, unsigned int), identifier, flag);
	else if (identifier == '%')
		count = percent_writer(flag);
	else
		count = ft_putchar(identifier);
	return (count);
}

int	parce_proc(va_list *args, const char *format)
{
	int		count;
	t_tok	tok;

	count = 0;
	while (*format != '\0')
	{
		init_tok(&tok);
		if (*format == '%')
		{
			format = flag_handler(format, &tok);
			format = width_handler(format, &tok);
			format = precision_handler(format, &tok);
			count += token_handler(*format, args, &tok);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}

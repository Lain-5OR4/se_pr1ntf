/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:14:55 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:14:57 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tok
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	space;
	int	sharp;
	int	plus;
}		t_tok;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		putstr(char *s, int writelen);
void	ft_putnbr_fd(int n, t_tok *flag, int *count);
void	ft_putnbr_base(unsigned long long nb, char *base, int *count,
			t_tok *flag);
int		putspace(int len);
int		put_sign(t_tok *flag, int nbr);
int		putzero(int len);
int		put_sharp(t_tok *flag, unsigned int nbr, char ident);
int		parce_proc(va_list *args, const char *format);
int		check_sign(int nbr, t_tok *flag);
void	init_tok(t_tok *tok);
size_t	ft_strlen(const char *s);
int		ft_intlen(int nbr);
int		ft_unslen(unsigned int nbr);
int		ft_atoi(const char *str);
void	getnbr_base(unsigned long long nb, char *base, int *num, t_tok *flag);
int		getnbr_base_len(unsigned int nb, char *base, t_tok *flag);
int		get_sharp(t_tok *flag, int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		char_writer(int args, t_tok *flag);
int		str_writer(char *s, t_tok *flag);
int		int_writer(int nbr, t_tok *flag);
int		ptr_writer(unsigned long long p, t_tok *flag);
int		hex_writer(unsigned int i, char ident, t_tok *flag);
int		uint_writer(unsigned int i, t_tok *flag);
int		percent_writer(t_tok *flag);
#endif

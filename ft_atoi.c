/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebiko <sebiko@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:12:28 by sebiko            #+#    #+#             */
/*   Updated: 2024/06/02 17:12:30 by sebiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int      check_long_of(int sign, long res, char s)
{
        if (sign == 1)
                if (LONG_MAX / 10 < res || (LONG_MAX / 10 == res && LONG_MAX % 10 <= s
                                - '0'))
                        return (1);
        if (sign == -1)
                if (LONG_MIN / -10 < res || (LONG_MIN / -10 == res && (LONG_MIN
                                        % -10 * -1) <= s - '0'))
                        return (-1);
        return (0);
}

int     ft_atoi(const char *str)
{
        int             i;
        int             sign;
        long    res;

        i = 0;
        sign = 1;
        res = 0;
        while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
                i++;
        if (str[i] == '-')
                sign *= -1;
        if (str[i] == '-' || str[i] == '+')
                i++;
        while (str[i] >= '0' && str[i] <= '9' && str[i])
        {
                if (check_long_of(sign, res, str[i]) == 1)
                        return ((int)LONG_MAX);
                if (check_long_of(sign, res, str[i]) == -1)
                        return ((int)LONG_MIN);
                res = (str[i] - '0') + (res * 10);
                i++;
        }
        return ((int)(res * sign));
}

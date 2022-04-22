/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:42:54 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/23 03:36:53 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

static int	calc_num_len(long num, int base, t_fmt *p_ret)
{
	int		len;
	char	*buf;

	len = 0;
	buf = p_ret->data.str_buf;
	if (num < 0)
	{
		buf[0] = '-';
		num *= -1;
	}
	else if (p_ret->f_plus)
		buf[0] = '+';
	else if (p_ret->f_space)
		buf[0] = ' ';
	if (buf[0] != '\0')
	{
		buf++;
		len++;
	}
	if (num == 0)
	{
		*buf = '0';
		return (len + 1);
	}
	return (len + get_numstr_base(buf, num, base, p_ret->f_upper));
}

bool	parse_opt_num(size_t *len, char **fmt, va_list args, t_fmt *p_ret)
{
	int	num_len;

	if (*fmt == 'd' || *fmt == 'i')
		p_ret->type = INT_10BASE;
	else if (*fmt == 'u')
		p_ret->type == UINT_10BASE;
	else if (*fmt == 'x' || *fmt == 'X')
		p_ret->type == UINT_16BASE;
	else
		return (false);
	if (*fmt == 'X')
		p_ret->f_upper = true;
	if (p_ret->type == INT_10BASE)
		p_ret->data.s_digit = va_arg(args, int);
	else
		p_ret->data.s_digit = va_arg(args, unsigned int);
	if (p_ret->type == INT_10BASE)
		p_ret->str_len = calc_num_len(p_ret->data.s_digit, 10, p_ret);
	else if (p_ret->type == UINT_10BASE)
		p_ret->str_len = calc_num_len(p_ret->data.u_digit, 10, p_ret);
	else
		p_ret->str_len = calc_num_len(p_ret->data.u_digit, 16, p_ret);
	return (true);
}

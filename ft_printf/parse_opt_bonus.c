/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:27:16 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/23 03:47:20 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

static bool	is_valid_conv_char(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

static bool	is_valid_flag_char(char c)
{
	return (c == '-' || ft_isdigit(c) || c == '.'
		|| c == '#' || c == ' ' || c == '+');
}

t_fmt	*parse_opt(size_t *len, char **fmt, va_list args)
{
	t_fmt	*p_ret;
	bool	is_valid;

	*fmt += 1;
	if (!is_valid_conv_char(*fmt)
		&& !is_valid_flag_char(*fmt))
		return (check_no_opt_str(len, fmt));
	p_ret = ft_calloc(1, sizeof(t_fmt));
	if (p_ret == NULL)
		return (p_ret);
	parse_opt_flags(fmt, p_ret);
	if (!(parse_opt_c_str(len, fmt, args, p_ret)
			|| parse_opt_num(len, fmt, args, p_ret)
			|| parse_opt_ptr(len, fmt, args, p_ret)))
		return (check_no_opt_str(len, fmt));
	*fmt += 1;
	*len += ft_max(p_ret->opt_num, p_ret->str_len);
	if (p_ret->type == UINT_16BASE && p_ret->data.u_digit != 0 && p_ret->f_hash)
		*len += 2;
	return (p_ret);
}

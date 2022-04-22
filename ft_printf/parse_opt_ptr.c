/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:46:19 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/23 03:24:05 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

bool	parse_opt_ptr(size_t *len, char **fmt, va_list args, t_fmt *p_ret)
{
	size_t	num;

	if (*fmt != 'p')
		return (false);
	p_ret->type = PTR;
	num = va_arg(args, void *);
	if (num == 0)
	{
		p_ret->str_len = 1;
		p_ret->data.str[0] = '0';
	}
	else
		p_ret->str_len = get_numstr_base(p_ret->data.str_buf, num, 16, false);
	p_ret->str_len += 2;
	return (true);
}

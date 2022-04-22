/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_c_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:44:07 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/23 02:44:25 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

bool	parse_opt_c_str(size_t *len, char **fmt, va_list args, t_fmt *p_ret)
{
	if (*fmt == 'c' || *fmt == '%')
	{
		p_ret->type = CHAR;
		if (*fmt == 'c')
			p_ret->data.c = va_arg(args, char);
		else
			p_ret->data.c = '%';
		p_ret->str_len = 1;
	}
	else if (*fmt == 's')
	{
		p_ret->type = STR;
		p_ret->data.str = va_arg(args, char *);
		if (p_ret->data.str == NULL)
			p_ret->data.str = g_NULLSTR;
		p_ret->str_len = ft_strlen(p_ret->data.str);
	}
	else
		return (false);
	return (true);
}

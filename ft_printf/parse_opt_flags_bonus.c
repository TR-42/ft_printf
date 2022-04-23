/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:37:57 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/24 04:19:29 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf_local.h"

void	parse_opt_flags(char **fmt, t_fmt *p_ret)
{
	long	tmp;

	if (**fmt == '-')
		p_ret->f_minus = true;
	else if (**fmt == '0')
		p_ret->f_zero = true;
	else if (**fmt == '.')
		p_ret->f_dot = true;
	else if (**fmt == '#')
		p_ret->f_hash = true;
	else if (**fmt == ' ')
		p_ret->f_space = true;
	else if (**fmt == '+')
		p_ret->f_plus = true;
	else
	{
		tmp = ft_strtol(*fmt, fmt, 10);
		if (tmp > (long)INT_MAX)
			p_ret->opt_num = INT_MAX;
		else
			p_ret->opt_num = tmp;
		return ;
	}
	*fmt += 1;
}

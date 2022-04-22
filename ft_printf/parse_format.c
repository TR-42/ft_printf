/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:19:18 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/23 03:43:47 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "ft_printf_local.h"

t_fmt	*check_no_opt_str(size_t *len, char **fmt)
{
	t_fmt	*p_ret;
	size_t	str_len;

	str_len = 0;
	p_ret = ft_calloc(1, sizeof(t_fmt));
	if (p_ret == NULL)
		return (p_ret);
	p_ret->type = STR;
	p_ret->data.str = *fmt;
	while (len < INT_MAX && *fmt != '\0' && *fmt != '%')
	{
		str_len++;
		len++;
		*fmt += 1;
	}
	p_ret->str_len = len;
	*len += ft_max(p_ret->opt_num, p_ret->str_len);
	return (p_ret);
}

t_list	*parse_format(char *fmt, va_list args)
{
	t_list	*p_ret;
	size_t	ret_len;
	t_fmt	*p_tmp;

	p_ret = NULL;
	ret_len = 0;
	while (*fmt != '\0' && ret_len < INT_MAX)
	{
		if (*fmt == '%')
			ft_lstadd_back(&p_ret,
				ft_lstnew(parse_opt(&ret_len, &fmt, args)));
		else
			ft_lstadd_back(&p_ret,
				ft_lstnew(check_no_opt_str(&ret_len, &fmt)));
		if (p_ret == NULL || ft_lstlast(p_ret)->content == NULL)
			ret_len = SIZE_T_MAX;
	}
	if (ret_len >= INT_MAX)
		ft_lstclear(&p_ret, free);
	return (p_ret);
}

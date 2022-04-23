/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 01:13:22 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/24 04:13:48 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_local.h"

// STDOUT_FILENO
#define DST_FD (1)

static int	print_buf(t_fmt *fmt)
{
	int		pad_len;

	pad_len = fmt->opt_num - fmt->str_len - fmt->head_len;
	if (fmt->f_minus || !(fmt->f_zero))
	{
		while (!(fmt->f_minus) && pad_len-- > 0)
			write(DST_FD, " ", 1);
		write(DST_FD, fmt->header, fmt->head_len);
		write(DST_FD, fmt->data.str_buf, fmt->str_len);
		while (fmt->f_minus && pad_len-- > 0)
			write(DST_FD, " ", 1);
	}
	else
	{
		write(DST_FD, fmt->header, fmt->head_len);
		while (pad_len-- > 0)
			write(DST_FD, "0", 1);
		write(DST_FD, fmt->data.str_buf, fmt->str_len);
	}
	return (ft_max(fmt->str_len + fmt->head_len, fmt->opt_num));
}

static int	print_str(t_fmt *fmt)
{
	int		pad_len;

	pad_len = fmt->opt_num - fmt->str_len;
	if (fmt->f_minus || !(fmt->f_zero))
	{
		while (!(fmt->f_minus) && pad_len-- > 0)
			write(DST_FD, " ", 1);
		write(DST_FD, fmt->data.str, fmt->str_len);
		while (fmt->f_minus && pad_len-- > 0)
			write(DST_FD, " ", 1);
	}
	else
	{
		while (pad_len-- > 0)
			write(DST_FD, "0", 1);
		write(DST_FD, fmt->data.str, fmt->str_len);
	}
	return (ft_max(fmt->str_len, fmt->opt_num));
}

int	print_all(t_list *list)
{
	int		written_count;
	int		tmp;
	t_fmt	*data;

	written_count = 0;
	while (list != NULL)
	{
		data = list->content;
		tmp = 0;
		if (data->type == STR)
			tmp = print_str(data);
		else
			tmp = print_buf(data);
		written_count += tmp;
		list = list->next;
	}
	return (written_count);
}

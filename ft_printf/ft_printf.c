/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:58:25 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/23 01:44:46 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_printf_local.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_list	*list;

	if (*format == '\0')
		return (0);
	else if (format[0] != '%' && format[1] == '\0')
	{
		if (write(STDOUT_FILENO, format, 1) == 1)
			return (1);
		else
			return (-1);
	}
	va_start(args, format);
	list = parse_format(format, args);
	va_end(args);
	if (list == NULL)
		return (-1);
	return (0);
}

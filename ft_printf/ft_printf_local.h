/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_local.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:04:40 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/23 23:01:15 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LOCAL_H
# define FT_PRINTF_LOCAL_H

# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>
# include <libft.h>

# define STR_BUF_LEN (17)

typedef enum e_dtype
{
	CHAR,
	STR,
	PTR,
	INT_10BASE,
	UINT_10BASE,
	UINT_16BASE,
}	t_dtype;

typedef union u_data
{
	char			str_buf[STR_BUF_LEN];
	char			*str;
	void			*p_ptr;
	size_t			ptr;
	char			c;
	int				s_digit;
	unsigned int	u_digit;
}	t_data;

typedef struct s_printf_fmt
{
	t_dtype	type;
	t_data	data;
	int		str_len;
	int		opt_num;

	bool	f_upper:	1;
	bool	f_minus:	1;
	bool	f_zero:		1;
	bool	f_dot:		1;
	bool	f_hash:		1;
	bool	f_space:	1;
	bool	f_plus:		1;
}	t_fmt;

const char *const	g_NULLSTR = "(null)";

int		print_c(t_fmt *fmt);
int		print_s(t_fmt *fmt);
int		print_p(t_fmt *fmt);
int		print_d(t_fmt *fmt);
int		print_i(t_fmt *fmt);
int		print_u(t_fmt *fmt);
int		print_x(t_fmt *fmt);
int		print_X(t_fmt *fmt);
int		print_percent(t_fmt *fmt);

int		get_numstr_base(char *buf, size_t num, int base, bool is_upper);

t_list	*parse_format(char *fmt, va_list args);

t_fmt	*parse_opt(size_t *len, char **fmt, va_list args);

void	parse_opt_flags(char **fmt, t_fmt *p_ret);
bool	parse_opt_c_str(size_t *len, char **fmt, va_list args, t_fmt *p_ret);
bool	parse_opt_num(size_t *len, char **fmt, va_list args, t_fmt *p_ret);
bool	parse_opt_ptr(size_t *len, char **fmt, va_list args, t_fmt *p_ret);


#endif

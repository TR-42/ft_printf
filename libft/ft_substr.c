/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:37:13 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/20 20:43:03 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_smaller(size_t v1, size_t v2)
{
	if (v1 < v2)
		return (v1);
	else
		return (v2);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	size_t	s1_len;
	char	*p_ret;
	char	*p_ret_top;

	if (n <= 0)
		return (ft_strdup(""));
	s1_len = get_smaller(ft_strlen(s1), n);
	p_ret = (char *)malloc(s1_len + 1);
	p_ret_top = p_ret;
	if (p_ret == NULL)
		return (NULL);
	while (s1_len-- > 0)
		*p_ret++ = *s1++;
	*p_ret = '\0';
	return (p_ret_top);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (s == NULL)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
		return (ft_calloc(1, sizeof(char)));
	return (ft_strndup(s + start, len));
}

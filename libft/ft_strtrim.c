/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 05:00:01 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/20 20:42:52 by kfujita          ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		s1_len;
	const char	*s1_end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || *s1 == '\0')
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s1_end = s1 + s1_len - 1;
	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, *s1_end) != NULL)
		s1_end--;
	return (ft_strndup(s1, (size_t)s1_end - (size_t)s1 + 1));
}

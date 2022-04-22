/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:41:10 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/20 01:11:40 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p_ret;

	p_ret = malloc(sizeof(t_list));
	if (p_ret != NULL)
	{
		p_ret->content = content;
		p_ret->next = NULL;
	}
	return (p_ret);
}

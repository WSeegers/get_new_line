/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:53:34 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/10 17:01:10 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (*(t_uchar*)s1 == *(t_uchar*)s2)
	{
		if (!--n)
			return (0);
		s1++;
		s2++;
	}
	return (*(t_uchar*)s1 - *(t_uchar*)s2);
}

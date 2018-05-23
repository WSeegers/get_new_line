/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:19:54 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/23 11:10:42 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uchar	chr;
	t_uchar	*ret;
	size_t	i;

	chr = (t_uchar)(0xff & c);
	ret = (t_uchar*)s;
	i = -1;
	while (++i < n)
		if (ret[i] == chr)
			return (ret + i);
	return (NULL);
}

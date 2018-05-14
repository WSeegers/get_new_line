/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 02:04:35 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/10 14:33:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_uchar *d;
	t_uchar *s;

	d = (t_uchar*)dest;
	s = (t_uchar*)src;
	while (d != (t_uchar*)dest + n)
		*d++ = *s++;
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:44:17 by WSeegers          #+#    #+#             */
/*   Updated: 2018/04/23 15:05:55 by WSeegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		*(t_uchar*)dest++ = *(t_uchar*)src++;
		if (((t_uchar*)dest)[-1] == (t_uchar)c)
			return (dest);
	}
	return (NULL);
}

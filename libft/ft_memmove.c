/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:47:45 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/23 11:20:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MB 1024 * 1024

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	buf[MB];
	size_t	acc;
	size_t	cpy;

	acc = 0;
	while (acc < n)
	{
		if (n - acc > MB)
			cpy = MB;
		else
			cpy = n - acc;
		ft_memcpy(buf, src + acc, cpy);
		ft_memcpy(dest + acc, buf, cpy);
		acc += cpy;
	}
	return (dest);
}

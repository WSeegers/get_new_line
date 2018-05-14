/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:35:48 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/02 19:53:37 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_uchar charmap(const t_uchar c)
{
	if (c < 10)
		return (c + '0');
	if (c < 36)
		return (c - 10 + 'a');
	return (0);
}

char	*ft_itostr(t_ulong nbr, const t_uchar base)
{
	int		size;
	char	*str;

	size = ft_intlen(nbr);
	if (!(str = (char*)ft_memalloc(sizeof(*str) * (size + 1))))
		return (NULL);
	str[--size] = charmap((nbr % base));
	while (--size)
		str[size] = charmap((nbr /= base) % base);
	return (str);
}

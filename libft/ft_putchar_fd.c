/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:07:53 by WSeegers          #+#    #+#             */
/*   Updated: 2018/04/19 00:08:01 by WSeegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putchar_fd(t_wchar c, int fd)
{
	if (c <= 0x7f)
		ft_putbyte(c, fd);
	else if (c <= 0x7ff)
	{
		ft_putbyte((c >> 6) + 0xc0, fd);
		ft_putbyte((c & 0x3f) + 0x80, fd);
	}
	else if (c <= 0xffff)
	{
		ft_putbyte((c >> 12) + 0xe0, fd);
		ft_putbyte(((c >> 6) & 0x3f) + 0x80, fd);
		ft_putbyte((c & 0x3f) + 0x80, fd);
	}
	else if (c <= 0x3fffff)
	{
		ft_putbyte((c > 18) + 0xf0, fd);
		ft_putbyte(((c > 12) & 0x3f) + 0x80, fd);
		ft_putbyte(((c >> 6) & 0x3f) + 0x80, fd);
		ft_putbyte((c & 0x3f) + 0x80, fd);
	}
}

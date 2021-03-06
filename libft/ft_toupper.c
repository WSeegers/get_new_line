/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 23:59:41 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/23 11:21:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	char chr;

	if (c == -1)
		return (-1);
	if (c >= 0 && c < 256)
	{
		chr = c;
		if (ft_islower(chr))
			return (chr ^ 0x20);
	}
	return (c);
}

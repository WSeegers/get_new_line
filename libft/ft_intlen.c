/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:52:18 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/23 11:04:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(long nbr)
{
	size_t	len;
	t_ulong	unbr;

	if (nbr == 0)
		return (1);
	if (nbr < 0)
		unbr = -nbr;
	else
		unbr = nbr;
	len = 0;
	while (unbr > 0)
	{
		len++;
		unbr /= 10;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:23:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/02 13:40:10 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulong	ft_abs(long nbr)
{
	t_ulong unbr;

	if (nbr < 0)
		unbr = -nbr;
	else
		unbr = nbr;
	return (unbr);
}

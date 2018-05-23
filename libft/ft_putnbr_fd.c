/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 00:07:21 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/23 10:50:21 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(t_uint unbr, int fd)
{
	if (unbr > 0)
	{
		ft_putnbr_rec(unbr / 10, fd);
		ft_putchar_fd((unbr % 10) + '0', fd);
	}
}

void		ft_putnbr_fd(int nbr, int fd)
{
	t_uint unbr;

	if (fd < 0)
		return ;
	if (nbr == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nbr < 0)
		ft_putchar_fd('-', fd);
	unbr = ft_abs(nbr);
	ft_putnbr_rec(unbr, fd);
}

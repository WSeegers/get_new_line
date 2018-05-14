/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 00:07:21 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/14 01:34:22 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	t_uint unbr;

	if (nbr == 0)
		ft_putchar('0');
	if (nbr < 0)
		ft_putchar_fd('-', fd);
	unbr = ft_abs(nbr);
	if (unbr > 0)
	{
		ft_putnbr_fd(unbr / 10, fd);
		ft_putchar_fd((unbr % 10) + '0', fd);
	}
}

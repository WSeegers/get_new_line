/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 21:52:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/02 12:23:51 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list **pp_lstcur;
	t_list **pp_lstnext;

	if (!alst || !*alst)
		return ;
	pp_lstcur = alst;
	while ((*pp_lstcur)->next) 
	{
		pp_lstnext = &((*pp_lstcur)->next);
		ft_lstdelone(pp_lstcur, del);
		pp_lstcur = pp_lstnext;
	}
	ft_lstdelone(pp_lstcur, del);
}

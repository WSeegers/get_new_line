/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 21:22:55 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/23 11:07:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p_lst;

	if (!(p_lst = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size ||
			!(p_lst->content = ft_memalloc(content_size)))
	{
		p_lst->content = NULL;
		p_lst->content_size = 0;
		return (p_lst);
	}
	ft_memcpy(p_lst->content, content, content_size);
	p_lst->content_size = content_size;
	return (p_lst);
}

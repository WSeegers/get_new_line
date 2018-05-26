/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:23:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/26 12:22:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static t_file	*ft_getfile(int fd, t_list *flist)
{
	t_file	*file;

	while (((t_file*)flist->content)->fd != fd && flist->next)
		if (flist->next)
			flist = flist->next;
	if (((t_file*)flist->content)->fd != fd)
	{
		file = (t_file*)ft_memalloc(sizeof(t_file));
		*file = NEWFILE(fd);
		flist->next = ft_lstnew(file, sizeof(t_file));
		file = (t_file*)flist->next->content;
	}
	else
		file = (t_file*)flist->content;
	if (read(file->fd, NULL, 0) < 0)
		file->flag = -1;
	return (file);
}

static char		ft_getchar(t_file *file)
{
	int ret;

	if (file->fpos == file->bufsize)
	{
		ret = read(file->fd, file->buf, BUFF_SIZE);
		if (ret <= 0)
		{
			file->flag = ret;
			return (ret);
		}
		file->bufsize = ret;
		file->fpos = 0;
	}
	++file->fpos;
	return (file->buf[file->fpos - 1]);
}

static void		ft_getline(t_file *file, char **line)
{
	char	*buf;
	char	*ret;
	size_t	size;
	size_t	pos;

	size = 64;
	pos = 0;
	ret = ft_strnew(size);
	while ((ret[pos] = ft_getchar(file)) != '\n' && ret[pos] > 0)
	{
		pos++;
		if (pos == size - 1)
		{
			buf = ft_strnew(size *= 2);
			ft_strcpy(buf, ret);
			ft_strdel(&ret);
			ret = buf;
		}
	}
	if (ret[pos] == '\n')
		ret[pos] = '\0';
	*line = ret;
}

static void		ft_clean_flist(t_list **flist)
{
	t_list	*current;
	t_list	*next;
	t_file	*file;

	current = *flist;
	while (current)
	{
		file = (t_file*)current->content;
		next = current->next;
		if (file->flag <= 0)
		{
			if (current == *flist)
				*flist = next;
			ft_strdel(&file->buf);
		}
		current = next;
	}
}

int				get_next_line(int fd, char **line)
{
	static t_list	*flist;
	t_file			*file;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!flist)
	{
		file = (t_file*)ft_memalloc(sizeof(t_file));
		*file = NEWFILE(fd);
		flist = ft_lstnew(file, sizeof(t_file));
	}
	file = ft_getfile(fd, flist);
	ft_getline(file, line);
	if (file->flag >= 0 && ft_strlen(*line))
		ret = 1;
	else
		ret = file->flag;
	ft_clean_flist(&flist);
	return (ret);
}

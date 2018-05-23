/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:23:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/23 13:26:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		*file = newfile(fd);
		flist->next = ft_lstnew(file, sizeof(t_file));
		file = (t_file*)flist->next->content;
	}
	else
		file = (t_file*)flist->content;
	return (file);
}

static char		ft_getchar(t_file* file)
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

static void ft_getline(t_file *file, char **line)
{
	char *buf;
	char *ret;
	size_t size;
	int pos;

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

int		get_next_line(int fd, char **line)
{
	static t_list	*flist;
	t_file			*file;
	int 			ret;
	
	if (fd < 0 || !line)
		return (-1);
	if (!flist)
	{
		file = (t_file*)ft_memalloc(sizeof(t_file));
		*file = newfile(fd);
		flist = ft_lstnew(file, sizeof(t_file));
	}
	file = ft_getfile(fd, flist);
 	ft_getline(file, line);
	return (file->flag);
}

//remember to remove main
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char *line;
	int fd1;
	int fd2;
	int ret;
	
	ret = get_next_line(-1, &line);
	printf("err-> %d\n", ret);
	ret = get_next_line(23, &line);
	printf("err-> %d\n", ret);
	ret = get_next_line(23, NULL);
	printf("err-> %d\n", ret);
	fd1 = open("test_text1.txt", O_RDONLY);
	fd2 = open("test_text2.txt", O_RDONLY);
	while (get_next_line(fd1, &line))
	{
		printf("%s\n", line);
		ft_strdel(&line);
		if (get_next_line(fd2, &line))
			printf("%s\n", line);
		ft_strdel(&line);
	}
	close(fd1);
	return (0);
}

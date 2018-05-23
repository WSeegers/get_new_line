/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:13:33 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/23 13:26:18 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEW_LINE_H
# define GET_NEW_LINE_H

# include "libft.h"

int		get_next_line(const int fd, char **line);

# define BUFF_SIZE 32

typedef unsigned int t_fpos;

typedef struct			s_file
{
	int fd;
	char *buf;
	size_t bufsize;
	t_fpos fpos;
	int flag;
}						t_file;

# define newfile(fd) (t_file){fd, ft_strnew(BUFF_SIZE), 0, 0, 1}

#endif

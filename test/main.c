/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:53:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/23 22:32:57 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

static void get_line(int fd, int nbr)
{
	char *line;

	printf("file no: %d\tret: %d\tline->%s\n", nbr, get_next_line(fd, &line), line);
	free(line);
}

int main(void)
{
	char *line;
	int fd1;
	int fd2;
	int fd3;
	int fd4;
	int ret;

	printf("Error testing: all errors should return -1\n");
	ret = get_next_line(-1, &line);
	printf("err-> %d\n", ret);
	ret = get_next_line(23, &line);
	printf("err-> %d\n", ret);
	ret = get_next_line(23, NULL);
	printf("err-> %d\n\n", ret);

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);
	
	get_line(fd1, 1);
	get_line(fd1, 1);
	get_line(fd2, 2);
	get_line(fd2, 2);
	get_line(fd3, 3);
	get_line(fd3, 3);
	get_line(fd3, 3);
	get_line(fd3, 3);
	get_line(fd4, 4);
	get_line(fd4, 4);
	get_line(fd2, 2);
	get_line(fd2, 2);
	get_line(fd2, 2);
	get_line(fd2, 2);
	get_line(fd2, 2);
	get_line(fd2, 2);
	get_line(fd2, 2);
	get_line(fd2, 2);
	get_line(fd2, 2);

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	
	printf("\nTo finish this test, please type a sentence:\n");
	get_line(0, 0);
	return (0);
}

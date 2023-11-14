/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:45:45 by taekhkim          #+#    #+#             */
/*   Updated: 2023/11/14 20:37:03 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_temp	*start = NULL;
	t_temp			*c_node;
	char			*restr;

	if (read(fd, NULL, 0) == -1)
	{
		c_node = current_temp(start, fd);
		return (remove_target(&start, c_node, NULL));
	}
	if (start == NULL)
	{
		start = new_node(fd);
		if (start == NULL)
			return (NULL);
	}
	restr = NULL;
	c_node = current_temp(start, fd);
	if (c_node == NULL)
		return (NULL);
	restr = (char *)malloc(sizeof(char) * 1);
	if (restr == NULL)
		return (remove_target(&start, c_node, NULL));
	restr[0] = '\0';
	restr = result(c_node, &start, restr);
	return (restr);
}

char	*result(t_temp *c_n, t_temp **start, char *restr)
{
	size_t			next_idx;
	char			*sub;
	int				temp;

	while (1)
	{
		temp = check(start, c_n, restr);
		if (temp == -1)
			return (NULL);
		else if (temp == 1)
			return (restr);
		next_idx = check_next(c_n->content, c_n->idx, c_n->len);
		sub = substr(c_n->content, c_n->idx, (next_idx - c_n->idx));
		if (sub == NULL)
			return (remove_target(start, c_n, restr));
		c_n->idx = next_idx;
		restr = ft_strcat(restr, sub);
		free(sub);
		if (restr == NULL)
			return (remove_target(start, c_n, NULL));
		if (c_n->idx < c_n->len || c_n->content[c_n->idx - 1] == '\n')
			return (restr);
	}
}

size_t	check_next(char *s, ssize_t idx, ssize_t len)
{
	ssize_t	i;

	i = idx;
	while (i < len)
	{
		if (s[i] == '\n')
		{
			return (i + 1);
		}
		i++;
	}
	return (i);
}

char	*ft_strcat(char *s1, char *s2)
{
	size_t	t1;
	size_t	t2;
	char	*restr;

	t1 = 0;
	t2 = 0;
	while (s1[t1] != '\0')
		t1++;
	while (s2[t2] != '\0')
		t2++;
	restr = (char *)malloc(sizeof(char) * (t1 + t2 + 1));
	if (restr == NULL)
	{
		free(s1);
		return (NULL);
	}
	t1 = 0;
	t2 = 0;
	while (s1[t1] != '\0')
		restr[t2++] = (s1[t1++]);
	while (*s2 != '\0')
		restr[t2++] = (*s2++);
	restr[t2] = '\0';
	free(s1);
	return (restr);
}

char	*substr(char *s, ssize_t start, ssize_t len)
{
	ssize_t	i;
	char	*restr;

	restr = (char *)malloc(sizeof(char) * (len + 1));
	if (restr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		restr[i] = s[start + i];
		i++;
	}
	restr[i] = '\0';
	return (restr);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
//     int fd1,fd2,fd3;
//     fd1 = open("temp.txt",O_RDONLY);
// 	fd2 = open("temp2.txt",O_RDONLY);
// 	fd3 = open("temp3.txt",O_RDONLY);
// 	printf("0. %s", get_next_line(fd1));
// 	close(fd1);
// 	printf("0. %s", get_next_line(fd1));
//     printf("1. %s",get_next_line(1002));
// 	printf("2. %s",get_next_line(fd3));
//     //close(fd);
//     //fd = open("temp.txt",O_RDONLY);
//     return (0);
// }
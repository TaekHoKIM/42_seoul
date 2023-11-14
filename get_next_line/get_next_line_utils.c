/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:46:04 by taekhkim          #+#    #+#             */
/*   Updated: 2023/11/14 20:07:00 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_temp	*new_node(int fd)
{
	t_temp	*new;
	char	*temp_con;
	ssize_t	temp_len;

	temp_con = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (temp_con == NULL)
		return (NULL);
	temp_len = read(fd, temp_con, BUFFER_SIZE);
	if (temp_len == -1)
	{
		free(temp_con);
		return (NULL);
	}
	new = (t_temp *)malloc(sizeof(t_temp));
	while (new == NULL)
	{
		free(temp_con);
		return (NULL);
	}
	new->fd = fd;
	new->content = temp_con;
	new->len = temp_len;
	new->idx = 0;
	new->next = NULL;
	return (new);
}

int	content_change(t_temp *node)
{
	ssize_t	temp_len;

	temp_len = read(node->fd, node->content, BUFFER_SIZE);
	if (temp_len == -1)
		return (-1);
	node->idx = 0;
	node->len = temp_len;
	return (1);
}

void	*remove_target(t_temp	**start, t_temp *target, char *restr)
{
	t_temp	*temp;
	t_temp	*remove;

	if (restr != NULL)
		free(restr);
	temp = (*start);
	if (target == NULL)
		return (NULL);
	if (temp == target)
	{
		(*start) = temp->next;
		free(temp->content);
		free(temp);
		return (NULL);
	}
	while (temp->next != target)
	{
		temp = temp->next;
	}
	remove = temp->next;
	temp->next = temp->next->next;
	free(remove->content);
	free(remove);
	return (NULL);
}

t_temp	*current_temp(t_temp *start, int fd)
{
	t_temp	*current;
	t_temp	*add;

	current = start;
	if (current == NULL)
		return (NULL);
	while (current->fd != fd && current->next != NULL)
	{
		current = current->next;
	}
	if (current->fd != fd)
	{
		add = new_node(fd);
		if (add == NULL)
			return (NULL);
		current->next = add;
		return (add);
	}
	return (current);
}

int	check(t_temp **start, t_temp *c_node, char *restr)
{
	if (c_node->idx == c_node->len)
	{
		if (-1 == content_change(c_node))
		{
			remove_target(start, c_node, restr);
			return (-1);
		}
	}
	if (c_node->len == 0 && restr[0] == '\0')
	{
		remove_target(start, c_node, restr);
		return (-1);
	}
	if (c_node->len == 0)
	{
		remove_target(start, c_node, NULL);
		return (1);
	}
	return (0);
}

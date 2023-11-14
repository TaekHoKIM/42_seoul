/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:16:44 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:38:25 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*start_node;

	start_node = malloc(sizeof(t_list));
	if (start_node == NULL)
		return (NULL);
	start_node->content = content;
	start_node->next = NULL;
	return (start_node);
}

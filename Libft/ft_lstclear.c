/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:12:27 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:38:07 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*remove_node;

	if (lst == NULL || del == NULL)
		return ;
	if ((*lst) == NULL)
		return ;
	temp = (*lst);
	while (temp->next != NULL)
	{
		remove_node = temp;
		temp = temp->next;
		del(remove_node->content);
		free(remove_node);
	}
	del(temp->content);
	free(temp);
	(*lst) = NULL;
}

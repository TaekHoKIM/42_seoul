/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:28:22 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:38:22 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	start = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew(NULL);
		if (new == NULL)
		{
			ft_lstclear(&start, del);
			return (start);
		}
		new->content = f(lst->content);
		ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}

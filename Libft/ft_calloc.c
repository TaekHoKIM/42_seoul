/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:45:33 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:37:37 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*return_ptr;

	return_ptr = (void *)malloc(count * size);
	if (return_ptr == NULL)
		return (NULL);
	ft_bzero(return_ptr, count * size);
	return (return_ptr);
}

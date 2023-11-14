/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:43:58 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:12:36 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*return_s;

	i = 0;
	return_s = (unsigned char *)s;
	while (i < n)
	{
		if (return_s[i] == (unsigned char)c)
		{
			return ((void *)&return_s[i]);
		}
		i++;
	}
	return (0);
}

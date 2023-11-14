/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:02:56 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/09 22:12:10 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	i = 0;
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (t_dst > t_src)
	{
		while (len-- != 0)
			t_dst[len] = t_src[len];
	}
	else
	{
		while (i < len)
		{
			t_dst[i] = t_src[i];
			i++;
		}
	}
	return (dst);
}

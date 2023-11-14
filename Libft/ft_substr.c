/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:58:19 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:43:14 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	max;
	char	*return_ptr;

	if (s == NULL)
		return (NULL);
	max = 0;
	if (ft_strlen(s) <= (size_t)start)
		max = 0;
	else
	{
		while (s[(size_t)start + max] != '\0' && max < len)
			max++;
	}
	return_ptr = (char *)malloc(sizeof(char) * (max + 1));
	if (return_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < max)
	{
		return_ptr[i] = s[(size_t)start + i];
		i++;
	}
	return_ptr[i] = '\0';
	return (return_ptr);
}

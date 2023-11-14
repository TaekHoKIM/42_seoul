/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:37:13 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:42:46 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		temp = 0;
		if (haystack[i] == needle[temp])
		{
			while (needle[temp] != '\0' && temp + i < len)
			{	
				if (haystack[i + temp] != needle[temp])
					break ;
				temp++;
			}
			if (needle[temp] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

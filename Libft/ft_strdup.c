/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:50:33 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:41:57 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*return_ptr;

	len = ft_strlen(s1);
	return_ptr = (char *)malloc((sizeof(char) * len) + 1);
	if (return_ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		return_ptr[i] = s1[i];
		i++;
	}
	return_ptr[i] = s1[i];
	return (return_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:55:02 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:42:15 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*return_ptr;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	return_ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (return_ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		return_ptr[i] = f(i, s[i]);
		i++;
	}
	return_ptr[i] = '\0';
	return (return_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:47:05 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:42:05 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_str_len(char const *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*return_ptr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_s1 = st_str_len(s1);
	len_s2 = st_str_len(s2);
	return_ptr = (char *)malloc((sizeof(char) * (len_s1 + len_s2)) + 1);
	if (return_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		return_ptr[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		return_ptr[i] = s2[i - len_s1];
		i++;
	}
	return_ptr[i] = '\0';
	return (return_ptr);
}

static size_t	st_str_len(char const *s)
{
	if (s == NULL)
		return (0);
	else
		return (ft_strlen(s));
}

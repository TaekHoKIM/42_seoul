/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:00:37 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:42:41 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	while (temp1[i] != '\0' && temp2[i] != '\0' && i < n)
	{
		if (temp1[i] > temp2[i])
			return (1);
		else if (temp1[i] < temp2[i])
			return (-1);
		i++;
	}
	if (i == n)
		return (0);
	if (temp1[i] > temp2[i])
		return (1);
	else if (temp1[i] < temp2[i])
		return (-1);
	return (0);
}

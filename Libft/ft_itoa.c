/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:05:08 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:37:47 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*mal_char(int n);
static void		in_char(char *s, unsigned int n, unsigned int strat_idx);
static size_t	int_count(int n);

char	*ft_itoa(int n)
{
	char			*return_ptr;
	size_t			i;
	unsigned int	temp;

	return_ptr = mal_char(n);
	if (return_ptr == NULL)
		return (NULL);
	if (n < 0)
	{
		i = 1;
		temp = (unsigned int)(n * -1);
	}
	else
	{
		i = 0;
		temp = (unsigned int)n;
	}
	in_char(return_ptr, temp, i);
	return (return_ptr);
}

static char	*mal_char(int n)
{
	char	*return_ptr;
	size_t	count;

	count = int_count(n);
	if (n < 0)
	{
		return_ptr = (char *)malloc(sizeof(char) * (count + 2));
		if (return_ptr == NULL)
			return (NULL);
		return_ptr[0] = '-';
		return_ptr[count + 1] = '\0';
	}
	else
	{
		return_ptr = (char *)malloc(sizeof(char) * (count + 1));
		if (return_ptr == NULL)
			return (NULL);
		return_ptr[count] = '\0';
	}
	return (return_ptr);
}

static void	in_char(char *s, unsigned int n, unsigned int strat_idx)
{
	unsigned int	i;

	i = 1000000000;
	if (n == 0)
	{
		s[0] = '0';
		return ;
	}
	while (n / i == 0)
		i /= 10;
	while (i != 1)
	{
		s[strat_idx] = ((n / i) % 10) + '0';
		strat_idx++;
		i /= 10;
	}
	s[strat_idx] = ((n / i) % 10) + '0';
}

static size_t	int_count(int n)
{
	size_t			count;
	unsigned int	temp;

	count = 1;
	if (n < 0)
	{
		temp = (unsigned int)(n * -1);
	}
	else
		temp = (unsigned int)n;
	while (temp >= 10)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

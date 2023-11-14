/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:17:59 by taekhkim          #+#    #+#             */
/*   Updated: 2023/10/17 16:41:14 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num(unsigned int nb, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
		write(fd, "-", 1);
		print_num(nb, fd);
	}
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		nb = (unsigned int)n;
		print_num(nb, fd);
	}
}

static void	print_num(unsigned int nb, int fd)
{
	unsigned int	i;
	char			temp;

	i = 1000000000;
	while (nb / i == 0)
		i /= 10;
	while (i != 1)
	{
		temp = ((nb / i) % 10) + '0';
		write(fd, &temp, 1);
		i /= 10;
	}
	temp = ((nb / i) % 10) + '0';
	write(fd, &temp, 1);
}

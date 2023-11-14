/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:21:05 by taekhkim          #+#    #+#             */
/*   Updated: 2023/11/01 18:37:10 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_print(va_list *arg_ptr, int *len)
{
	unsigned long long	value;
	void				*ptr;

	ptr = va_arg(*arg_ptr, void *);
	value = (unsigned long long)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	(*len) += 2;
	if (p_print_sub(value, len) == -1)
		return (-1);
	return (1);
}

int	p_print_sub(unsigned long long value, int *len)
{
	char	*set;

	set = "0123456789abcdef";
	if (value < 16)
	{
		(*len)++;
		if (write(1, &set[value], 1) == -1)
			return (-1);
		return (1);
	}
	if (p_print_sub(value / 16, len) == -1)
		return (-1);
	if (write(1, &set[value % 16], 1) == -1)
		return (-1);
	(*len)++;
	return (1);
}

int	d_print(va_list *arg_ptr, int *len)
{
	int				temp;
	unsigned int	value;

	temp = va_arg(*arg_ptr, int);
	if (temp < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*len)++;
		temp = temp * -1;
	}
	value = (unsigned int)temp;
	if (du_print_sub(value, len) == -1)
		return (-1);
	return (1);
}

int	du_print_sub(unsigned int value, int *len)
{
	char			*set;

	set = "0123456789";
	if (value < 10)
	{
		if (write(1, &set[value], 1) == -1)
			return (-1);
		(*len)++;
		return (1);
	}
	if (du_print_sub(value / 10, len) == -1)
		return (-1);
	if (write(1, &set[value % 10], 1) == -1)
		return (-1);
	(*len)++;
	return (1);
}

int	u_print(va_list *arg_ptr, int *len)
{
	unsigned int	value;

	value = va_arg(*arg_ptr, unsigned int);
	if (du_print_sub(value, len) == -1)
		return (-1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:50:57 by taekhkim          #+#    #+#             */
/*   Updated: 2023/11/01 18:37:09 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_print(va_list	*arg_ptr, int *len)
{
	unsigned int	value;

	value = va_arg(*arg_ptr, unsigned int);
	if (x_print_sub(value, len) == -1)
		return (-1);
	return (1);
}

int	x_print_sub(unsigned int value, int *len)
{
	char	*set;

	set = "0123456789abcdef";
	if (value < 16)
	{
		if (write(1, &set[value], 1) == -1)
			return (-1);
		(*len)++;
		return (1);
	}
	if (x_print_sub(value / 16, len) == -1)
		return (-1);
	if (write(1, &set[value % 16], 1) == -1)
		return (-1);
	(*len)++;
	return (1);
}

int	bigx_print(va_list	*arg_ptr, int *len)
{
	unsigned int	value;

	value = va_arg(*arg_ptr, unsigned int);
	if (bigx_print_sub(value, len) == -1)
		return (-1);
	return (1);
}

int	bigx_print_sub(unsigned int value, int *len)
{
	char	*set;

	set = "0123456789ABCDEF";
	if (value < 16)
	{
		if (write(1, &set[value], 1) == -1)
			return (-1);
		(*len)++;
		return (1);
	}
	if (bigx_print_sub(value / 16, len) == -1)
		return (-1);
	if (write(1, &set[value % 16], 1) == -1)
		return (-1);
	(*len)++;
	return (1);
}

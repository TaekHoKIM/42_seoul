/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:02:07 by taekhkim          #+#    #+#             */
/*   Updated: 2023/11/01 19:10:20 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		idx;
	int		len;
	int		temp;

	idx = 0;
	len = 0;
	va_start(arg, format);
	while (format[idx] != '\0')
	{
		temp = normal_print(format, idx);
		if (temp == -1)
			return (-1);
		idx += temp;
		len += temp;
		if (format[idx] == '\0' || format[idx + 1] == '\0')
			return (len);
		if (switch_print(format[idx + 1], &arg, &len) == -1)
			return (-1);
		idx += 2;
	}
	return (len);
}

int	normal_print(const char *format, int idx)
{
	int	start;

	start = idx;
	while (format[idx] != '%' && format[idx] != '\0')
	{
		idx++;
	}
	if (start - idx != 0)
		if (write(1, &format[start], idx - start) == -1)
			return (-1);
	return (idx - start);
}

int	switch_print(char point, va_list *arg_ptr, int *len)
{
	int	check;

	check = 0;
	if (point == 'c')
		check = c_print(arg_ptr, len);
	else if (point == 's')
		check = s_print(arg_ptr, len);
	else if (point == 'p')
		check = p_print(arg_ptr, len);
	else if (point == 'd' || point == 'i')
		check = d_print(arg_ptr, len);
	else if (point == 'u')
		check = u_print(arg_ptr, len);
	else if (point == 'x')
		check = x_print(arg_ptr, len);
	else if (point == 'X')
		check = bigx_print(arg_ptr, len);
	else if (point == '%')
	{
		check = write(1, "%", 1);
		(*len)++;
	}
	if (check == -1)
		return (-1);
	return (1);
}

int	c_print(va_list *arg_ptr, int *len)
{
	char	temp;

	temp = (char)va_arg(*arg_ptr, int);
	(*len)++;
	return (write(1, &temp, 1));
}

int	s_print(va_list *arg_ptr, int *len)
{
	char	*temp;
	size_t	idx;

	temp = va_arg(*arg_ptr, char *);
	if (temp == 0)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		(*len) += 6;
		return (1);
	}
	idx = 0;
	while (temp[idx] != '\0')
		idx++;
	if (write(1, temp, idx) == -1)
		return (-1);
	(*len) += idx;
	return (1);
}

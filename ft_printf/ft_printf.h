/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekhkim <xorgh456@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:21:24 by taekhkim          #+#    #+#             */
/*   Updated: 2023/11/01 19:10:19 by taekhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	normal_print(const char *format, int idx);
int	switch_print(char point, va_list *arg_ptr, int *len);
int	c_print(va_list *arg_ptr, int *len);
int	s_print(va_list *arg_ptr, int *len);
int	p_print(va_list *arg_ptr, int *len);
int	p_print_sub(unsigned long long value, int *len);
int	d_print(va_list *arg_ptr, int *len);
int	du_print_sub(unsigned int value, int *len);
int	u_print(va_list *arg_ptr, int *len);
int	x_print(va_list	*arg_ptr, int *len);
int	x_print_sub(unsigned int value, int *len);
int	bigx_print(va_list	*arg_ptr, int *len);
int	bigx_print_sub(unsigned int value, int *len);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:06:36 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 05:59:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_info	g_printf_info;

int	ft_printf(const char *format, ...)
{
	va_list		v_arg;
	uint64_t	i;
	uint64_t	tmp;
	uint64_t	format_len;

	va_start(v_arg, format);
	g_printf_info.printed_chars = 0;
	g_printf_info.printing_fd = STDOUT_FILENO;
	i = 0;
	format_len = ft_strlen(format);
	while (i < format_len)
	{
		tmp = (uint64_t)ft_strchr_index(format + i, '%');
		ft_static_put_fd(format + i, (uint32_t)(tmp), 0,
						g_printf_info.printing_fd);
		g_printf_info.printed_chars += (tmp);
		i += tmp;
		if (format[i] == '%')
			i += process_conversion(&v_arg, format, i);
		else
			break ;
	}
	ft_static_put_fd(NULL, 0, STATIC_PUT_FLUSH, g_printf_info.printing_fd);
	va_end(v_arg);
	return ((int32_t)g_printf_info.printed_chars);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		v_arg;
	uint64_t	i;
	uint64_t	tmp;
	uint64_t	format_len;

	va_start(v_arg, format);
	g_printf_info.printed_chars = 0;
	g_printf_info.printing_fd = fd;
	i = 0;
	format_len = ft_strlen(format);
	while (i < format_len)
	{
		tmp = (uint64_t)ft_strchr_index(format + i, '%');
		ft_static_put_fd(format + i, (uint32_t)(tmp), 0,
						g_printf_info.printing_fd);
		g_printf_info.printed_chars += (tmp);
		i += tmp;
		if (format[i] == '%')
			i += process_conversion(&v_arg, format, i);
		else
			break ;
	}
	ft_static_put_fd(NULL, 0, STATIC_PUT_FLUSH, g_printf_info.printing_fd);
	va_end(v_arg);
	return ((int32_t)g_printf_info.printed_chars);
}

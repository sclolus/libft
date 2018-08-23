/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 02:15:58 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:58:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_string(t_conversion *conversion)
{
	uint64_t	printed_count;
	uint64_t	len;
	char		*value;

	value = (char *)conversion->value;
	if (value == NULL)
		value = "(null)";
	len = ft_strlen(value);
	len = (conversion->precision > len) || conversion->precision == 0
		? len
		: conversion->precision;
	printed_count = len;
	if (!conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	ft_static_put_fd(value, (uint32_t)len, 0, g_printf_info.printing_fd);
	if (conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	return (printed_count);
}

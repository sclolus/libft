/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_unsigned_decimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 00:48:31 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 00:56:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_unsigned_decimal(t_conversion *conversion)
{
	uint64_t	printed_count;
	uint64_t	len;
	char		*ascii;
	uint64_t	value;

	value = (uint64_t)conversion->value;
	ascii = ft_static_ulltoa(value);
	len = ft_strlen(ascii);
	printed_count = len;
	if (!conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	ft_static_put_fd(ascii, (uint32_t)len, 0, g_printf_info.printing_fd);
	if (conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	return (printed_count);
}

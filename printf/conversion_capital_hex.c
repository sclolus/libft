/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_capital_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 01:15:31 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:56:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_capital_hex(t_conversion *conversion)
{
	uint64_t	printed_count;
	uint64_t	len;
	char		*ascii;
	uint64_t	value;

	value = (uint64_t)conversion->value;
	ascii = ft_static_ulltoa_base(value, HEX_BASE);
	len = ft_strlen(ascii);
	printed_count = len;
	if (conversion->flags.sharp && value != 0)
		printed_count += 2;
	if (!conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	if (conversion->flags.sharp && value != 0)
		ft_static_put_fd("0X", 2, 0, g_printf_info.printing_fd);
	ft_static_put_fd(ascii, (uint32_t)len, 0, g_printf_info.printing_fd);
	if (conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	return (printed_count);
}

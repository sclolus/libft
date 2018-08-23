/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_small_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 00:58:29 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:56:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_small_hex(t_conversion *conversion)
{
	uint64_t	printed_count;
	uint64_t	len;
	char		*ascii;
	uint64_t	value;

	value = (uint64_t)conversion->value;
	ascii = ft_static_ulltoa_base(value, SMALL_HEX_BASE);
	len = ft_strlen(ascii);
	printed_count = len;
	if (conversion->flags.sharp && value != 0)
		printed_count += 2;
	if (!conversion->flags.negative && !conversion->flags.zero_pad)
		printed_count += print_left_padding(conversion, printed_count);
	if (conversion->flags.sharp && value != 0)
		ft_static_put_fd("0x", 2, 0, g_printf_info.printing_fd);
	if (!conversion->flags.negative && conversion->flags.zero_pad)
		printed_count += print_left_padding(conversion, printed_count);
	ft_static_put_fd(ascii, (uint32_t)len, 0, g_printf_info.printing_fd);
	if (conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	return (printed_count);
}

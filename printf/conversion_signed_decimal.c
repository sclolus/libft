/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_signed_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:30:09 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 05:56:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_signed_decimal(t_conversion *conversion)
{
	uint64_t	printed_count;
	uint64_t	len;
	char		*ascii;
	int64_t		value;

	value = (int64_t)conversion->value;
	ascii = ft_static_lltoa(value);
	len = ft_strlen(ascii);
	printed_count = len;
	if ((conversion->flags.plus || conversion->flags.space) && value >= 0)
		printed_count++;
	if (!conversion->flags.negative && !conversion->flags.zero_pad)
		printed_count += print_left_padding(conversion, printed_count);
	if (conversion->flags.plus && value >= 0)
		ft_static_put_fd("+", 1, 0, g_printf_info.printing_fd);
	else if (conversion->flags.space && value >= 0)
		ft_static_put_fd(" ", 1, 0, g_printf_info.printing_fd);
	if (!conversion->flags.negative && conversion->flags.zero_pad)
		printed_count += print_left_padding(conversion, printed_count);
	ft_static_put_fd(ascii, (uint32_t)len, 0, g_printf_info.printing_fd);
	if (conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	return (printed_count);
}

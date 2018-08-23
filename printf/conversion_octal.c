/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 01:23:20 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:58:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_octal(t_conversion *conversion)
{
	uint64_t	printed_count;
	uint64_t	len;
	char		*ascii;
	uint64_t	value;

	value = (uint64_t)conversion->value;
	ascii = ft_static_ulltoa_base(value, OCTAL_BASE);
	len = ft_strlen(ascii);
	printed_count = len;
	if (conversion->flags.sharp)
		printed_count += 1;
	if (!conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	if (conversion->flags.sharp)
		ft_static_put_fd("0", 1, 0, g_printf_info.printing_fd);
	ft_static_put_fd(ascii, (uint32_t)len, 0, g_printf_info.printing_fd);
	if (conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	return (printed_count);
}

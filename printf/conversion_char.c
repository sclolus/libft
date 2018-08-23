/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 01:43:56 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:57:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_char(t_conversion *conversion)
{
	uint64_t	printed_count;
	char		value;

	value = (char)conversion->value;
	printed_count = 1;
	if (!conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	ft_static_put_fd(&value, 1, 0, g_printf_info.printing_fd);
	if (conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	return (printed_count);
}

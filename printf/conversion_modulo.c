/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_modulo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 03:01:40 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 05:46:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_modulo(t_conversion *conversion)
{
	uint64_t	printed_count;

	printed_count = 1;
	if (!conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	ft_static_put_fd("%", 1U, 0, g_printf_info.printing_fd);
	if (conversion->flags.negative)
		printed_count += print_left_padding(conversion, printed_count);
	return (printed_count);
}

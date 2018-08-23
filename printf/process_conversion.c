/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:27:20 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:54:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline uint64_t	process_conversion(va_list *v_arg,
								const char *format,
								uint64_t index)
{
	t_conversion	conversion;
	int64_t			conversion_end_index;

	ft_bzero(&conversion, sizeof(t_conversion));
	conversion_end_index = get_conversion(format + index, v_arg, &conversion);
	if (-1 == conversion_end_index)
		return (index + 1);
	print_conversion(&conversion);
	return ((uint64_t)conversion_end_index);
}

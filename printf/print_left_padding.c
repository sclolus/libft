/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left_padding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:54:21 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 06:07:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>

static inline void	init_padding_bufs(char *zero_padding, char *space_padding)
{
	static bool	first_entry = true;

	if (first_entry)
	{
		ft_memset(zero_padding, (~0U / 255) * '0', 4096);
		ft_memset(space_padding, (~0U / 255) * ' ', 4096);
		first_entry = false;
	}
}

uint64_t			print_left_padding(t_conversion *conversion, uint64_t len)
{
	static char			zero_padding[4096];
	static char			space_padding[4096];
	uint64_t			padding_size;
	char const			*selected_padding;
	uint64_t			i;

	init_padding_bufs(zero_padding, space_padding);
	if (conversion->field_width > len)
	{
		padding_size = conversion->field_width - len;
		if (conversion->flags.zero_pad)
			selected_padding = zero_padding;
		else
			selected_padding = space_padding;
		i = 0;
		while (i < padding_size)
		{
			ft_static_put_fd(selected_padding,
			padding_size - i < 4096 ?
			(uint32_t)(padding_size - i) : 4096, 0, g_printf_info.printing_fd);
			i += 4096;
		}
		return (padding_size);
	}
	return (0);
}

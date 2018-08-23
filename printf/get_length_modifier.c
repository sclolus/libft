/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_modifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:27:35 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:53:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	get_length_modifier(const char *str, t_conversion *conversion)
{
	static const char			*str_modifiers[SUPPORTED_LEN_MODIFIERS + 2] = {
		MODIFIER_LL, MODIFIER_HH, MODIFIER_H, MODIFIER_L, "j", "z",
	};
	static const t_len_modifier	modifiers[SUPPORTED_LEN_MODIFIERS + 2] = {
		MOD_LL, MOD_HH, MOD_H, MOD_L, MOD_LL, MOD_LL,
	};
	uint32_t					i;
	uint64_t					len;

	i = 0;
	while (i < SUPPORTED_LEN_MODIFIERS + 2)
	{
		len = ft_strlen(str_modifiers[i]);
		if (!ft_strncmp(str, str_modifiers[i], len))
		{
			conversion->modifier = modifiers[i];
			return (len);
		}
		i++;
	}
	conversion->modifier = NO_MODIFIER;
	return (0);
}

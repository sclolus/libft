/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 03:43:26 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 04:03:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t		ft_atou_base(const char *str, const char *base)
{
	uint32_t		nbr;
	uint32_t		base_len;
	char			*tmp;

	nbr = 0;
	base_len = ft_strlen(base);
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	while (*str && (tmp = ft_strchr(base, *str)))
	{
		if ((nbr * base_len + (uint32_t)tmp - (uint32_t)base) < nbr
			|| ((nbr > (~0U / base_len))))
		{
			nbr = ~0U;
			break ;
		}
		nbr = nbr * base_len + (uint32_t)tmp - (uint32_t)base;
		str++;
	}
	return (nbr);
}

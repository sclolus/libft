/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollu_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 03:16:33 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 04:03:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_atollu_base(const char *str, const char *base)
{
	uint64_t		nbr;
	uint64_t		base_len;
	char			*tmp;

	nbr = 0;
	base_len = ft_strlen(base);
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	while (*str && (tmp = ft_strchr(base, *str)))
	{
		if ((nbr * base_len + (uint64_t)tmp - (uint64_t)base) < nbr
			|| ((nbr > (~0UL / base_len))))
		{
			nbr = ~0UL;
			break ;
		}
		nbr = nbr * base_len + (uint64_t)tmp - (uint64_t)base;
		str++;
	}
	return (nbr);
}

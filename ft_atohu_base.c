/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 03:47:34 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 04:03:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

uint16_t		ft_atohu_base(const char *str, const char *base)
{
	uint16_t		nbr;
	uint16_t		base_len;
	char			*tmp;

	nbr = 0;
	base_len = ft_strlen(base);
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	while (*str && (tmp = ft_strchr(base, *str)))
	{
		if ((uint16_t)(nbr * base_len + (uint16_t)(tmp - base)) < nbr
			|| ((nbr > (uint16_t)USHRT_MAX / base_len)))
		{
			nbr = (uint16_t)USHRT_MAX;
			break ;
		}
		nbr = nbr * base_len + (uint16_t)(tmp - base);
		str++;
	}
	return (nbr);
}

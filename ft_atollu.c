/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 03:14:36 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 04:03:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_atollu(const char *str)
{
	uint64_t		nbr;

	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((nbr * 10UL + (uint64_t)*str - (uint64_t)'0') < nbr
			|| (nbr > (~0UL / 10UL)))
		{
			nbr = ~0UL;
			break ;
		}
		nbr = nbr * 10UL + (uint64_t)*str++ - (uint64_t)'0';
	}
	return (nbr);
}

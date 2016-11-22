/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:56:39 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/06 18:11:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *tmp_s1;
	unsigned char *tmp_s2;

	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	if (!n)
		return (0);
	if (*tmp_s1 == *tmp_s2 && n > 1)
		return (ft_memcmp(tmp_s1 + 1, tmp_s2 + 1, n - 1));
	else
		return (*tmp_s1 - *tmp_s2);
}

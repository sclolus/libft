/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:41:00 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/07 11:49:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char	utf[2];

	if (!ft_isascii(c))
	{
		utf[0] = 0xC0 | ((unsigned char)c >> 6);
		utf[1] = 0x80 | (0x3F & (unsigned char)c);
		write(1, utf, 2);
	}
	else
		write(1, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:10:20 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/06 18:34:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
  unsigned long	*longword_ptr;
  unsigned int	i;
  unsigned int	len;

  len = ft_strlen(src);
  i = 0;
  while (i < len % 8)
    {
      dst[i] = src[i];
      i++;
    }
  longword_ptr = (unsigned long*)(src + i);
  while (i < len)
    {
      *((unsigned long*)(dst + i)) = *longword_ptr++;
      i += 8;
    }
  return (dst);
}

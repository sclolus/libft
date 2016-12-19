/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:18:10 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/05 13:22:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
  unsigned long	*longword_ptr;
  unsigned int	i;
  unsigned int	n;

  n = ft_strlen(src);
  i = 0;
  while (i < n % 8 && i < len)
    {
      dst[i] = src[i];
      i++;
    }
  longword_ptr = (unsigned long*)(src + i);
  while (i < len && i < n)
    {
      *((unsigned long*)(dst + i)) = *longword_ptr++;
      i += 8;
    }
  return (dst);
}

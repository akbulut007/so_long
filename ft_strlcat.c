/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <muhakbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:01:05 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 18:01:07 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dst, const char *src, size_t size_dst, size_t val)
{
	size_t	i;

	i = 0;
	while (src[i] && i < val - 1)
	{
		dst[size_dst] = src[i];
		i++;
		size_dst++;
	}
	dst[size_dst] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_dst;
	size_t	size_dst_val;
	size_t	size_src;
	size_t	val;

	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	size_dst_val = size_dst;
	if (size_dst_val >= dstsize)
		return (dstsize + size_src);
	val = dstsize - size_dst;
	ft_strcpy(dst, src, size_dst, val);
	return (size_dst_val + size_src);
}

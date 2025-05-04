/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:58:11 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:58:14 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr1 = dest;
	ptr2 = src;
	while (n > 0)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		n--;
	}
	return (dest);
}

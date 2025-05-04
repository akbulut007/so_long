/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:51:33 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:51:38 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	mem_size;

	mem_size = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (mem_size / nmemb != size)
		return (NULL);
	ptr = malloc(mem_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, mem_size);
	return (ptr);
}

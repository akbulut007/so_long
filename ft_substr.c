/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <muhakbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:02:01 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 18:02:03 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	length;
	size_t	end;

	length = ft_strlen(s);
	end = 0;
	if (start < length)
		end = length - start;
	if (len < end)
		end = len;
	ptr = malloc(end + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < end)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

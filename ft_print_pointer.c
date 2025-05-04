/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:48:33 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:48:37 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_length(uintptr_t address, int length)
{
	while (address > 0)
	{
		address /= 16;
		length++;
	}
	return (length);
}

static char	*reverse_str(char *ptr, int length)
{
	char	temp;
	int		i;
	int		end;

	end = length - 1;
	i = 2;
	while (i < end)
	{
		temp = ptr[i];
		ptr[i] = ptr[end];
		ptr[end] = temp;
		i++;
		end--;
	}
	ptr[length] = '\0';
	return (ptr);
}

static char	*ft_putptr(uintptr_t val, char *ptr, int length)
{
	int	modulo;

	while (val >= 16)
	{
		modulo = val % 16;
		if (modulo <= 9)
			ptr[length++] = modulo + '0';
		else
			ptr[length++] = modulo - 10 + 'a';
		val /= 16;
	}
	if (val <= 9)
		ptr[length++] = val + '0';
	else
		ptr[length++] = val - 10 + 'a';
	ptr = reverse_str(ptr, length);
	return (ptr);
}

static int	zero_case(char *ptr)
{
	int		str_size;
	char	*s;
	int		i;

	i = 0;
	s = "(nil)";
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	ft_print_str(ptr);
	str_size = ft_strlen_pf(ptr);
	free(ptr);
	return (str_size);
}

int	ft_print_pointer(void *val)
{
	uintptr_t	address;
	char		*ptr;
	int			length;
	int			str_size;

	address = (uintptr_t)val;
	if (address == 0)
	{
		ptr = malloc(sizeof(char) * 6);
		if (ptr == NULL)
			return (0);
		return (zero_case(ptr));
	}
	length = 2;
	ptr = malloc(sizeof(char) * find_length(address, length) + 3);
	if (ptr == NULL)
		return (0);
	ptr[0] = '0';
	ptr[1] = 'x';
	ptr = ft_putptr(address, ptr, length);
	ft_print_str(ptr);
	str_size = ft_strlen_pf(ptr);
	free(ptr);
	return (str_size);
}

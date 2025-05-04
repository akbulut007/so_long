/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_undec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:48:50 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:48:53 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_length(unsigned int num)
{
	int	count;

	if (num == 0)
		count = 1;
	else
	{
		count = 0;
		while (num > 0)
		{
			num /= 10;
			count++;
		}
	}
	return (count);
}

static char	*reverse_str(char *s, int i)
{
	char	temp;
	int		j;
	int		end;

	end = i - 1;
	j = 0;
	while (j < end)
	{
		temp = s[j];
		s[j] = s[end];
		s[end] = temp;
		j++;
		end--;
	}
	s[i] = '\0';
	return (s);
}

static int	zero_case(void)
{
	int		str_size;
	char	*ptr;

	ptr = malloc(sizeof(char) * 2);
	ptr[0] = '0';
	ptr[1] = '\0';
	ft_print_str(ptr);
	str_size = ft_strlen_pf(ptr);
	free(ptr);
	return (str_size);
}

int	ft_print_undec(unsigned int num)
{
	char	*ptr;
	int		i;
	int		modulo;
	int		str_size;

	if (num == 0)
		return (zero_case());
	ptr = malloc(sizeof(char) * find_length(num) + 1);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (num > 0)
	{
		modulo = num % 10;
		ptr[i] = modulo + '0';
		num /= 10;
		i++;
	}
	ptr = reverse_str(ptr, i);
	ft_print_str(ptr);
	str_size = ft_strlen_pf(ptr);
	free(ptr);
	return (str_size);
}

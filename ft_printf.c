/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:48:00 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:48:03 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	diux_format(int *final_count,
	va_list args, const char *fixed_arg)
{
	if (*fixed_arg == 'd' || *fixed_arg == 'i')
		*final_count += ft_print_dec(va_arg(args, int));
	else if (*fixed_arg == 'u')
		*final_count += ft_print_undec(va_arg(args, unsigned int));
	else if (*fixed_arg == 'x')
		*final_count += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (*fixed_arg == 'X')
		*final_count += ft_print_hex_upper(va_arg(args, unsigned int));
}

static void	csp_formats(int *final_count,
	va_list args, const char *fixed_arg)
{
	char	c;

	if (*fixed_arg == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		*final_count += 1;
	}
	else if (*fixed_arg == 's')
		*final_count += ft_print_str(va_arg(args, char *));
	else if (*fixed_arg == 'p')
		*final_count += ft_print_pointer(va_arg(args, void *));
	else if (*fixed_arg == '%')
	{
		c = '%';
		write(1, &c, 1);
		*final_count += 1;
	}
}

int	ft_printf(const char *fixed_arg, ...)
{
	va_list	args;
	int		final_count;

	final_count = 0;
	va_start(args, fixed_arg);
	while (*fixed_arg != '\0')
	{
		if (*fixed_arg == '%')
		{
			fixed_arg++;
			diux_format(&final_count, args, fixed_arg);
			csp_formats(&final_count, args, fixed_arg);
		}
		else
		{
			write(1, fixed_arg, 1);
			final_count++;
		}
		fixed_arg++;
	}
	va_end(args);
	return (final_count);
}

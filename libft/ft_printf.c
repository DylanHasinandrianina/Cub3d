/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:49:56 by mgodawat          #+#    #+#             */
/*   Updated: 2025/04/17 19:04:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int	print_format(char c, va_list args)
{
	int	total_print;

	total_print = 0;
	if (c == 'd' || c == 'i')
		total_print += print_dec(va_arg(args, int));
	else if (c == 'c')
		total_print += print_char(va_arg(args, int));
	else if (c == 's')
		total_print += print_str(va_arg(args, char *));
	else if (c == 'p')
		total_print += print_ptr(va_arg(args, void *));
	else if (c == 'u')
		total_print += print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		total_print += print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		total_print += print_char('%');
	return (total_print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		total_print;

	total_print = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			total_print += print_format(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			total_print++;
		}
		i++;
	}
	va_end(args);
	return (total_print);
}

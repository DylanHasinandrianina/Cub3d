/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:54:07 by mgodawat          #+#    #+#             */
/*   Updated: 2025/04/17 19:02:16 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hex(unsigned int deci)
{
	int	count;

	count = 0;
	if (deci == 0)
		return (1);
	while (deci > 0)
	{
		deci = deci / 16;
		count++;
	}
	return (count);
}

char	*dec_to_hex(unsigned int dec, const char format)
{
	char	*hex_base;
	char	*hex;
	int		i;
	int		len;

	if (format == 'x')
		hex_base = "0123456789abcdef";
	else if (format == 'X')
		hex_base = "0123456789ABCDEF";
	len = len_hex(dec);
	hex = malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (NULL);
	i = len;
	hex[i--] = '\0';
	if (dec == 0)
		hex[i--] = '0';
	while (dec > 0)
	{
		hex[i--] = hex_base[dec % 16];
		dec /= 16;
	}
	return (hex);
}

int	print_hex(unsigned int dec, const char format)
{
	char	*hex_of_dec;
	int		len;

	hex_of_dec = dec_to_hex(dec, format);
	len = ft_strlen(hex_of_dec);
	if (hex_of_dec)
	{
		ft_putstr_fd(hex_of_dec, 1);
		free(hex_of_dec);
	}
	return (len);
}

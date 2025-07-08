/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:54:12 by mgodawat          #+#    #+#             */
/*   Updated: 2025/04/17 19:02:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hex_ptr(uintptr_t deci)
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

char	*dec_to_hex_ptr(void *ptr)
{
	uintptr_t	adresse;
	char		*hex_base;
	char		*hex;
	int			i;
	int			len;

	adresse = (uintptr_t)ptr;
	len = len_hex_ptr(adresse);
	hex_base = "0123456789abcdef";
	hex = malloc(len + 3);
	if (!hex)
		return (NULL);
	i = len + 2;
	hex[i--] = '\0';
	if (adresse == 0)
		hex[i--] = '0';
	while (adresse > 0)
	{
		hex[i--] = hex_base[adresse % 16];
		adresse /= 16;
	}
	hex[i--] = 'x';
	hex[i] = '0';
	return (hex);
}

int	print_ptr(void *ptr)
{
	char	*adr;
	int		len;

	adr = dec_to_hex_ptr(ptr);
	len = ft_strlen(adr);
	if (adr)
	{
		ft_putstr_fd(adr, 1);
		free(adr);
	}
	return (len);
}

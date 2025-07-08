/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:54:17 by mgodawat          #+#    #+#             */
/*   Updated: 2025/04/17 19:04:31 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nbr(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*utoa;

	len = count_nbr(n);
	utoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!utoa)
		return (NULL);
	utoa[len] = '\0';
	if (n == 0)
		utoa[0] = '0';
	while (n != 0)
	{
		utoa[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (utoa);
}

int	print_unsigned(unsigned int num)
{
	char	*num_str;
	int		len;

	num_str = ft_utoa(num);
	len = ft_strlen(num_str);
	if (num_str)
	{
		ft_putstr_fd(num_str, 1);
		free(num_str);
	}
	return (len);
}

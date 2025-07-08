/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:36:43 by shasinan          #+#    #+#             */
/*   Updated: 2025/04/17 19:03:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(int n)
{
	int	count;

	count = 0;
	if (n == 0 || n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*itoa;
	long	nb;

	nb = n;
	len = count_nbr(nb);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (nb == 0)
		itoa[0] = '0';
	if (nb < 0)
	{
		itoa[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		itoa[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (itoa);
}

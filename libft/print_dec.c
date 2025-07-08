/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:54:03 by mgodawat          #+#    #+#             */
/*   Updated: 2025/04/17 19:01:47 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(int num)
{
	char	*num_str;
	int		len;

	num_str = ft_itoa(num);
	len = ft_strlen(num_str);
	if (num_str)
	{
		ft_putstr_fd(num_str, 1);
		free(num_str);
	}
	return (len);
}

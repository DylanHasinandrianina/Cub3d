/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:01:13 by mgodawat          #+#    #+#             */
/*   Updated: 2025/04/17 19:01:14 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	n_len = 0;
	while (needle[n_len] != '\0')
		n_len++;
	if (n_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i + n_len <= len)
	{
		j = 0;
		while (j < n_len && haystack[i + j] == needle[j])
		{
			j++;
		}
		if (j == n_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

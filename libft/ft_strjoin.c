/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:11:24 by shasinan          #+#    #+#             */
/*   Updated: 2025/04/17 18:53:09 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*join;
	size_t	i;
	size_t	j;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!join)
		return (0);
	i = 0;
	while (i < l1)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < l2)
	{
		join[i++] = s2[j++];
	}
	join[i] = '\0';
	return (join);
}

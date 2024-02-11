/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:50:40 by aabdenou          #+#    #+#             */
/*   Updated: 2024/02/11 18:50:41 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	v;

	i = 0;
	str = (unsigned char *)b;
	v = (unsigned char)c;
	while (i < len)
	{
		str[i] = v;
		i++;
	}
	return (b);
}

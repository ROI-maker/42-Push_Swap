/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:18:47 by sclaeys           #+#    #+#             */
/*   Updated: 2025/04/28 16:46:37 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst || !src)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest < source)
	{
		while (i < n)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dest[n] = source[n];
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[50] = "HelloWorld";
	char str2[50] = "HelloWorld";

	printf("Avant ft_memmove : %s\n", str1);
	ft_memmove(str1 + 5, str1, 5);
	printf("Après ft_memmove : %s\n", str1);

	printf("Avant vrai memmove : %s\n", str2);
	memmove(str2 + 5, str2, 5);
	printf("Après vrai memmove : %s\n", str2);

	return 0;
}
*/
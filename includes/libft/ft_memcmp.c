/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:47:45 by sclaeys           #+#    #+#             */
/*   Updated: 2025/03/31 09:18:02 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		n--;
		str1++;
		str2++;
	}
	return (0);
}

/*
#include <stdio.h>

int main()
{
	char *s1 = "abcd";
	char *s2 = "abd";
	printf("%d\n", ft_memcmp(s1, s2, 4));
	
	char *s3 = "abcd";
	char *s4 = "abd";
	printf("%d\n", ft_memcmp(s3, s4, 2));

	char *s5 = "abc";
	char *s6 = "abc";
	printf("%d\n", ft_memcmp(s5, s6, 4));

	char *s7 = "";
	char *s8 = "abc";
	printf("%d\n", ft_memcmp(s7, s8, 4));
}
*/

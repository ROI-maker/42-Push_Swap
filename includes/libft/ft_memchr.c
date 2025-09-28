/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:47:33 by sclaeys           #+#    #+#             */
/*   Updated: 2025/03/31 09:00:19 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *) str;
	while (n > 0)
	{
		if (*s1 == (unsigned char)c)
		{
			return ((void *)s1);
		}
		s1++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
	char *s1 = "hello world!";
	char *s2 = "";
	char *result;

	result = ft_memchr(s1, 'w', 12);
	printf("%s\n", result);

	result = ft_memchr(s1, 'x', 12);
	if (result)
		printf("%s\n", result);

	result = ft_memchr(s2, 'w', 5);
	if (result)
		printf("%s\n", result);
}
*/

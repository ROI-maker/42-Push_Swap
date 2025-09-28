/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:44 by sclaeys           #+#    #+#             */
/*   Updated: 2025/05/04 17:57:28 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && (i + j) < len)
		{
			j++;
		}
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
	char *res;

	res = ft_strnstr("Hello World", "World", 11);
	if (res)
		printf("Test 1: %s\n", res);
	else
		printf("Test 1: (NULL)\n");

	res = ft_strnstr("Hello World", "World", 5);
	if (res)
		printf("Test 2: %s\n", res);
	else
		printf("Test 2: (NULL)\n");

	res = ft_strnstr("Hello", "", 5);
	if (res)
		printf("Test 3: %s\n", res);
	else
		printf("Test 3: (NULL)\n");

	return 0;
}
*/

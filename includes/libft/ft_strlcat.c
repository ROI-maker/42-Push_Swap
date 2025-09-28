/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:30 by sclaeys           #+#    #+#             */
/*   Updated: 2025/05/04 17:42:08 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	i;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (src_size + size);
	i = 0;
	while (i < size - dst_size - 1 && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}

/*
#include <stdio.h>
#include <string.h>

void	run_test(const char *init_dst, const char *src, size_t size)
{
	char buffer[50];

	memset(buffer, 0, sizeof(buffer));
	strcpy(buffer, init_dst);

	size_t ret = ft_strlcat(buffer, src, size);

	printf("==== TEST ====\n");
	printf("dst init : \"%s\"\n", init_dst);
	printf("src      : \"%s\"\n", src);
	printf("size     : %zu\n", size);
	printf("result   : \"%s\"\n", buffer);
	printf("return   : %zu\n\n", ret);
}

int	main(void)
{
	run_test("Hello", " World", 20);   // assez de place
	run_test("Hello", " World", 10);   // pile la place
	run_test("Hello", " World", 5);    // pas assez de place
	run_test("", "Salut", 10);         // dst vide
	run_test("Bonjour", "", 10);       // src vide
	run_test("", "", 10);              // les deux vides
	run_test("123456789", "abc", 10);  // overflow
	run_test("yo", "lo", 0);           // size = 0
	run_test("yo", "lo", 2);           // size < len(dst)

	return 0;
}
*/

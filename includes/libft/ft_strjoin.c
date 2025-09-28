/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:26 by sclaeys           #+#    #+#             */
/*   Updated: 2025/05/04 17:27:42 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	dest_size;

	if (!s1 && !s2)
		return (ft_calloc(1, 1));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	else
		dest_size = (ft_strlen(s1) + ft_strlen(s2));
	dest = malloc(sizeof(char) * (dest_size + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, dest_size + 1);
	ft_strlcat(dest, s2, dest_size + 1);
	return (dest);
}

/*
#include <stdio.h>

int main()
{
	char *s1 = "Hello ";
	char *s2 = "World!";

	printf("%s\n", ft_strjoin(s1, s2));

	char *s3 = "Hello ";
	char *s4 = NULL;

	printf("%s\n", ft_strjoin(s3, s4));

	char *s5 = NULL;
	char *s6 = "World!";

	printf("%s\n", ft_strjoin(s5, s6));

	char *s7 = NULL;
	char *s8 = NULL;

	printf("%s\n", ft_strjoin(s7, s8));
}
*/

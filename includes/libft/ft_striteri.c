/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:23 by sclaeys           #+#    #+#             */
/*   Updated: 2025/05/04 17:25:43 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	test_function(unsigned int i, char *c)
{
	*c = *c - 32;
}

int	main(void)
{
	char str[] = "hello";

	printf("Avant : %s\n", str);
	ft_striteri(str, test_function);
	printf("Après : %s\n", str);
	return (0);
}
*/

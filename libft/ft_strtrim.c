/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:52:26 by carmelag          #+#    #+#             */
/*   Updated: 2023/10/18 18:32:07 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	find_start(char *s1, char *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (in_set(s1[i], set) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

int	find_end(char *s1, char *set, int start)
{
	int	i;

	i = ft_len(s1);
	while (i > start)
	{
		if (in_set(s1[i - 1], set) == 1)
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	start = find_start((char *)s1, (char *)set);
	end = find_end((char *)s1, (char *)set, start);
	str = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	const char    *s1 = "lorem ipsum dolor sit amet";
	const char    *set = "te";

    printf("%s", ft_strtrim(s1, set));
    return (0);
}*/

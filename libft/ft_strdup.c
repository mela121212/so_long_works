/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:59:37 by carmelag          #+#    #+#             */
/*   Updated: 2023/10/02 16:07:22 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (*dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		tam;

	tam = ft_strlen(src);
	dest = (char *)malloc(sizeof(*dest) * tam + 1);
	if (!(dest))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

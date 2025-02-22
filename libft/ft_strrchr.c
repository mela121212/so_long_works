/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:05 by carmelag          #+#    #+#             */
/*   Updated: 2023/10/20 13:35:52 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	a;
	int		i;

	a = c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == a)
			return ((char *)(&str[i]));
		i--;
	}
	return (0);
}

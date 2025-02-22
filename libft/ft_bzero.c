/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:36:59 by carmelag          #+#    #+#             */
/*   Updated: 2023/09/12 16:58:12 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*p;

	p = (char *)str;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

/*Esta función es útil cuando necesitas asegurarte de que cierta parte 
de la memoria de la computadora esté limpia y lista para usar, 
como cuando creas una lista o un archivo nuevo.*/

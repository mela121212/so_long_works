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

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	else
	{
		ft_bzero(result, (count * size));
		return (result);
	}
}
/*malloc: se utiliza cuando solo necesitas asignar memoria y 
no te importa inicializar los valores manualmente.

calloc: se utiliza cuando deseas asignar memoria y asegurarte de 
que todos los valores estén inicializados en cero desde el 
principio, lo que es útil en situaciones donde los valores 
iniciales cero son importantes, como al trabajar con arreglos o 
estructuras.*/
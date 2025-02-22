/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:05 by carmelag          #+#    #+#             */
/*   Updated: 2023/09/25 13:48:30 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dest);
	}
	while (len--)
		*d++ = *s++;
	return (dest);
}

//maneja las situaciones de solapamiento (copia segura)
//Si las áreas se solapan (caso src < dst), 
//copia los bytes de atrás hacia adelante para evitar 
//sobrescribir datos antes de que se hayan copiado.
//si no se solapan copia de adelante a atras

/*int main(void)
{
    size_t len = 10;
    char src[] = "Hello";
    char dest[10];

    ft_memmove(dest, src, len);
    printf("%s", dest);

    return 0;
}*/
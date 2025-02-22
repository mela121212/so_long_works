/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:00:38 by carmelag          #+#    #+#             */
/*   Updated: 2023/10/18 17:21:34 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(long nbr)
{
	int		len;

	len = 1;
	if (nbr < 0)
		len++;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	ft_fill(char *result, int *i, long nbr)
{
	if (nbr >= 10)
	{
		ft_fill(result, i, nbr / 10);
		ft_fill(result, i, nbr % 10);
	}
	else
	{
		result[*i] = nbr + '0';
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	nbr;

	nbr = n;
	result = (char *) ft_calloc(count_digits(nbr) + 1, 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		result[i++] = '-';
		nbr *= -1;
	}
	ft_fill(result, &i, nbr);
	result[i] = 0;
	return (result);
}

/*int main(void)
{
    int num1 = 12345;
    char *str1 = ft_itoa(num1);
    printf("Número: %d, String: %s\n", num1, str1);
    free(str1);
	return (0);
}*/
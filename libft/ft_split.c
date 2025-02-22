/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmelag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:08:37 by carmelag          #+#    #+#             */
/*   Updated: 2023/10/20 12:07:22 by carmelag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			counter++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free_array(char **aux, int j)
{
	while (j >= 0)
	{
		free(aux[j]);
		j--;
	}
	free(aux);
	return (NULL);
}

static char	**fill_array(char **aux, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			aux[j] = word_dup(s, start, i);
			if (aux[j] == NULL)
				return (ft_free_array(aux, j));
			j++;
		}
		if (s[i])
			i++;
	}
	aux[j] = NULL;
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = fill_array(array, s, c);
	return (array);
}

/*int main(void)
{
    const char s[] = "--1-2--3---4----5-----42";
    char c = '-';
    char **result = ft_split(s, c);

    if (result) {
        int i = 0;
        while (result[i] != NULL) {
            printf("%s\n", result[i]);
            free(result[i]); // Liberar cada cadena asignada dinámicamente
            i++;
        }
        free(result); // Liberar el array de cadenas
    } else {
        printf("Error de asignación de memoria\n");
    }

    return 0;
}*/

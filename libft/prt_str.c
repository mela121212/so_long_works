#include "libft.h"

int	prt_str(char const *str)
{
	if (str == NULL)
		return (write(STDOUT_FILENO, "(null)", 6));
	else
		return (write(STDOUT_FILENO, str, ft_strlen(str)));
}
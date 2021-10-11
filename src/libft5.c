#include "../cub3d.h"

char			*ft_copy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static	size_t	ft_length(char const *s, \
unsigned int star, size_t len)
{
	size_t		i;

	i = 0;
	while (s[star] != '\0' && i < len)
	{
		star++;
		i++;
	}
	return (i);
}

void			ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char			*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			*ft_substr(char const *s, unsigned int star, size_t len)
{
	char		*result;
	size_t		i;
	size_t		j;

	result = NULL;
	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_length(s, star, len) + 1));
	if (!result)
		return (0);
	while (s[i] != '\0' && len > 0)
	{
		if (i >= star)
		{
			result[j] = s[i];
			j++;
			len--;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

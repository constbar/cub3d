#include "../cub3d.h"

int		ft_atoi(const char *str)
{
	int					i;
	int					f;
	unsigned long int	r;

	i = 0;
	r = 0;
	f = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			f = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
		if (r > 2147483647 && f == 1)
			return (-1);
		if (r > 2147483648 && f == -1)
			return (0);
	}
	return (r * f);
}

char	*ft_strstr(char *str, char *find)
{
	int i;

	if (find[0] == '\0')
		return (str);
	while (*str)
	{
		i = 0;
		while (str[i] == find[i] && find[i])
			i++;
		if (find[i] == '\0')
			return (str);
		str++;
	}
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = (unsigned char*)b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *p;

	p = (unsigned char*)s;
	ft_memset(p, '\0', n);
}

void	*ft_calloc(size_t n, size_t size)
{
	void *p;

	p = (void*)malloc(n * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * n);
	return (p);
}

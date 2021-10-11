#include "../cub3d.h"

static	int		ft_numwords(char const *s, char c)
{
	int				words;
	unsigned int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (words);
}

static	void	ft_cancel_arr(char **mass)
{
	while (*mass)
	{
		free(*mass);
		mass++;
	}
	free(mass);
}

static	char	**ft_fill(char **res, int i, char const *s, char c)
{
	int			letters;
	char const	*s2;

	letters = 0;
	s2 = s;
	while (*s && *s != c)
	{
		letters++;
		s++;
	}
	if (!(res[i] = (char*)ft_calloc(letters + 1, sizeof(char))))
		ft_cancel_arr(res);
	letters = 0;
	while (*s2 && *s2 != c)
	{
		res[i][letters] = *s2;
		letters++;
		s2++;
	}
	return (res);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		numwords;
	char	**final_res;

	if (!s)
		return (NULL);
	numwords = ft_numwords(s, c);
	if (!(final_res = (char**)ft_calloc(numwords + 1, sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			while (*s && *s == c)
				s++;
		else
		{
			final_res = ft_fill(final_res, i, s, c);
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	return (final_res);
}

char			*ft_strdup(const char *s)
{
	size_t	l;
	size_t	i;
	char	*new;

	l = 0;
	i = 0;
	while (s[l])
		l++;
	new = (char*)malloc(l * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (i < l)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

#include "../cub3d.h"

static	char		*ft_search(const char *s, int c)
{
	char	*p;

	p = (char*)s;
	while (*p && *p != c)
		p++;
	if (*p == c)
		return (p);
	return (NULL);
}

static	char		*ft_duplicate(const char *s)
{
	size_t	i;
	size_t	k;
	char	*new;

	i = 0;
	k = ft_strlen(s);
	new = (char*)malloc((k + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < k)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char			*check_pn(char **remains, char **line)
{
	char	*new_pn;

	new_pn = NULL;
	if (!*remains)
	{
		*line = ft_duplicate("");
		return (NULL);
	}
	if ((new_pn = ft_search(*remains, '\n')))
	{
		*new_pn = '\0';
		new_pn++;
		*line = ft_duplicate(*remains);
		ft_copy(*remains, new_pn);
	}
	else
	{
		*line = ft_duplicate(*remains);
		if (*remains)
		{
			free(*remains);
			*remains = NULL;
		}
	}
	return (new_pn);
}

static	char		*ft_concat(char const *s1, char const *s2)
{
	char	*p;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	p = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

int					get_next_line(int fd, char **line)
{
	char			buf[3 + 1];
	static	char	*remains[128];
	char			*temp;
	char			*pn;
	int				bwr;

	if (!line || fd < 0 || fd > 127 || 3 < 1
	|| read(fd, buf, 0) == -1)
		return (-1);
	pn = check_pn(&remains[fd], line);
	while (!pn && (bwr = read(fd, buf, 3)))
	{
		buf[bwr] = '\0';
		if ((pn = ft_search(buf, '\n')))
		{
			*pn = '\0';
			remains[fd] = ft_duplicate(++pn);
		}
		temp = *line;
		if (!(*line = ft_concat(*line, buf)))
			return (-1);
		free(temp);
		temp = NULL;
	}
	return (pn ? 1 : 0);
}

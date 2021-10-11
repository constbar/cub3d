#include "../cub3d.h"

void	wtf(char letter)
{
	ft_putstr("Error\n");
	letter == 'a' ? ft_putstr(NF1) : 0;
	letter == 'b' ? ft_putstr(NF4) : 0;
	letter == 'c' ? ft_putstr(NF3) : 0;
	letter == 'd' ? ft_putstr(NF6) : 0;
	letter == 'e' ? ft_putstr(NF7) : 0;
	letter == 'f' ? ft_putstr(NF5) : 0;
	letter == 'g' ? ft_putstr(NF8) : 0;
	letter == 'h' ? ft_putstr(NF9) : 0;
	letter == 'i' ? ft_putstr(NF12) : 0;
	letter == 'j' ? ft_putstr(NF10) : 0;
	letter == 'k' ? ft_putstr(NF11) : 0;
	letter == 'l' ? ft_putstr(NF13) : 0;
	letter == 'm' ? ft_putstr(NF14) : 0;
	letter == 'n' ? ft_putstr(NF15) : 0;
	letter == 'o' ? ft_putstr(NF16) : 0;
	letter == 'p' ? ft_putstr(NF17) : 0;
	letter == 'r' ? ft_putstr(NF18) : 0;
	letter == 's' ? ft_putstr(NF19) : 0;
	letter == 't' ? ft_putstr(NF20) : 0;
	letter == 'x' ? ft_putstr(NF21) : 0;
	letter == 'y' ? ft_putstr(NF22) : 0;
	letter == 'q' ? ft_putstr(NF23) : 0;
	letter == 'z' ? ft_putstr(NF24) : 0;
	exit(EXIT_FAILURE);
}

void	suc(char letter)
{
	letter == 'z' ? ft_putstr(NF2) : 0;
	exit(EXIT_SUCCESS);
}

void	free_mem(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	if (n == 0)
		return (0);
	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (ps1[i] && ps2[i] && i < (n - 1))
	{
		if (ps1[i] != ps2[i])
			break ;
		i++;
	}
	return (ps1[i] - ps2[i]);
}

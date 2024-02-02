#include "so_long.h"

static int	ft_len(int nb)
{
	int			i;
	long int	n;

	i = 0;
	n = nb;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	num;
	int			i;
	char		*p;

	num = n;
	i = ft_len(num);
	p = (char *)malloc(i + 1);
	if (p == NULL)
		return (NULL);
	p[i] = '\0';
	if (num == 0)
		p[0] = '0';
	if (num < 0)
	{
		p[0] = '-';
		num *= -1;
	}
	i--;
	while (num > 0)
	{
		p[i] = (num % 10) + 48;
		i--;
		num /= 10;
	}
	return (p);
}
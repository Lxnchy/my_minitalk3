#include <stdio.h>
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*res;
	size_t			i;

	i = -1;
	res = (unsigned char *)s;
	while (++i < n)
		res[i] = '\0';
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	ovcheck;
	void	*res;

	ovcheck = size * nmemb;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (ovcheck / nmemb != size)
		return (0);
	res = malloc(nmemb * size);
	if (!res)
		return (0);
	ft_bzero(res, nmemb * size);
	return (res);
}

static int	*charbit(int c)
{
	int		*bits;
	int		i;

	i = -1;
	bits = ft_calloc(9, 1);
	while (++i < 9 && c)
	{
		bits[8 - i] = c%2;
		c /= 2;
	}
	return (bits);
}

static void	readbit(int *b)
{
	int		res;
	int		i;

	i = -1;
	res = 0;
	while (++i < 9)
		res = res * 2 + b[i];
	printf("\n%d\n\n", res);
	return ;
}

int	main(int ac, char **av)
{
	int i = -1;
	int	*res = charbit(97);
	while (++i < 9)
	{
		printf("%d", res[i]);
	}
	readbit(res);
	return (1);
}

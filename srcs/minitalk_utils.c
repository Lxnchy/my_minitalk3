/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:47:14 by jehubert          #+#    #+#             */
/*   Updated: 2022/12/01 17:52:23 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*res;
	size_t			i;

	i = -1;
	res = (unsigned char *)s;
	while (++i < n)
		res[i] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	totlen;

	if (!s1 || !s2)
		return (NULL);
	totlen = ft_strlen(s1) + ft_strlen(s2);
	res = ft_calloc(sizeof(char), (totlen + 1));
	if (!res)
		return (NULL);
	ft_strlcat(res, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(&res[ft_strlen(s1)], (char *)s2, ft_strlen(s2) + 1);
	return (res);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!src)
		return (0);
	j = ft_strlen(src);
	if (!dest || size == 0)
		return (j);
	i = ft_strlen(dest);
	k = 0;
	if (size <= i)
		j = j + size;
	else
		j = j + i;
	while (i + 1 < size && src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	if (i < size)
		dest[i] = '\0';
	return (j);
}
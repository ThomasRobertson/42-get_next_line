/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:57:53 by troberts          #+#    #+#             */
/*   Updated: 2022/05/11 16:54:05 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*desttmp;
	size_t	i;

	if (dest == NULL && src == NULL)
	{
		return (dest);
	}
	i = 0;
	desttmp = dest;
	while (i < n)
	{
		*(unsigned char *)desttmp = *(unsigned char *)src;
		i++;
		desttmp++;
		src++;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	void	*stmp;

	stmp = s;
	while (n > 0)
	{
		*((unsigned char *)stmp) = c;
		stmp++;
		n--;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

static char	*ft_strncpy_static(char *dest, const char *src, size_t n)
{
	ft_bzero((void *)dest, n);
	if (ft_strlen(src) < n)
		ft_memcpy(dest, src, ft_strlen(src));
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size > len_src)
	{
		dst = ft_strncpy_static(dst, src, len_src);
		dst[len_src] = 0;
	}
	else
	{
		dst = ft_strncpy_static(dst, src, (size - 1));
		dst[size - 1] = 0;
	}
	return (len_src);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = 0;
	return (str);
}

static char	*ft_strcpy_static(char *dest, const char *src)
{
	ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}

static char	*ft_strnew_static(size_t size)
{
	char	*str;

	str = malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (size > 0)
	{
		str[size] = 0;
		size--;
	}
	str[0] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	char	*ptr;

	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew_static(len);
	ptr = str;
	if (str == NULL)
		return (NULL);
	ptr = ft_strcpy_static(ptr, s1);
	ptr = ptr + ft_strlen(s1);
	ptr = ft_strcpy_static(ptr, s2);
	return (str);
}

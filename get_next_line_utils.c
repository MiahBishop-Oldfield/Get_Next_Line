/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:51:45 by mbishop-          #+#    #+#             */
/*   Updated: 2022/02/07 11:09:27 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

/* This function takes a string as an argument and counts 
 * the length of the string up to (but not including) the 
 * null terminator.
 * size_t is used here because it is an unsigned data type,
 * meaning it cannot represent any negative values. As we
 * are counting the length of a string, we know the result 
 * will always be at least zero. This is because even an 
 * empty string will have a null terminator which is still
 * counted as an element and thus gives a length of zero.*/

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (start > ft_strlen(str) || len == 0)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (str[start + i] != '\0' && i < len)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* Beginning at the index 'start' and finishing at maximum
 * size 'len', this function allocates and returns a 
 * substring from the given string */

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}

/* Searches for and returns a pointer to the first 
 * occurrence of c in the string. If this character is
 * not found, return NULL. */

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*newstr;

	i = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/* Allocates sufficient memory to hold the string (including
 * NULL terminator) and copies the old string to the new 
 * string and returns a pointer to the new address. */

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

/* Allocates and returns a new string that is the result of
 * s1 and s2 combined.*/

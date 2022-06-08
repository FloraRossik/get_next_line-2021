#include "get_next_line.h"

size_t     ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strcpy(char *dest, const char *src)
{
	int i;
	
	i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *ft_strcat(char *dest, const char *src)
{
    int i;
    int j;

	i = 0;
	j = 0;
while (dest[i] != '\0')
{
    i++;
}
while (src[j] != '\0')
{
    dest[i + j] = src[j];
    j++;
}
	dest[i + j] = '\0';
return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(* new_str) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strcpy(new_str, s1);
	ft_strcat(new_str, s2);
	return (new_str);
}

char    *ft_strdup(const char *s1)
{
    size_t  len;
    char    *str;
    char    *tmp;

    len = ft_strlen((char *)s1);
    str = malloc(len+1);
    if (str == NULL)
            return (NULL);
    tmp = str;
    while(*s1 != '\0')
    {
		*str++ = *s1++;    
    }
    *str = '\0';
    return (tmp);
}

char    *ft_strchr(const char *s, int c)
{
	char		*s1;

	s1 = (char *)s;

    while (*s1 != '\0')
    {
		if (*s1 == ((char )c))
			return (s1);
		s1++;
	}
    if (c == '\0')
		return (s1);
	return (NULL);
}
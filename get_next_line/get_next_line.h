#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdio.h>
# include <fcntl.h> //open
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFER_SIZE
#	define BUFER_SIZE 42
# endif

char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcpy(char *dest, const char *src);
size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
char		*ft_strcat(char *dest, const char *src);

#endif
#include "get_next_line.h"

char	*chek_rest(char **rest, char **line)
{
	char *p_n;
	char *tmp;

	p_n = NULL;
	tmp = NULL;
	if (*rest)
	{
		if ((p_n = ft_strchr(*rest, '\n'))) 
		{
			*p_n = '\0';
			p_n++;
			*line = ft_strdup(*rest);
			if (*p_n)
				tmp = ft_strdup(p_n);
		}
		else
			*line = ft_strdup(*rest); 
		free(*rest);
		*rest = tmp;
	}
	return (p_n); 
}

char		*get_next_line(int fd)
{
	static char		*rest;
	char			*line;
	char			*buf;
	int				byte_read;
	char			*p_n;
	char			*tmp;

	line = NULL;
	buf = (char *)malloc(sizeof(*buf) * (BUFER_SIZE + 1));
	if (fd < 0 || BUFER_SIZE < 1 ||read(fd, 0, 0) < 0)
			return (NULL);
	p_n = chek_rest(&rest, &line);
	byte_read = BUFER_SIZE;
	while (!p_n && (byte_read = read(fd, buf, BUFER_SIZE)) > 0) 
	{
		if (line == NULL)
			line = ft_strdup("");
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			rest = ft_strdup(p_n);
		}
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
	}
	return (line);
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
}
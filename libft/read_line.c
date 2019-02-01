#include <unistd.h>
#include "libft.h"

static int	read_line(const int fd, char **line, int count)
{
  char	tmp[2];
  char	*deltmp;
  int	ret;

  while((ret = read(fd, tmp, 1)) > 0 && *tmp != '\n' && *tmp)
    {
      tmp[1] = 0;
      count++;
      if (count == 1000)
	{
	  ft_putendl("(Map is too big !)");
	  return (-1);
	}
      if(*tmp != 'x' && *tmp != ' ' && *tmp != 'o')
	return (-1);
      deltmp = *line;
      if (!(*line = ft_strjoin(*line, tmp)))
	return (-1);
      ft_strdel(&deltmp);
    }
  if (ret < 0)
    return (-1);
  if (ret == 0 || *tmp == 0)
    return (0);
  return (1);
}

int		get_line(const int fd, char **line)
{
  int	count;

  count = 0;
  if (fd < 0)
    return (-1);
  if (!(*line = ft_strnew(0)))
    return (-1);
  return(read_line(fd, line, count));
}

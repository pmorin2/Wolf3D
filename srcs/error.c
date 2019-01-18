#include "wolf3d.h"

void	error_def_map(void)
{
  ft_putendl("Map is invalid !");
  exit(1);
}

void    error_map(t_data *mlx)
{
  free_map(&mlx->map);
  ft_putendl("Map is not surrounded by walls !");
  exit(1);
}

void	small_map(void)
{
  ft_putendl("Map is too small !");
  exit(1);
}

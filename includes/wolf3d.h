/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheuben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:04:44 by cheuben           #+#    #+#             */
/*   Updated: 2019/01/23 15:15:41 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# define WIDTH 812
# define HEIGHT 684
# define UP 126
# define DOWN 125
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define R_RIGHT 124
# define R_LEFT 123
# define MENU_HIDE 4
# define W 13
# define S 1

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixel;
	int				x;
	int				y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			cam_x;
	int				map_x;
	int				map_y;
	double			delta_dis_x;
	double			delta_dis_y;
	int				step_x;
	int				step_y;
	double			side_dis_x;
	double			side_dis_y;
	int				hit;
	int				side;
	double			perp_wall_dis;
	double			line_height;
	int				draw_start;
	int				draw_end;
	int				size_line;
	int				bpp;
	int				endian;
	int				color;
	double			rot;
	double			speed;
	double			t_d;
	double			t_p;
	double			wall_x;
	char			**map;
	char			*name_map;
	int				line;
	int				line_count;
	int				col;
	int				col_count;
	int				test;
	int				fd;
	int				left;
	int				right;
	int				up;
	int				down;
	int				r_left;
	int				r_right;
	int				help_menu;
	char			*line_test;
	char			*l;
	int				i;
}					t_data;

int					exit_program(void);
void				calc_height_line(t_data *data);
void				after_val(t_data *data);
int					hook_after_val(t_data *data, int key);
int					key_hook_left_right(t_data *data);
int					key_hook_r_left_right(t_data *data);
int					key_hook_stop_hit(t_data *data);
int					key_hook(t_data *data);
void				set_pixel(int x, int y, int color, t_data *data);
void				untextured(t_data *data);
void				set_image_untextured(t_data *data);
void				print_map(t_data *data, int x);
void				ray_pos(t_data *data, int x);
void				init(t_data *data);
void				err_exit(char *str, t_data data);
void				usage(void);
int					parsor(t_data *data);
void				free_map(char ***map);
int					key_press(int key, t_data *data);
int					key_release(int key, t_data *data);
void				error_map(t_data *mlx);
int					check_wall(t_data *mlx);
void				small_map(void);
void				error_def_map(void);
#endif

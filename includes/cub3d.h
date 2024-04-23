/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:36:28 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/26 13:55:57 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

# define SOUTH		0
# define NORTH		1

# define WEST		2
# define EAST		3

# define DOOR		4

# define WALK_SPEED	0.128
# define RUN_SPEED	0.3
# define ROT_SPEED	0.075

/*
** Keyboard LETTERS FOR MAC AND LINUX
*/
# if UNAME == 1
#  define KEY_A 	0
#  define KEY_S 	1
#  define KEY_D 	2
#  define KEY_W 	13
#  define KEY_M 	46
#  define KEY_ESC 	53
#  define KEY_SHIFT 257
#  define K_LEFT 	123
#  define K_RIGHT 	124
#  define KEY_SPACE 49
# else
#  define KEY_A		97
#  define KEY_S 	115
#  define KEY_D		100
#  define KEY_W 	119
#  define KEY_M 	46
#  define KEY_ESC 	65307
#  define KEY_SHIFT	65505
#  define K_LEFT 	65361
#  define K_RIGHT 	65363
#  define KEY_SPACE 49
# endif

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}				t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	char			*addr;
	void			*img;
	int				bit_x_pixl;
	int				l_length;
	int				endian;
}			t_mlx;

typedef struct s_map
{
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	char			player_dir;
	int				floor;
	int				ceiling;
	char			**textures;
	char			**matrix;
	int				end;
	int				begin;
}				t_map;

typedef struct s_images
{
	unsigned int		floor;
	unsigned int		ceiling;
	t_mlx				*walls;
	t_mlx				gun;
	t_mlx				bang;
	t_mlx				mmap;
}			t_images;

typedef struct s_raycast
{
	bool	wall_hit;
	bool	side_hit;
	int		line_height;
	int		draw_from;
	int		draw_to;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
	double	tex_wall_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
}			t_raycast;

typedef struct s_cub3d
{
	t_mlx			mlx;
	t_player		player;
	t_map			*map;
	t_images		images;
	t_raycast		raycast;
	char			*filepath;
	int				run;
	int				bang;
	int				minmap;
}				t_cub3d;

/* parse.c */
int				parse_args(int argv, char **argc);

/* init.c */
t_cub3d			*init_cub3d(char *path);

/* main.c */
void			init_game(t_cub3d *cub3d);
int				close_game(t_cub3d *cub);

/* images.c + images_bonus.c*/
t_images		images(t_cub3d *cub3d);

/* error_exit.c */
void			print_error(char *err_msg);

/*  map_1.c + parse_map_bonus.c*/
t_map			*map(char *path);

/* map_2.c*/
void			map_closed(t_map *map);
void			validate_size(t_map *map);

/* player.c */
void			fill_player_vars(t_map *map);
void			validate_player(t_map *map);

/* ceiling_and_floor.c  */
void			fill_color(t_map *map, char *line);

/* map_utils.c */
int				only_matrix(t_map *map);
char			*ft_strtrim2(char *s1, char *set);
int				ft_idos(char *str);

/* vtextures.c */
void			fill_texture(t_map *map, char *line);
void			validate_text(char **textures_arr, t_map *map);

/* game.c */
t_player		init_player(t_cub3d *cub3d);
t_raycast		init_raycast(void);
int				start_game(t_cub3d *cub);

/* hooks.c + hooks_bonus.c */
int				key_press_handler(int keycode, t_cub3d *cub);
int				key_rel_handler(int keycode, t_cub3d *cub);
int				mouse_handler(int button, int x, int y, t_cub3d *cub);

/* move.c + move_bonus.c */
void			move_rotate(int keycode, t_cub3d *cub);
void			move_left_right(int keycode, t_cub3d *cub);
void			move_up_down(int keycode, t_cub3d *cub);
bool			ft_is_wall(float x, float y, t_cub3d *cub);
bool			ft_is_door(float x, float y, t_cub3d *cub);

/* textures.c + textures_bonus.c*/
void			draw_textures(t_cub3d *cub, int x);

/* utils.c */
double			ft_abs(double x);
void			fill(t_mlx *mlx, int color);
void			put_pixel(t_mlx *mlx, int color, int x, int y);
/* raycast.c */
void			raycasting(t_cub3d *cub);

/* gun.c + gun_bonus.c */
int				render(t_cub3d *cub);

/* doors.c */
void			opendoor(t_cub3d *cub);

/* minimap.c */
void			draw_mini_map(t_cub3d *cub);

/* error_exit.c*/
void			print_map_error(char *err_msg, t_map *map);
void			exit_game(t_cub3d *cub, int ext_n);

#endif
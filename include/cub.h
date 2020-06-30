/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:29:26 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/30 16:32:09 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

# define MAP_SCALE 256
# define ANGLE_STEP 4
# define DEPTH 20

# define PI 3.1415

# define ALLOC_ERROR 1
# define INVALID_MAP_ERROR 2
# define TEXTURE_ERROR 3
# define CORRECT_EXIT 4

enum					e_color
{
	r = 16711680,
	g = 65280,
	b = 255
};

typedef struct			s_position
{
	float				dir;
	int					x_pos;
	int					y_pos;
	float				speed;
	float				fov;
}						t_position;

typedef struct			s_identifier
{
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				*s_path;
	int					res[2];
	int					f_color[3];
	int					c_color[3];
	t_uchar				flags;
	t_uchar				save;
	int					map_x_dim;
	int					map_y_dim;
	t_position			*pos;
}						t_identifier;

typedef struct			s_collision_line
{
	float				x0;
	float				y0;
	float				x1;
	float				y1;
	float				x_dir_plane;
	float				y_dir_plane;
	int					a_index;
	int					height;
	unsigned int		color;
	char				side;
}						t_collision_line;

typedef struct			s_tex
{
	void				*img_ptr;
	void				*data_ptr;
	int					sizeline;
	int					bpp;
	int					height;
	int					width;
	int					endian;
}						t_tex;

typedef struct			s_texture
{
	t_tex				*sky;
	t_tex				*floor;
	t_tex				*weapon;
	t_tex				*s;
	t_tex				*so;
	t_tex				*no;
	t_tex				*we;
	t_tex				*ea;
	t_tex				*tmp;
}						t_texture;

typedef struct			s_geometry
{
	float				*bsin;
	float				*bcos;
	float				*btan;
}						t_geomrtry;

typedef struct			s_linker
{
	void				*mlx_ptr;
	void				*win_ptr;
	char				**map;
	void				*img;
	void				*data;
	int					bpp;
	int					endian;
	int					sizeline;
	int					*sprite_dist;
	float				x_sprite_size;
	int					*wall_dist;
	int					sprite_num;
	int					sky_regime;
	int					wall_regime;
	int					floor_regime;
	int					floor_reflection;
	int					gun_regime;
	int					wall_refl;
	t_identifier		*ident;
	t_collision_line	*collision;
	t_texture			*texture;
	t_geomrtry			*g;
}						t_linker;

int						ft_isspaces(int c);
int						refresh_flag(t_identifier *ident, unsigned int flag);
char					*scip_spaces(char *s);
void					set_identifiers(t_identifier *ident);
void					*free_tab(char **tab, int final);
int						tab_length(char **tab);
int						tab_length(char **tab);
int						define_identifier(char *s, t_identifier *ident);
char					**ft_split_spaces(char const *s);
char					**get_map(int argc, char **argv, t_identifier *ident);
int						catch_overflow(char *s);

char					**get_data(int fd);
int						valid_param(int c);
int						check_correct(char **map, t_identifier *ident);
char					**get_final_map(int *params, t_list *lst);

t_linker				*create_linker_struct(t_identifier *ident, char **map);
void					create_image(t_linker *link, int width, int height);
void					initialize_window(t_linker *link);
int						calculate_const(t_linker *link);
void					set_params(t_linker *link);
void					buble_sort(int *arr, t_linker *link);
int						y_sprite_pos(int y, t_linker *link);
int						x_sprite_pos(int x, t_linker *link);
float					metric(int x0, int y0, int x1, int y1);
void					y_span(t_linker *link, float dir);
void					x_span(t_linker *link, float dir);
void					draw_sprite(t_linker *link);
void					*get_pixel_ptr(t_tex *tmp, int x, int y);
void					set_pixel(t_linker *link, int x, int y,
											unsigned int color);
void					draw_weapon(t_linker *link);
void					refresh_plane(t_linker *link);
int						calc_angle_index(float angle);
void					draw_wall(t_linker *link, int x0, int y0);
void					draw_sky(t_linker *link, int x0, int y0);
void					draw_floor_pixel(t_linker *link, int i, int j,
														int up_color);
void					plot_map(t_linker *link);
int						key_event(int key_num, void *s_ptr);
void					move_events(t_linker *link, int key_num);
void					rotate_events(t_linker *link, int key_num);
void					plot_interconnections(t_linker *link);
void					step_out(t_linker *link, float angle);
void					load_textures(t_linker *link);
void					plot_interconnections(t_linker *link);
int						close_event(void *s_ptr);

void					free_link(t_linker *link, int er_num);
void					free_texture(t_linker *link);
void					free_identifiers(t_identifier *ident, int er_num);

#endif

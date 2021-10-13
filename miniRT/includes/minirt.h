
#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# include "mlx.h"

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "scene.h"
# include "vector.h"

typedef struct	s_solution {
	double	inter;
	t_vec	vinter;
	t_vec	norm;
	int		color;
}				t_solution;

void			create_image(t_scene *scene, t_camera *cam);
void			start_image(t_scene *scene);

void			select_cam(t_scene *scene, t_camera **cam);
void			ft_zoom(int z, t_scene *scene);

void			parse_sphere(char *line, t_scene *scene);
void			parse_plane(char *line, t_scene *scene);
void			parse_square(char *line, t_scene *scene);
void			parse_cylinder(char *line, t_scene *scene);
void			parse_triangle(char *line, t_scene *scene);

int				parse_color(char *line, t_scene *scene);
t_vec			parse_coord(char *line, int nov, t_scene *scene);
float			ft_atof(char *str);
int				parsing_skip(char *line, t_scene *scene);
int				parsing_vskip(char *line, t_scene *scene);

void			parse_light(char *line, t_scene *scene);
void			parse_camera(char *line, t_scene *scene);
void			parse_resolution(char *line, t_scene *scene);
void			parse_ambience(char *line, t_scene *scene);

void			parse_line(char *line, t_scene *scene);
void			parse_scene(const char *file, t_scene *scene);

void			add_rays(t_scene *scene);
void			ray_to_pixel(t_camera *cam, int k, int m);

void			ft_error(char *str, t_scene *scene);

void			cust_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_error(char *str, t_scene *scene);
void			free_scene(t_scene *scene);
int				key_hook(int key, t_scene *scene);
int				hook_close(t_scene *scene);

int				trgb(int t, int r, int g, int b);
int				ft_trans(int col);
int				ft_red(int col);
int				ft_green(int col);
int				ft_blue(int col);

int				light_start(t_scene *scene, t_vec *inter,
							t_vec *norm, int obj_col);

void			create_bmp(t_scene *scene, t_camera *cam);

#endif

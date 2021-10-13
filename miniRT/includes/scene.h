
#ifndef SCENE_H
# define SCENE_H

# include "vector.h"
# include "../libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_res {
	int	x;
	int	y;
}				t_res;

typedef struct	s_amb {
	double	light;
	int		col;
}				t_amb;

typedef struct	s_camera {
	t_vec	view_point;
	t_vec	nov;
	int		hfov;

	t_vec	lower_left;
	t_vec	horizontal;
	t_vec	vertical;
}				t_camera;

typedef struct	s_light {
	t_vec	light_point;
	double	br;
	int		col;
}				t_light;

typedef struct	s_sphere {
	t_vec	center;
	double	diam;
	int		col;
}				t_sphere;

typedef struct	s_plane {
	t_vec	coord;
	t_vec	nov;
	int		col;
}				t_plane;

typedef struct	s_square {
	t_vec	center;
	t_vec	nov;
	double	side;
	int		col;
}				t_square;

typedef struct	s_cylinder {
	t_vec	coord;
	t_vec	nov;
	double	diam;
	double	height;
	int		col;
}				t_cylinder;

typedef struct	s_triangle {
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
	int		col;
}				t_triangle;

typedef struct	s_object {
	void	*data;

	int		(*intersect)(void *data, t_vec ray_start,
			t_vec ray, double *intersection);
	int		(*get_color)(void *data);
	t_vec	(*get_normal_vector)(void *data, t_vec ray_start,
			t_vec ray, double intersection);
	void	(*free_data)(void *data);
}				t_object;

typedef struct	s_scene {
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	int		save;

	int		res_full;
	t_res	res;

	int		amb_full;
	t_amb	amb;

	int		cam_nbr;
	t_list	*cam;
	t_list	*light;

	t_list	*obj;
}				t_scene;

int				get_sphere_color(void *data);
t_vec			get_sphere_normal_vector(void *data, t_vec ray_start,
				t_vec ray, double intersection);
int				intersect_sphere(void *data, t_vec ray_start,
				t_vec ray, double *intersection);
void			free_sphere_data(void *data);

int				get_plane_color(void *data);
t_vec			get_plane_normal_vector(void *data, t_vec ray_start,
				t_vec ray, double intersection);
int				intersect_plane(void *data, t_vec ray_start,
				t_vec ray, double *intersection);
void			free_plane_data(void *data);

int				get_triangle_color(void *data);
t_vec			get_triangle_normal_vector(void *data, t_vec ray_start,
				t_vec ray, double intersection);
int				intersect_triangle(void *data, t_vec ray_start,
				t_vec ray, double *intersection);
void			free_triangle_data(void *data);

int				get_square_color(void *data);
t_vec			get_square_normal_vector(void *data, t_vec ray_start,
				t_vec ray, double intersection);
int				intersect_square(void *data, t_vec ray_start,
				t_vec ray, double *intersection);
void			free_square_data(void *data);

int				get_cylinder_color(void *data);
t_vec			get_cylinder_normal_vector(void *data, t_vec ray_start,
				t_vec ray, double intersection);
int				intersect_cylinder(void *data, t_vec ray_start,
				t_vec ray, double *intersection);
void			free_cylinder_data(void *data);

#endif

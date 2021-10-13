
#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec {
	double x;
	double y;
	double z;
}				t_vec;

t_vec			vec_init(double x, double y, double z);
t_vec			vec_add(t_vec v1, t_vec v2);
t_vec			vec_sub(t_vec v1, t_vec v2);
t_vec			vec_nmult(t_vec v1, double a);
t_vec			vec_ndiv(t_vec v1, double a);
double			vec_mscal(t_vec v1, t_vec v2);
t_vec			vec_mvec(t_vec v1, t_vec v2);

t_vec			vec_norm(t_vec *v);
int				is_norm(t_vec v);

#endif

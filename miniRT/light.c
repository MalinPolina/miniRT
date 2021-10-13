
#include "minirt.h"

static int		color_mult(int color, t_vec br)
{
	return (trgb(0, ft_red(color) * br.x,
				ft_green(color) * br.y, ft_blue(color) * br.z));
}

static t_vec	brightness(int color, float ratio)
{
	t_vec br;

	br.x = ft_red(color) * ratio / 255;
	br.y = ft_green(color) * ratio / 255;
	br.z = ft_blue(color) * ratio / 255;
	return (br);
}

static int		color_mix(int color1, int color2)
{
	int	r;
	int	g;
	int	b;

	if ((r = ft_red(color1) + ft_red(color2)) > 255)
		r = 255;
	if ((g = ft_green(color1) + ft_green(color2)) > 255)
		g = 255;
	if ((b = ft_blue(color1) + ft_blue(color2)) > 255)
		b = 255;
	return (trgb(0, r, g, b));
}

static int		is_shadow(t_scene *scene, t_light *light, t_vec *inter)
{
	double		light_inter;
	t_list		*onode;
	t_object	*obj;
	t_vec		tolight;

	onode = scene->obj;
	while (onode)
	{
		light_inter = 0;
		obj = onode->content;
		tolight = vec_sub(light->light_point, *inter);
		if (obj->intersect(obj->data, *inter, vec_norm(&tolight),
							&light_inter))
		{
			if (light_inter < sqrt(vec_mscal(tolight, tolight))
				&& (light_inter > 1))
				return (1);
		}
		onode = onode->next;
	}
	return (0);
}

int				light_start(t_scene *scene, t_vec *inter,
				t_vec *norm, int obj_col)
{
	int		color;
	t_list	*lnode;
	t_light	*light;
	t_vec	tolight;
	double	cosn;

	color = color_mult(obj_col, brightness(scene->amb.col,
			scene->amb.light));
	lnode = scene->light;
	while (lnode)
	{
		light = lnode->content;
		if (!is_shadow(scene, light, inter))
		{
			tolight = vec_sub(light->light_point, *inter);
			cosn = vec_mscal(vec_norm(&tolight), *norm);
			if (cosn > 0)
				color = color_mix(color, color_mult(obj_col,
						brightness(light->col, light->br * cosn)));
		}
		lnode = lnode->next;
	}
	return (color);
}

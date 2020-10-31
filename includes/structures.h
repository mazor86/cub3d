/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:06:19 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 15:02:01 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>
# include "libft.h"
# define TRUE		1
# define FALSE		0
# define EPSILON	0.000001
# define SPOT		1
# define SPHERE		1
# define PLANE		2
# define SQUARE		3
# define CYLINDER	4
# define TRIANGLE	5
# define LEFT		65361
# define RIGHT		65363
# define KEY_S		115
# define ESC		65307
# define PI			3.141592654

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			z;
	double			len;
	double			len2;
}					t_vec;

typedef struct		s_cam
{
	t_vec			pos;
	t_vec			norm;
	double			fov;
	t_vec			rot_fov_x;
	t_vec			rot_fov_y;
}					t_cam;

typedef struct		s_color
{
	int				t;
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_light
{
	int				type;
	t_vec			pos;
	double			intens;
	t_color			color;
}					t_light;

typedef struct		s_inter
{
	double			t;
	t_vec			pos;
	t_vec			norm;
	t_color			color;
}					t_inter;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				screen_x;
	int				screen_y;
	int				w;
	int				h;
	char			*title;
}					t_mlx;

typedef struct		s_cyl_tmp
{
	double			roots[2];
	double			a;
	double			b;
	double			c;
	t_vec			tmp_a;
	t_vec			h;
	t_vec			n;
	t_vec			intersect;
	t_vec			vec_center2inter;
	double			disc;
	t_vec			del_p;
	t_vec			tmp_c;
}					t_cyl_tmp;

typedef struct		s_obj
{
	int				type;
	t_color			color;
	t_vec			center;
	t_vec			norm;
	double			diam;
	double			r;
	double			height;
	t_vec			a;
	t_vec			b;
	t_vec			c;
	t_vec			e1;
	t_vec			e2;
}					t_obj;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size_line;
	int				end;
}					t_img;

typedef struct		s_scene
{
	t_mlx			mlx;
	t_list			*cams;
	int				num_cams;
	t_list			*objs;
	t_list			*lights;
	t_img			**images;
	int				line_error;
	int				scene_error;
	int				is_resol_set;
	int				is_light_set;
	double			amb_intens;
	t_color			amb_color;
	int				i;
}					t_scene;

#endif

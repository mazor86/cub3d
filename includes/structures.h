/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:06:19 by mazor             #+#    #+#             */
/*   Updated: 2020/10/21 00:10:39 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>
# include "libft.h"
# define TRUE 1
# define FALSE 0
# define EPSILON 0.000001

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
	int				fov;
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
	char			*type;
	t_vec			pos;
	double			intens;
	int				color;
}					t_light;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				screen_x;
	int				screen_y;
	int				size_x;
	int				size_y;
	char			*title;
}					t_mlx;

typedef struct		s_scene
{
	t_mlx			mlx;
	t_list			*cams;
	t_list			*objs;
	t_list			*lights;
	int				scene_error;
	int				is_resol_set;
	int				is_light_set;
	double			amb_intens;
	t_color			amb_color;
}					t_scene;

#endif

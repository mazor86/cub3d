#include "temp.h"

void	print_sphere(t_obj obj)
{
	printf("SPHERE\n");
	printf("center: (%.2f, %.2f %.2f)\n", obj.center.x, obj.center.y, obj.center.z);
	printf("diameter = %.2f\n", obj.diam);
	printf("color: %3d %3d %3d\n\n", obj.color.r, obj.color.g, obj.color.b);
}
void	print_plane(t_obj obj)
{
	printf("PLANE\n");
	printf("center: (%.2f, %.2f %.2f)\n", obj.center.x, obj.center.y, obj.center.z);
	printf("normal vect: (%.2f, %.2f %.2f)\n", obj.norm.x, obj.norm.y, obj.norm.z);
	printf("color: %3d %3d %3d\n\n", obj.color.r, obj.color.g, obj.color.b);
	
}

void	print_square(t_obj obj)
{
	printf("SQUARE\n");
	printf("center: (%.2f, %.2f %.2f)\n", obj.center.x, obj.center.y, obj.center.z);
	printf("normal vect: (%.2f, %.2f %.2f)\n", obj.norm.x, obj.norm.y, obj.norm.z);
	printf("side_size = %.2f\n", obj.height);
	printf("color: %3d %3d %3d\n\n", obj.color.r, obj.color.g, obj.color.b);
}

void	print_cylinder(t_obj obj)
{
	printf("CYLINDER\n");
	printf("center: (%.2f, %.2f %.2f)\n", obj.center.x, obj.center.y, obj.center.z);
	printf("normal vect: (%.2f, %.2f %.2f)\n", obj.norm.x, obj.norm.y, obj.norm.z);
	printf("diameter = %.2f\n", obj.diam);
	printf("height = %.2f\n", obj.height);
	printf("color: %3d %3d %3d\n\n", obj.color.r, obj.color.g, obj.color.b);
}

void	print_trianlge(t_obj obj)
{
	printf("TRIANGLE\n");
	printf("point A: (%.2f, %.2f %.2f)\n", obj.a.x, obj.a.y, obj.a.z);
	printf("point B: (%.2f, %.2f %.2f)\n", obj.b.x, obj.b.y, obj.b.z);
	printf("point Z: (%.2f, %.2f %.2f)\n", obj.c.x, obj.c.y, obj.c.z);
	printf("color: %3d %3d %3d\n\n", obj.color.r, obj.color.g, obj.color.b);
	
}
void	ft_print_scene(t_scene *scene)//
{
	t_cam	camera;
	t_light	light;
	t_cam	*cam_ptr;
	t_light	*light_ptr;
	t_obj	obj;
	t_obj	*obj_ptr;

	if (scene->scene_error)
		return ;
	cam_ptr = scene->cams ? (t_cam *)(scene->cams->content) : NULL;
	light_ptr = scene->lights ? (t_light *)(scene->lights->content) : NULL;
	obj_ptr = scene->objs ? (t_obj*)(scene->objs->content) : NULL;
	printf("SCENE\n\n");
	printf("Resolution = %d x %d\n\n", scene->mlx.size_x, scene->mlx.size_y);
	printf("Ambient light:\nintens = %.2f\ncolor: %3d %3d %3d\n\n", scene->amb_intens, scene->amb_color.r, scene->amb_color.g, scene->amb_color.b);
	while (cam_ptr)
	{
		camera = *cam_ptr;
		printf("Cameras:\nposition: (%.2f, %.2f %.2f)\n", camera.pos.x, camera.pos.y, camera.pos.z);
		printf("direction: (%.2f, %.2f %.2f)\n", camera.norm.x, camera.norm.y, camera.norm.z);
		printf("fov: %d\n\n", camera.fov);
		scene->cams = scene->cams->next;
		cam_ptr = scene->cams ? (t_cam *)(scene->cams->content) : NULL;
	}
	while (light_ptr)
	{
		light = *light_ptr;
		printf("Lights\n");
		printf("position: (%.2f, %.2f %.2f)\n", light.pos.x, light.pos.y, light.pos.z);
		printf("intens = %.2f\ncolor: %3d %3d %3d\n\n", light.intens, light.color.r, light.color.g, light.color.b);
		scene->lights = scene->lights->next;
		light_ptr = scene->lights ? (t_light *)(scene->lights->content) : NULL;
	}
	while (obj_ptr)
	{
		obj = *obj_ptr;
		if (obj.type == SPHERE)
			print_sphere(obj);
		if (obj.type == PLANE)
			print_plane(obj);
		if (obj.type == SQUARE)
			print_square(obj);
		if (obj.type == CYLINDER)
			print_cylinder(obj);
		if (obj.type == TRIANGLE)
			print_trianlge(obj);
		scene->objs = scene->objs->next;
		obj_ptr = scene->objs ? (t_obj*)scene->objs->content : NULL;
	}
}
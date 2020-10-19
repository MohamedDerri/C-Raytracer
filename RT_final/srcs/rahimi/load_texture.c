#include "rt.h"

int load_texture(t_rt *rt,t_obj *obj, char *path)
{
	int bpp;
	int size_line;
	int endian;

	obj->txt->img = mlx_xpm_file_to_image(rt->mlx.ptr, path, &obj->txt->w, &obj->txt->h);
	if (!obj->txt->img)
		return (0);
	obj->txt->buf = (int *)mlx_get_data_addr(obj->txt->img, &bpp, &size_line, &endian);
	return (1);
}
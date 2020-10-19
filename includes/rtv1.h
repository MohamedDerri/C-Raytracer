/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 23:59:36 by mderri            #+#    #+#             */
/*   Updated: 2020/03/18 12:57:45 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include "libft.h"
# include "xml.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define FORWARD 3
# define BACK 11
# define PI 3.1415926535
# define ADV ((PI * 60) / 180)
# define MAX 1e30
# define MIN 1e-4
# define MAX_FILE_SIZE 200000
# define SPECULAR_POWER 30
# define MULT_CAMERA_ERROR "Error: multiple cameras are not supported!"
# define CAMERA_NOT_FOUND "Error: Camera cannot be found!"
# define WINDOW_NOT_FOUND "Error: Window cannot be found!"
# define WINDOW_SIZE_ERROR "The window's size is not supported!"
# define MULT_WINDOW_ERROR "Error: multiple windows are not supported!"
# define MULT_NAME_ERROR "Error: multiple names!"
# define SYNTAX_ERROR "Config file: syntax error!"
# define OPEN_ERROR "Open error!"
# define READ_ERROR "Reading error!"
# define INVALID_FOCAL_LENGTH "Focal length is invalid!"
# define INVALID_INTENSITY "Light intensity is invalid!"
# define BIG_FILE_ERROR "File very big for reading!"

typedef enum	e_types
{
	tplane, tsphere, tcylinder, tcone, ttorus, tparaboloid, tellipsoid,
	thyperboloid, tcubet, tmoebius, tdingdong, tgoursat, tteardrop
}				t_types;

typedef struct	s_data
{
	void	*img_ptr;
	int		bpp;
	int		s_l;
	int		endian;
	int		*pic_str;
}				t_data;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		h;
	int		w;
	t_data	d;
}				t_mlx;

typedef struct	s_color
{
	long double	r;
	long double	g;
	long double	b;
}				t_color;

typedef struct	s_vecteur
{
	long double	x;
	long double	y;
	long double	z;
}				t_vecteur;

typedef	struct	s_rayon
{
	t_vecteur	org;
	t_vecteur	direct;
}				t_rayon;

typedef struct	s_light
{
	t_vecteur	org;
	long double	intensity;
	t_color		color;
}				t_light;

typedef struct	s_light_lst
{
	t_light				light;
	struct s_light_lst	*next;
}				t_light_lst;

typedef struct	s_camera
{
	t_vecteur	lookat;
	t_vecteur	position;
	t_vecteur	up;
	t_vecteur	forward;
	t_vecteur	left;
	long double	focal_length;
	long double	frame_width;
	long double	frame_height;
}				t_camera;

typedef	struct	s_sphere
{
	t_vecteur	centre;
	int			rayon;
	t_vecteur	tr;
	t_vecteur	rot;
	t_color		color;
}				t_sphere;

typedef	struct	s_plane
{
	t_vecteur	normal;
	t_vecteur	o;
	t_vecteur	tr;
	t_vecteur	rot;
	t_color		color;
}				t_plane;

typedef struct	s_cylinder
{
	t_vecteur	st;
	t_vecteur	axe;
	int			r;
	t_vecteur	tr;
	t_vecteur	rot;
	t_color		color;
	int			add_cylinder_j;
	char		**s;
}				t_cylinder;

typedef	struct	s_cone
{
	t_vecteur	st;
	t_vecteur	axe;
	long double	k;
	t_vecteur	tr;
	t_vecteur	rot;
	t_color		color;
	int			add_cone_j;
	char		**s;
}				t_cone;

typedef	struct	s_obj
{
	int				type;
	t_color			color;
	t_vecteur		normal;
	t_vecteur		inter;
	void			*obj;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_holders
{
	int		*sh;
	int		*ph;
	int		*ch;
	int		*coh;
	int		*wh;
	int		*cah;
	int		*lgh;
	int		sn;
	int		pn;
	int		cn;
	int		con;
	int		lgn;
	char	**s;
	int		i;
	int		j;
	int		flag;
}				t_holders;

typedef	struct s_coef
{
	long double m;
	long double n;
	long double o;
	long double p;
	long double q;
}				t_coef;

typedef	struct s_torus
{
	t_vecteur centre;
	t_vecteur axe;
	int		  pr;
	int		  gr;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_torus;

typedef	struct s_paraboloid
{
	t_vecteur st;
	t_vecteur axe;
	int		  k;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_paraboloid;

typedef	struct s_ellipsoid
{
	t_vecteur centre;
	t_vecteur axe;
	int		  k;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_ellipsoid;

typedef	struct s_hyperboloid
{
	t_vecteur centre;
	t_vecteur axe;
	int		  k;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_hyperboloid;

typedef	struct s_cubet
{
	t_vecteur centre;
	t_vecteur axe;
	int		  k;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_cubet;

typedef	struct s_moebius
{
	t_vecteur centre;
	t_vecteur axe;
	int		  k;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_moebius;

typedef	struct s_dingdong
{
	t_vecteur centre;
	t_vecteur axe;
	int		  k;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_dingdong;

typedef	struct s_goursat
{
	t_vecteur centre;
	t_vecteur axe;
	int		  k;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_goursat;

typedef	struct s_teardrop
{
	t_vecteur centre;
	t_vecteur axe;
	int		  k;
	t_vecteur tr;
	t_vecteur rot;
	t_color		color;
}				t_teardrop;

/* --------------------------------------------------- */
typedef struct	s_quartic
{
	long double		a;
	long double		b;
	long double		c;
	long double		d;
	long double		z;
	long double		u;
	long double		v;
	long double		sub;
	long double		sq_a;
	long double		p;
	long double		q;
	long double		r;
}				t_quartic;

typedef struct	s_cubic
{
	long double		a;
	long double		b;
	long double		c;
	long double		d;
	long double		sq_a;
	long double		p;
	long double		q;
	long double		cb_p;
}				t_cubic;

# define EQN_EPS     1e-9
# define IS_ZERO(x)	((x) > -EQN_EPS && (x) < EQN_EPS)
# define POW1(x) pow((long double)(x), 1.0/3.0)
# define POW2(x) pow((long double)-(x), 1.0/3.0)

# define CBRT(x) ((x) > 0.0 ? POW1(x) : ((x) < 0.0 ? -POW2(x) : 0.0))


typedef struct	s_rt
{
	t_mlx			m;
	t_holders		h;
	t_obj			*obj_list;
	t_obj			*obj;
	t_obj			*head;
	t_light_lst		*light;
	t_rayon			ray;
	t_vecteur		v1;
	t_camera		cam;
	t_vecteur		u;
	t_color			ambient;
	t_color			diff;
	t_color			spec;
	t_color			color;
	char			*name;
	long double		delta;
	long double		sol1;
	long double		sol2;
	long double		dis;
}				t_rt;

int				cast_object(t_rt *r);
int				cast_shadow(t_rt *r);
int				distances(t_rt *r);
long double		intersection_p(t_rt *r, t_plane *p);
int				intersection_s(t_rt *r, t_sphere *s);
int				intersection_c(t_rt *r, t_cylinder *c);
int				intersection_co(t_rt *r, t_cone *co);
void			get_normal(t_rt *r, t_obj *obj);
int				rat_trace_sphere(t_rt *r, t_obj *obj);
int				rat_trace_plane(t_rt *r, t_obj *obj);
int				rat_trace_cylinder(t_rt *r, t_obj *obj);
int				rat_trace_cone(t_rt *r, t_obj *obj);
void			raytracer(t_rt *r);
void			lighting(t_rt *r);
t_vecteur		sum(t_vecteur v1, t_vecteur v2);
t_vecteur		sub(t_vecteur v1, t_vecteur v2);
t_vecteur		kv(t_vecteur v1, long double k);
long double		dot(t_vecteur v1, t_vecteur v2);
t_vecteur		vcross(t_vecteur v1, t_vecteur v2);
long double		module(t_vecteur v1);
t_vecteur		normalise(t_vecteur v1);
void			free_all(t_rt *r);
int				ft_close(t_rt *r);
int				event_handle(int keycode, t_rt *r);
void			put_error(char *str);
int				rgb(int r, int g, int b);
t_vecteur		create_v(long double x, long double y, long double z);
void			free_splited(char **tab);
int				isdouble(char *str);
int				there_is_sphere(char **tab);
int				there_is_plane(char **tab);
int				there_is_cylinder(char **tab);
int				there_is_cone(char **tab);
int				there_is_light(char **tab);
void			init_sphere_holders(t_holders *h, int n);
void			init_plane_holders(t_holders *h, int n);
void			init_cylinder_holders(t_holders *h, int n);
void			init_cone_holders(t_holders *h, int n);
void			init_light_holders(t_holders *h, int n);
void			init_camera_holders(t_holders *h, int n);
void			init_window_holders(t_holders *h, int n);
void			check_plane_params(t_holders *h);
void			check_cylinder_params(t_holders *h);
void			check_cone_params(t_holders *h);
void			check_light_params(t_holders *h);
void			check_sphere_params(t_holders *h);
void			check_camera_params(t_holders *h);
void			check_window_params(t_holders *h);
int				check_file(char **tab);
int				check_objects(char **tab);
int				check_lights(char **tab);
int				check_spheres(char **tab);
int				check_planes(char **tab);
int				check_cylinders(char **tab);
int				check_cones(char **tab);
void			check_window_params(t_holders *h);
void			create_camera(t_rt *r, char **s, int i);
void			get_window(t_rt *r, char **tab, int i);
int				calculate_lines(char *name);
t_color			c(long double red, long double green, long double blue);
void			parse_plane(t_obj **obj, t_obj **tmp, char **tab, int i);
void			parse_sphere(t_obj **obj, t_obj **tmp, char **tab, int i);
void			parse_cylinder(t_obj **obj, t_obj **tmp, char **tab, int i);
void			parse_cone(t_obj **obj, t_obj **tmp, char **tab, int i);
char			**read_file(char *name);
void			parse3(t_rt *r, char **tab);
t_obj			*parsing(char *file, t_rt *rt);
t_sphere		*add_sphere(char **s, int i);
t_cylinder		*add_cylinder(char **s, int i);
t_plane			*add_plane(char **s, int i);
t_cone			*add_cone(char **s, int i);
t_light			add_light(char **tab, int i);
void			final_color(t_rt *r);
void			ambient(t_rt *r, t_light_lst *lst);
void			diffuse(t_rt *r, long double d, t_light_lst *lst);
void			specular(t_rt *r, long double d, t_vecteur dir, t_light_lst *l);
long double			deg_to_rad(long double angle);
t_vecteur		rotatez(t_vecteur vec, long double angle);
t_vecteur		rotatex(t_vecteur vec, long double angle);
t_vecteur		rotatey(t_vecteur vec, long double angle);
t_vecteur		translation(t_vecteur old_pos, t_vecteur tr);
int				check_file(char **tab);
int				basic_test(char *str);
void			check_format(t_holders *h, char **tab);
void			check_format2(t_holders *h, char **tab);
/*----------------------------------------------------------------------------*/
int				distances2(t_rt *r, long double  c[5]);
int				distances3(t_rt *r, long double  c[4]);
int				intersection_t(t_rt *r, t_torus *t);
int				ft_solve_quartic(long double w[5], long double s[4]);
int				ft_solve_quadric(long double w[3], long double s[2]);
int				ft_solve_cubic(long double w[4], long double s[3]);
int				rat_trace_torus(t_rt *r, t_obj *obj);
void			parse_torus(t_obj **obj, t_obj **tmp);
t_torus			*add_torus(void);
int				shadow_t(t_rt *r, t_obj *obj);
int				intersection_pb(t_rt *r, t_paraboloid *p);
int				rat_trace_paraboloid(t_rt *r, t_obj *obj);
int				shadow_pb(t_rt *r, t_obj *obj);
void			paraboloid_normal(t_rt *r, t_obj *obj);
t_paraboloid	*add_paraboloid(void);
void			parse_paraboloid(t_obj **obj, t_obj **tmp);
int				intersection_ell(t_rt *r, t_ellipsoid *ell);
int				rat_trace_ellipsoid(t_rt *r, t_obj *obj);
void			ellipsoid_normal(t_rt *r, t_obj *obj);
int				shadow_ell(t_rt *r, t_obj *obj);
t_ellipsoid		*add_ellipsoid(void);
void			parse_ellipsoid(t_obj **obj, t_obj **tmp);
int				intersection_hp(t_rt *r, t_hyperboloid *hp);
int				rat_trace_hyperboloid(t_rt *r, t_obj *obj);
void			hyperboloid_normal(t_rt *r, t_obj *obj);
int				cast_shadow(t_rt *r);
void			parse_hyperboloid(t_obj **obj, t_obj **tmp);
t_hyperboloid	*add_hyperboloid(void);
int				intersection_cubet(t_rt *r, t_cubet *ct);
int				rat_trace_cubet(t_rt *r, t_obj *obj);
void			cubet_normal(t_rt *r, t_obj *obj);
int				shadow_cubet(t_rt *r, t_obj *obj);
void			parse_cubet(t_obj **obj, t_obj **tmp);
t_cubet			*add_cubet(void);
int				intersection_moebius(t_rt *r, t_moebius *m);
int				rat_trace_moebius(t_rt *r, t_obj *obj);
void			moebius_normal(t_rt *r, t_obj *obj);
int				shadow_moebius(t_rt *r, t_obj *obj);
void			parse_moebius(t_obj **obj, t_obj **tmp);
t_moebius		*add_moebius(void);
int				intersection_dingdong(t_rt *r, t_dingdong *d);
int				rat_trace_dingdong(t_rt *r, t_obj *obj);
void			dingdong_normal(t_rt *r, t_obj *obj);
int				shadow_dingdong(t_rt *r, t_obj *obj);
void			parse_dingdong(t_obj **obj, t_obj **tmp);
t_dingdong		*add_dingdong(void);
int				intersection_goursat(t_rt *r, t_goursat *g);
int				rat_trace_goursat(t_rt *r, t_obj *obj);
void			goursat_normal(t_rt *r, t_obj *obj);
int				shadow_goursat(t_rt *r, t_obj *obj);
void			parse_goursat(t_obj **obj, t_obj **tmp);
t_goursat		*add_goursat(void);
int				intersection_teardrop(t_rt *r, t_teardrop *td);
int				rat_trace_teardrop(t_rt *r, t_obj *obj);
void			teardrop_normal(t_rt *r, t_obj *obj);
int				shadow_teardrop(t_rt *r, t_obj *obj);
void			parse_teardrop(t_obj **obj, t_obj **tmp);
t_teardrop		*add_teardrop(void);
int				distances4(t_rt *r, long double  c[4], t_moebius *m);
int				in_moebius(t_moebius *m, t_vecteur p);
#endif

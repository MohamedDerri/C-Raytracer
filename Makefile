# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 23:51:03 by mderri            #+#    #+#              #
#    Updated: 2020/10/19 22:16:51 by mderri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# CFLAGS1 = -Wextra -Wall -Werror -I ./minilibx -I ./includes
# CFLAGS2 = -L srcs/libft -lft -I ./includes -I ./minilibx -L ./minilibx -lmlx -framework OpenGL -framework AppKit
# INCS = -I ./frameworks/minilibx_linux -I ./incl/udes
# LIBS = -L ./frameworks/minilibx_linux -lmlx -lXext -lX11 -lm -L ./srcs/libft -lft
INCS = -I ./frameworks/minilibx -I ./includes
LIBS = -L ./frameworks/minilibx -lmlx -L ./srcs/libft -lft -L ./frameworks/zlib -lz -framework OpenGL -framework AppKit
CFLAGS1 = -Wextra -Wall -Werror $(INCS)
NAME = rt

SRC =	tools.c\
		tools2.c\
		tools3.c\
		sphere.c\
		keyhandle.c\
		vecteur_operations.c\
		vecteur_operations2.c\
		cone.c\
		plan.c\
		cylinder.c\
		raytracer.c\
		lighting.c\
		shadow.c\
		get_normals.c\
		transformations.c\
		free_all.c\
		torus.c\
		quartic.c\
		quadric.c\
		cubic.c\
		distance.c\
		elliptic_paraboloid.c\
		ellipsoid.c\
		hyperboloid.c\
		cube_troue.c\
		moebius.c\
		dingdong.c\
		goursat.c\
		tear_drop.c\
		rt.c\
		xml.c\
		xml_tools.c\
		xml_check_file.c\
		xml_print_data.c\
		xml_custom_split.c\
		xml_stock_data.c\
		check_props_per_object.c\
		check_props_per_object_2.c\
		check_rt_props.c\
		get_sphere.c\
		get_plane.c\
		get_cylinder.c\
		get_cone.c\
		get_torus.c\
		get_paraboloid.c\
		get_ellipsoid.c\
		get_cubet.c\
		get_moebius.c\
		push_rt_light.c\
		push_rt_object.c\
		retrieve_camera_operator.c\
		retrieve_screen_operator.c\
		retrieve_world_operator.c\
		xml_color.c\
		xml_float_or_percentage.c\
		xml_vector.c\
		xml_int.c\
		object_selection.c\
		ui.c\
		ux.c\
		filtres.c\
		mb_filter.c\
		sepia_filtre.c\
		rgb.c\
		projection.c\
		repere.c \
		add_component.c\
		slice.c\
		texture.c\
		disk.c\
		update_ui.c\
		hover.c\
		add_object_event.c\
		load_texture.c\
		voronoi.c\
		perlin.c\
		rand.c\
		get_color.c

PARSE_SRC = xml.c


OBJ = $(SRC:%.c=objs/%.o)
DIRECTORY = objs

all: $(NAME)

$(NAME): $(DIRECTORY) $(OBJ)
	@make -C srcs/libft
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS1) $(LIBS)
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>\033[0;35m{YOUR RTV1 HAS BEEN COMPILED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

$(DIRECTORY):
	@mkdir -p objs

objs/%.o: srcs/%.c
	@gcc $(CFLAGS1) -c $< -o $@

objs/%.o: srcs/parser/%.c
	@gcc $(CFLAGS1) -c $< -o $@

objs/%.o: srcs/ui_ux/%.c
	@gcc $(CFLAGS1) -c $< -o $@

objs/%.o: srcs/rahimi/%.c
	@gcc $(CFLAGS1) -c $< -o $@

clean:
	@rm -rf objs
	@rm -f $(OBJ)
	@make clean -C srcs/libft
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>>\033[0;32m{YOUR RTV1 HAS BEEN CLEANED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

fclean: clean
	@make fclean -C srcs/libft
	@rm -f $(NAME)

re: fclean all
.PHONY: fclean, clean, re, all, rtv1

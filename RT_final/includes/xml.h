/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:23:43 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/06 20:19:35 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_H
# define XML_H

# define WHITESPACES " \t\n\v\t\r\f"
# define VALID_CHARACTERS "qwertyuiopasdfghjklzxcvbnm0123456789-_"
# define SYNTAX_ERROR "XML syntax error"
# define RT_ERROR "RT Object error"

typedef union	u_xml_value
{
	long double		number;
	t_vecteur	vector;
	char*		string;
}				t_xml_value;

typedef struct	s_xml_props
{
	char				*key;
	char				*value;
	struct s_xml_props	*next;
}				t_xml_props;

typedef struct	s_xml_object
{
	char				*name;
	t_xml_props			*props;
	size_t				nb_props;
	t_xml_props			*head_props;
	t_xml_props			*tmp_props;
	struct s_xml_object	*next;
}				t_xml_object;

typedef struct	s_xml_helper
{
	size_t			nb_obj;
	t_xml_object	*obj_list;
	t_xml_object	*tmp_obj;
	t_xml_object	*head_obj;
}				t_xml_helper;

#endif

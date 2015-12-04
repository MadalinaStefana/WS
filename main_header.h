/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:29:48 by msinca            #+#    #+#             */
/*   Updated: 2015/12/04 13:43:41 by msinca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MAIN_HEADER_H
#	define MAIN_HEADER_H
#	include <stdio.h>
#	include "libft.h"

typedef struct	s_person
{
	char		name[40];
	char		surname[40];
	char		county[40];
	char		grade[40];
	char		email_address[40];

	char		**decipher_fields(char *string);
	t_person	organize_person_data(char *initial_string);
	int			verify_grade(char *grade);
	int			verify_email_address(char *email);
	int			verify_naming(char *name);
	void		print_error(char *field);
}

#endif

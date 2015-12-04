/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:03:21 by msinca            #+#    #+#             */
/*   Updated: 2015/12/04 15:40:37 by msinca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void			print_error(char *field)
{
	printf("\nThe %s you introduced is incorrect. Please retry.\n\n", field);
}

int				verify_grade(char *grade)
{
	size_t		length;

	length = ft_strlen(grade);
	if (length > 5 || length == 0)
		return (0);
	if (length == 5 && ft_strcmp(grade, "10.00"))
		return (0);
	if (!ft_isdigit(grade[0]) || grade[1] != '.' || !ft_isdigit(grade[2]) || !ft_isdigit(grade[3]))
		return (0);
	return (1);
}

int				verify_naming(char *name)
{
	int 		index;

	if(ft_strlen(name) < 2)
		return (0);
	index = 0;
	while (name[index] != '\0')
	{
		if (!ft_isalpha(name[index]))
			return (0);
		index++;
	}
	return (1);
}

int				verify_email_address(char *email)
{
	int			index;
	int			nr_apparitions_period;
	int			nr_apparitions_at;
	int			nr_alnum_char;

	if (ft_strlen(email) < 5)
		return (0);
	index = 0;
	nr_apparitions_period = 0;
	nr_apparitions_at = 0;
	nr_alnum_char = 0;
	while (email[index])
	{
		if (!ft_isprint(email[index]) || email[index] == ' ')
			return (0);
		if (ft_isalnum(email[index]))
			nr_alnum_char++;
		if (email[index] == '.')
			nr_apparitions_period++;
		if (email[index] == '@')
			nr_apparitions_at++;
	}
	if (nr_apparitions_period == 0 || nr_apparitions_at == 0 || nr_alnum_char < 3)
		return (0);
	return (1);
}


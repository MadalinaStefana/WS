#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct	s_person
{
	char		name[20];
	char		surname[40];
	char		county[20];
	char		grade[6];
	char		email_address[20];
}				t_person;

void			print_error(char *error_code)
{
	if (ft_strcmp(error_code, "surname") == 0)
		printf("\nThe surname you introduced is not valid. ");
	else if (ft_strcmp(error_code, "name") == 0)
		printf("\nThe name you introduced is not valid. ");
	else if (ft_strcmp(error_code, "email") == 0)
		printf("\nThe e-mail address you introduced is not valid. ");
	else if (ft_strcmp(error_code, "grade") == 0)
		printf("\nThe grade you introduced is not valid. ");
	else if (ft_strcmp(error_code, "county") == 0)
		printf("\nThe county name you introduced is not valid. ");
	printf("Please retry.\n\n");
}

int				verify_grade(char *field)
{
	size_t		length;

	length = ft_strlen(field);
	if (length > 5 || length == 0)
		return (0);
	if (length == 5 && ft_strcmp(field, "10.00"))
		return (0);
	if (!ft_isdigit(field[0]) || field[1] != '.' || !ft_isdigit(field[2]) || !ft_isdigit(field[3]))
		return (0);
	return (1);
}

int				verify_naming(char *field)
{
	int 		index;

	if(ft_strlen(field) < 2)
		return (0);
	if (!ft_isalpha(field[0]) || ft_toupper(field[0]) == field[0])
		return (0);
	index = 0;
	while (field[index] != '\0')
	{
		if (!ft_isalpha(field[index]))
			return (0);
		index++;
	}
	return (1);
}

int				verify_email_address(char *field)
{
	int			index;
	int			nr_apparitions_period;
	int			nr_apparitions_at;
	int			nr_alnum_char;

	if (ft_strlen(field) < 5)
		return (0);
	index = 0;
	nr_apparitions_period = 0;
	nr_apparitions_at = 0;
	nr_alnum_char = 0;
	while (field[index])
	{
		if (!ft_isprint(field[index]) || field[index] == ' ')
			return (0);
		if (ft_isalnum(field[index]))
			nr_alnum_char++;
		if (field[index] == '.')
			nr_apparitions_period++;
		if (field[index] == '@')
			nr_apparitions_at++;
	}
	if (nr_apparitions_period == 0 || nr_apparitions_at == 0 || nr_alnum_char < 3)
		return (0);
	return (1);
}

char			**decipher_fields(char *string)
{
	char		 **data_table;
	int			str_index;
	int			line_index;
	int			column_index;

	str_index = 0;
	line_index = 0;
	column_index = 0;
	data_table = (char **)malloc(sizeof(char *) * 5);
	while (string[str_index] != '\0')
	{
			data_table[line_index] = (char *)malloc(sizeof(char) * 25);
		while (string[str_index] != ';' && string[str_index] != '\0')
		{
			data_table[line_index][column_index] = string[str_index];
			str_index++;
			column_index++;
		}
			data_table[line_index][column_index] = '\0';
			str_index++;
			line_index++;
			column_index = 0;
	}
	return (data_table);
}

t_person		organize_person_data(char *initial_string)
{
	char		**data_table;
	t_person	person;

	data_table = decipher_fields(initial_string);
	if (verify_naming(data_table[0]) == 0)
		print_error("surname");	
	strcpy(person.surname, data_table[0]);
	if (verify_naming(data_table[1]) == 0)
		print_error("name");
	strcpy(person.name, data_table[1]);
	if (verify_email_address(data_table[2]) == 0)
		print_error("email");
	strcpy(person.email_address, data_table[2]);
	if (verify_grade(data_table[3]) == 0)
		print_error("grade");
	strcpy(person.grade, data_table[3]);
	if (verify_naming(data_table[4]) == 0)
		print_error("county");
	strcpy(person.county, data_table[4]);
	return (person);
}

int 			main()
{
	FILE 		*file_descriptor;
	char		buffer[255];
	t_person	current_person;
	
	file_descriptor = fopen("students.csv", "r");
	while (fscanf(file_descriptor, "%s", buffer) > 0)
	{
		current_person = organize_person_data(buffer);
	if ((strcmp(current_person.county, "Cluj") == 0) && (atof(current_person.grade) > 8.00))
		printf("\n%s %s", current_person.surname, current_person.name);
	}
	return (0);
}

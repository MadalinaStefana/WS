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

/*char			**decipher_fields(char *string)
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
}*/

void			strlower(char *string)
{
	int		i;

	i = 0;
	while (string[i])
	{
		string[i] = ft_tolower(string[i]);
		i++;
	}
}

void			trim(char **table)
{
	int i;

	i = 0;
	while (table[i])
	{
		table[i] = ft_strtrim(table[i]);
		i++;
	}
}

t_person		organize_person_data(char *initial_string)
{
	char		**data_table;
	t_person	person;
	
	strlower(initial_string);
	data_table = ft_strsplit(initial_string);
	trim(data_table);
	if (verify_naming(data_table[0]) == 0)
	{
		print_error("surname");
		return (0);
	}
	strcpy(person.surname, data_table[0]);
	else if (verify_naming(data_table[1]) == 0)
	{
		print_error("name");
		return (0);
	}
	strcpy(person.name, data_table[1]);
	else if (verify_email_address(data_table[2]) == 0)
	{
		print_error("email");
		return (0);
	}
	strcpy(person.email_address, data_table[2]);
	else if (verify_grade(data_table[3]) == 0)
	{
		print_error("grade");
		return (0);
	}
	strcpy(person.grade, data_table[3]);
	else if (verify_naming(data_table[4]) == 0)
	{
		print_error("county");
		return (0);
	}
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

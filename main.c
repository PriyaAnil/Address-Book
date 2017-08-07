#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

// Read the file name
void read_file_name(read_info *read)
{
	int size;
	char buff[32], *ptr;

	printf("Enter the file name: ");
	scanf("%s", buff);
	size = strlen(buff + 1);
	ptr = (char *)malloc(sizeof(char) * size);
	strcpy(ptr, buff);
	read->fname = ptr;
}

// Main program
int main()
{
	int option;
	char ch;
	read_info read;
	add_book addbook;

	// Read the file name
	read_file_name(&read);

	do
	{
		// Read the options
		printf("1. Insert\n2. Edit\n3. Search\n4. Delete\n5. Display\nEnter the option: ");
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:

				// Insert data
				if ((insert_data_to_addbook(&addbook, &read, option)) < 0)
					break;
				
				break;

			case 2:

				// Edit data
				edit_data(&addbook, &read, option);
				printf("Contact edited successfully\n");
				break;

			case 3:

				// Search data
				if (read_search_data(&read, &addbook, option) < 0)
					break;

				break;
			
			case 4:

				// Delete data
				delete_data(&addbook, &read, option);
				printf("Contact deleted successfully\n");

				break;

			case 5:

				// Display data
				display_add_book(&read);
				break;
		}
		printf("continue: ");
		scanf("\n%c", &ch);
	}while(ch == 'y');

	return 0;
}

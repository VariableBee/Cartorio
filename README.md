# **About this project**

This was my first project in C. 

It's a registration and query system based on name, last name, position, and CPF(Brazilian Document).

## **Libraries**
```c
#include <stdio.h> // User communication library
#include <stdlib.h> // Memory allocation library
#include <locale.h> // Regional text allocation library
#include <string.h> // String handling library
```
## **How does it work?**

When executing this program, the user must first enter their administrator credentials¹, and then, will see the following menu:

Choose the desired menu option:

1 - Register names

2 - Query names

3 - Delete names

4 - Exit the system

Option: Gets user's input

### **PS¹: The password is "a"**

You can change this within the int main() function

Line 134 of the program > char enteredPassword[10] = "INSERT YOUR PASSWORD";

When choosing a menu action, the program will execute the following lines of code, thus calling the functions listed below, within the main function of the program. After each action, for example, registering, the user can return to the main menu and perform a new action, such as consulting a person already registered based on role, CPF, name, last name.

```c
// Start of the menu selection
switch (option) {
    case 1:
        registerUser(); // Function call
        break;

    case 2:
        query();
        break;

    case 3:
        delete();
        break;

    case 4:
        printf("Thank you for using the system\n");
        return 0;
        break;

    default:
        printf("This option is not available!\n");
        system("pause");
        break;
} // End of selection
```
## **Functions**
- **registerUser()** // Function responsible for registering users in the system
- **query()** // Function responsible for consulting users in the system
- **delete()** // Function responsible for deleting users from the system
```c
int registerUser() // Function responsible for registering users in the system 
{	
	// Variables/strings
	char file[40];
	char cpf[40];
	char name[40];
	char lastName[40];
	char role[40];
	// End of variables/strings
	
	printf("Enter the CPF to be registered: "); // Collecting user information
	scanf("%s", cpf);  // %s saves string information into variables 
	strcpy(file, cpf); // Copy the value of one string to another
	
	FILE *userFile; // Create the file
	userFile = fopen(file, "w"); //"w" writes to the file being created and accessed
	fprintf(userFile, cpf); // Save the variable value to the file
	fclose(userFile); // Close the file

	userFile = fopen(file, "a"); //"a" updates the file being accessed
	fprintf(userFile, ", ");  // Adding a comma to separate user information
	fclose(userFile); // Close the file

	printf("Enter a name to be registered: "); // Registering the user's name
	scanf("%s", name);

	userFile = fopen(file, "a");
	fprintf(userFile, name);
	fclose(userFile);

	userFile = fopen(file, "a");
	fprintf(userFile, ", ");
	fclose(userFile);

	printf("Enter a last name to be registered: "); // Registering the user's last name
	scanf("%s", lastName);

	userFile = fopen(file, "a");
	fprintf(userFile, lastName);
	fclose(userFile);

	userFile = fopen(file, "a");
	fprintf(userFile, ", ");
	fclose(userFile);

	printf("Enter a role to be registered: "); // Registering the user's role
	scanf("%s", role);

	userFile = fopen(file, "a");
	fprintf(userFile, role);
	fclose(userFile);
} // End of "register" function

int query()  // Function responsible for querying users in the system
{	
	// Set language
	setlocale(LC_ALL, "English"); 
	
	// Variables/strings
	char cpf[40];
	char content[200];
	// End of variables/strings
	
	printf("Enter the CPF to be queried: "); // Querying the user by CPF
	scanf("%s", cpf); // %s saves string information into variables 
	
	FILE *userFile; // Create/access the file
	userFile = fopen(cpf, "r"); //"r" to "read" the file being accessed

	if(userFile == NULL) // Validating CPF
	{
		printf("Unable to open the file. File not found.");
	}
	
	while(fgets(content, 200, userFile) != NULL) // Get all user data based on their CPF
	{
		printf("\nThese are the user's details: ");
		printf("%s", content);
		printf("\n\n");	
	}
	
	system("pause"); // Pause for the user to check their data
} // End of "query" function

int delete()  // Function responsible for deleting users from the system
{	
	// Variables/strings
	char cpf[40];
	// End of variables/strings
	
	// Query user by CPF
	printf("Enter the user's CPF to be deleted: ");
	scanf("%s", cpf);
	
	system("cls"); // Clear the screen
	
	// Access the file to "read" the CPF
	FILE *userFile;
	userFile = fopen(cpf, "r");
	fclose(userFile);
	
	// If the CPF does not exist: The user is not in the system!
	if(userFile == NULL)
	{
		printf("\nThe user is not in the system!\n\n");
		system("pause");
	}
	else
	{
	remove(cpf);
	printf("\nUser deleted successfully\n\n");
	system("pause");
	}
```


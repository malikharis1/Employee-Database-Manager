#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 20
#define FILE_NAME "employee_data.txt"

int totalNumberOfEmploy = 0;

struct data
{
    char name[20];
    int id;
    char password[20];
};

struct data user[MAX_EMPLOYEES];
void sortID();
void press();
void showEmploy();
void removeEmploy();
void addEmploy();
void saveData();
void loadData();
void searchUser();
void main()
{
    loadData();
    press();
    saveData();
}
void saveData()
{
    FILE *file;
    file = fopen(FILE_NAME, "w");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", totalNumberOfEmploy);

    for (int i = 0; i < totalNumberOfEmploy; i++)
    {
        fprintf(file, "%s %d %s\n", user[i].name, user[i].id, user[i].password);
    }

    fclose(file);
}

void loadData()
{
    FILE *file;
    file = fopen(FILE_NAME, "r");

    if (file == NULL)
    {
        printf("Error opening file for reading. Starting with an empty record.\n");
        return;
    }

    fscanf(file, "%d", &totalNumberOfEmploy);

    for (int i = 0; i < totalNumberOfEmploy; i++)
    {
        fscanf(file, "%s %d %s", user[i].name, &user[i].id, user[i].password);
    }

    fclose(file);
}

void clearScreen()
{
    printf("\033[2J\033[1;1H");
}

void showEmploy()
{
    clearScreen();

    printf("\n\t\t\t\tEmploy details ");

    for (int i = 0; i < totalNumberOfEmploy; i++)
    {
        printf("\nEmploy Name : %s", user[i].name);
        printf("\nEmploy ID : %d", user[i].id);
        printf("\nEmploy Password : %s", user[i].password);
    }

    press();
}

void addEmploy()
{
    int limit;
    int i;
    clearScreen();

    printf("How many employs you want to add : ");
    scanf("%d", &limit);
    i = totalNumberOfEmploy;
    limit = totalNumberOfEmploy + limit;
    for (; i < limit; i++)
    {
        printf("\nEmploy Name :");
        scanf("%s", user[i].name);
        printf("\nEmploy ID :");
        scanf("%d", &user[i].id);
        printf("\nEmploy Password: ");
        scanf("%s", user[i].password);
    }
    totalNumberOfEmploy = limit;

    press();
}

void removeEmploy()
{
    int removeVal;
    clearScreen();

    printf("Enter the id of an employ you want to remove: ");
    scanf("%d", &removeVal);

    for (int i = 0; i < totalNumberOfEmploy; i++)
    {
        if (user[i].id == removeVal)
        {
            for (int j = i; j < totalNumberOfEmploy - 1; j++)
            {
                strcpy(user[j].name, user[j + 1].name);
                user[j].id = user[j + 1].id;
                strcpy(user[j].password, user[j + 1].password);
            }
            totalNumberOfEmploy--;
            break;
        }
    }

    press();
}
void sortID()
{
    for (int i = 0; i < totalNumberOfEmploy; i++)
    {
        user[i].id = i + 1;
    }
    showEmploy();
    press();
}
void searchUser()
{
    char searchval[20];
    clearScreen();

    printf("Enter the name of the employee you want to search: ");
    scanf("%s", searchval);

    int found = 0;

    for (int i = 0; i < totalNumberOfEmploy; i++)
    {
        if (strcmp(searchval, user[i].name) == 0)
        {
            printf("\nEmploy Name: %s", user[i].name);
            printf("\nEmploy ID: %d", user[i].id);
            printf("\nEmploy Password: %s", user[i].password);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Employee with the given name not found.\n");
    }
    press();
}

void press()
{
    int choice;

    printf("\t\t\t\twelcome to Alfurqan");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t Total number of employs: %d", totalNumberOfEmploy);

    printf("\nPress 1 if you want to see the Employ details :");
    printf("\nPress 2 if you want to Add a new Employ :");
    printf("\nPress 3 if you want to remove a Employ  :");
    printf("\nPress 4 if you want to sort id of all Employs  :");
    printf("\nPress 5 to search a user:");

    printf("\nPress any other key to exit :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        if (totalNumberOfEmploy == 0)
        {
            printf("Sorry, no employ is added.\n");
            press();
        }
        else
        {
            showEmploy();
        }
        break;

    case 2:
        addEmploy();
        break;

    case 3:
        removeEmploy();
        break;
    case 4:
        sortID();
        break;
    case 5:
        searchUser();
        break;
    default:
        break;
    }
}

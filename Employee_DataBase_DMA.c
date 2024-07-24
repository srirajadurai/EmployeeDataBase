#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

struct Employee_DataBase
{
    long int id;
    char name[50];
    int experience;
    int age;
    int salary;
    char position[100];
};

struct Employee_DataBase *Emp; 
int count = -1; 

void createAccount();
void displayAccount();
void deleteAccount();
void searchAccount();
int checkAccount(long int id);

int main()
{
    int ch;

    Emp = (struct Employee_DataBase *)malloc(MAX * sizeof(struct Employee_DataBase)); 

    if(Emp == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1; 
    }

    while(1)
    {
        printf("\n1. Create a Employee Account\n2. Display my Details\n3. Delete my Account\n4. Search my Account\n5. Exit\n");
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                searchAccount();
                break;
            case 5:
                free(Emp); 
                exit(0); 
            default:
                printf("Invalid Choice..\n");
                break;
        }
    }
    return 0;
}

// Creating the Account
void createAccount()
{
    int match=0;
    count++;
    while(1)
    {
        printf("\nCreate your unique ID (Ex:1001): ");
        scanf("%li", &Emp[count].id);
        match=0;
        for(int i=0;i<count;i++)
        {
            if(Emp[i].id== Emp[count].id)
                match=1;
        }
        if(match==0)
        {
            break;
        }
        if(match==1)
        {
            printf("\nIt is already Exits.\n");
        }
    }
    getchar(); 
    printf("\nEnter your Name: ");
    fgets(Emp[count].name,50,stdin);
    strtok(Emp[count].name, "\n"); 
    printf("\nHow many years of Experience you have? : ");
    scanf("%d", &Emp[count].experience);
    printf("\nEnter your Age: ");
    scanf("%d", &Emp[count].age);
    printf("\nEnter your Salary: ");
    scanf("%d", &Emp[count].salary);
    getchar(); 

    printf("\nEnter your position: ");
    fgets(Emp[count].position,100,stdin);
    strtok(Emp[count].position, "\n");
    printf("\nYour Account has been created successfully.....\n");
}

void deleteAccount()
{
    while(1)
    {
        long int id;
        printf("\nEnter the ID to delete: ");
        scanf("%li", &id);
        int index = checkAccount(id);
        if (index != -1) 
        {
            printf("\nEmployee Account with ID %li deleted successfully.\n", id);
            for (int i = index; i < count; i++)
            {
                Emp[i] = Emp[i + 1];
            }
            count--;
            break;
        }
        else 
        {
            printf("\nEmployee Account with ID %li not found.\n", id);
            printf("\nEnter a valid Employee ID.\n");
        }
    }
}

void searchAccount()
{
    while(1)
    {
        long int id;
        printf("\nEnter the ID to search: ");
        scanf("%li", &id);
        int index = checkAccount(id);
        if (index != -1) {
            printf("%-6s %-15s %-15s %-10s %-15s %-20s\n","ID","Name","Experience","Age","Salary","Position");
            printf("%-6li %-15s %-15d %-10d %-15d %-20s\n", Emp[index].id, Emp[index].name, Emp[index].experience, Emp[index].age, Emp[index].salary, Emp[index].position);
            break;
        }
        else {
            printf("\nEmployee Account with ID %li not found.\n", id);
            printf("\nEnter a valid Employee ID.\n");
        }
    }
}

int checkAccount(long int id) {
    for (int i = 0; i <= count; i++) {
        if (id == Emp[i].id) {
            return i;
        }
    }
    return -1;
}

void displayAccount()
{
    printf("%-6s %-15s %-15s %-10s %-15s %-20s\n","ID","Name","Experience","Age","Salary","Position");
    for(int i = 0; i <= count; i++)
    {
        printf("%-6li %-15s %-15d %-10d %-15d %-20s\n", Emp[i].id, Emp[i].name, Emp[i].experience, Emp[i].age, Emp[i].salary, Emp[i].position);
    }
}

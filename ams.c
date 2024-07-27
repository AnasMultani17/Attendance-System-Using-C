#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define SESSION_NUM 100

void studentSignUp();
void teacherSignUp();
int studentLogin();
int teacherLogin();
float studentCP();
float studentP();
void teacherCP();
void teacherP();
void line()
{
    for (int i = 0; i < 45; i++)
    {
        printf("_");
    }
    printf("\n");
}

char usernameS[MAX_USERS][MAX_USERNAME_LENGTH], passwordS[MAX_USERS][MAX_PASSWORD_LENGTH], usernameT[MAX_USERS][MAX_USERNAME_LENGTH],
    passwordT[MAX_USERS][MAX_PASSWORD_LENGTH], assignment[100];
int attendanceCP[MAX_USERS][SESSION_NUM], attendanceP[MAX_USERS][SESSION_NUM], roll, userCountS = 0, userCountT = 0, sessionCP, sessionP, choice2, choice22;
float p;

void main()
{
    int choice;

    do
    {
        printf("1. Student Sign Up\n");
        printf("2. Teacher Sign Up\n");
        printf("3. Student Login\n");
        printf("4. Teacher Login\n");
        printf("0. Exit\n");
        line();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        line();
        switch (choice)
        {
        case 1:
            studentSignUp();
            line();
            break;
        case 2:
            teacherSignUp();
            line();
            break;
        case 3:
            if (studentLogin())
            {
                printf("Student login successful.\n");
                line();
                printf("Press 1 for Computer programming attendance\nPress 2 for Physics attendance\nPress 0 for main menu\n");
                line();
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                line();

                switch (choice2)
                {
                case 1:
                    p = studentCP();
                    printf("\nAttendance in CP is %f percent\n", p);
                    line();
                    break;
                case 2:
                    p = studentP();
                    printf("\nAttendance in Physics is %f percent\n", p);
                    line();
                    break;
                case 0:
                    printf("Exiting to main menu\n");
                    line();
                    break;
                default:
                    printf("Invalid choice...\n");
                    line();
                }
            }
            else
            {
                printf("Student login failed.\n");
                line();
            }
            break;
        case 4:
            if (teacherLogin())
            {
                printf("Teacher login successful.\n");
                line();

                printf("Press 1 for Computer programming attendance\nPress 2 for Physics attendance\nPress 0 for main menu\n");
                line();
                printf("Enter your choice : ");
                scanf("%d", &choice22);
                line();

                switch (choice22)
                {
                case 1:
                    teacherCP();
                    line();
                    break;
                case 2:
                    teacherP();
                    line();
                    break;
                case 0:
                    printf("Exiting to main menu\n");
                    line();
                    break;
                default:
                    printf("Invalid choice...\n");
                    line();
                }
            }
            else
            {
                printf("Teacher login failed.\n");
                line();
            }
            break;
        case 0:
            printf("Exiting program.\n");
            line();
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            line();
        }
    } while (choice != 0);

}

void studentSignUp()
{
    if (userCountS < MAX_USERS)
    {
        start:
        printf("Enter student username: ");
        scanf("%s", usernameS[userCountS]);
        printf("Enter student password: ");
        scanf("%s", passwordS[userCountS]);
        line();
        for (int i = 0; i < userCountS; i++)
        {
            if (strcmp(usernameS[i], usernameS[userCountS]) == 0)
            {
                printf("Username already exists. Change username.\n");
                line();
                goto start;
            }
        }
        userCountS++;
        printf("Student sign up successful.\n");
        line();
    }
    else
    {
        printf("User limit reached. Cannot sign up more users.\n");
        line();
    }
}

void teacherSignUp()
{
    if (userCountT < MAX_USERS)
    {
        start:
        printf("Enter Teacher username: ");
        scanf("%s", usernameT[userCountT]);
        printf("Enter Teacher password: ");
        scanf("%s", passwordT[userCountT]);
        line();
        for (int i = 0; i < userCountT; i++)
        {
            if (strcmp(usernameT[i], usernameT[userCountT]) == 0)
            {
                printf("Username already exists. Change username.\n");
                line();
                goto start;
            }
        }
        userCountT++;
        printf("Teacher sign up successful.\n");
        line();
    }
    else
    {
        printf("User limit reached. Cannot sign up more users.\n");
        line();
    }
}

int studentLogin()
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter student username: ");
    scanf("%s", username);
    printf("Enter student password: ");
    scanf("%s", password);
    line();

    for (int i = 0; i < userCountS; i++)
    {
        if (strcmp(usernameS[i], username) == 0 && strcmp(passwordS[i], password) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int teacherLogin()
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter Teacher username: ");
    scanf("%s", username);
    printf("Enter Teacher password: ");
    scanf("%s", password);
    line();

    for (int i = 0; i < userCountT; i++)
    {
        if (strcmp(usernameT[i], username) == 0 && strcmp(passwordT[i], password) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void teacherCP()
{
    if (teacherLogin())
    {
        printf("Enter total numbers of sessions in CP:");
        scanf("%d", &sessionCP);
        line();

        printf("1 For present\n2 For absent\n");
        line();

        for (int i = 0; i < userCountS; i++)
        {
            printf("Enter CP attendance of roll no:23ced%d\n", i + 1);
            for (int j = 0; j < sessionCP; j++)
            {
                printf("\tSession %d : ", j + 1);
                scanf("%d", &attendanceCP[i][j]);
            }
        }
    }
    else
    {
        printf("Teacher login failed. Cannot upload CP attendance.\n");
        line();
    }
}

void teacherP()
{
    if (teacherLogin())
    {
        printf("Enter total numbers of sessions in Physics:");
        scanf("%d", &sessionP);
        line();

        printf("1 For present\n2 For absent\n");
        line();

        for (int i = 0; i < userCountS; i++)
        {
            printf("Enter Physics attendance of roll no:23ced%d\n", i + 1);
            for (int j = 0; j < sessionP; j++)
            {
                printf("\tSession %d : ", j + 1);
                scanf("%d", &attendanceP[i][j]);
            }
        }
    }
    else
    {
        printf("Teacher login failed. Cannot upload Physics attendance.\n");
        line();
    }
}

float studentCP()
{
    int sumCP = 0;
    int roll;
    printf("Enter last two digits of your roll no: ");
    scanf("%d", &roll);
    line();
    for (int j = 0; j < sessionCP; j++)
    {
        sumCP = sumCP + attendanceCP[roll - 1][j];
    }
    float percentage = (float)(sumCP * 100) / sessionCP;
    return percentage;
}

float studentP()
{
    int sumP = 0;
    int roll;
    printf("Enter last two digits of your roll no: ");
    scanf("%d", &roll);
    line();
    for (int j = 0; j < sessionP; j++)
    {
        sumP = sumP + attendanceP[roll - 1][j];
    }
    float percentage = (float)(sumP * 100) / sessionP;
    return percentage;
}

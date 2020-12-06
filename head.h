#define SIZE_THIRTY 30
#define LOT_STUDENTS 5
#define MAX_SIZE 256
#define MAX_NUMBER_LESSONS 3
#define MAX_SCORES 5

typedef struct
{
    char surName[SIZE_THIRTY];
    // char lesson[SIZE_THIRTY];
    char Student[SIZE_THIRTY];
    // int score[SIZE_THIRTY][SIZE_THIRTY];
} StudentStuct;
StudentStuct Students[SIZE_THIRTY];

Lesson[SIZE_THIRTY][SIZE_THIRTY];
Score[SIZE_THIRTY][SIZE_THIRTY][SIZE_THIRTY];

int studentNumber[SIZE_THIRTY];
int currStudent = 0;

int menuNumber = 0, errorCode = 0, NumberStudents = 0, NumberLessons = 0, numberOfStudents = 0, numberLesson = 0;
int scoreNumber = 0, numberScores = 0, selectNumber = 0;
char TargetFile[MAX_SIZE] = "";
FILE *NameFile;

void enterTargetFile()
{
    do
    {
        do
        {
            printf("Меню:\n(1) - выбрать текстовый файл\n(2) - создать текстовый файл\n");
            errorCode = transfer(&menuNumber);
        }while(1 == errorCode);
        switch(menuNumber)
        {
        case 1:
            printf("Задайте путь к рабочему файлу: ");
            fflush(stdin);
            scanf("%s", TargetFile);
            fflush(stdin);
            NameFile = fopen(TargetFile,"r");
            if(NameFile == 0)
            {
                printf("Ошибка, файла по данному пути не найдено\n");
                errorCode = 1;
            }
            else
            {
                printf("Файл найден\n");
                errorCode = 0;
            }
            fclose(NameFile);
            break;
        case 2:
            printf("Укажите полный путь к создаваемому файлу: ");
            scanf("%s", TargetFile);
            fflush(stdin);
            NameFile = fopen(TargetFile,"w");
            printf("Файл успешно создан\n");
            fclose(NameFile);
            errorCode = 0;
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Неизвестная операция, агент 007\n");
            errorCode = 1;
            break;
        }if(errorCode==0) break;
    }while(menuNumber!=1||menuNumber!=2||menuNumber!=0);
}
void enterArray(char *array)
{
    char buffer;
    for (int i=0; i<SIZE_THIRTY; i++)
        {
            buffer = getchar();
            if(buffer == '\n')
            {
//                array[i] = ' ';
                break;
            }
            else
            {
                array[i] = buffer;
            }
        }
}
int checkArrayName(char *array)
{
    int k = strlen(array);
//    k--; //убирает последний элемент массива, который служит пробелом после каждого элемента фио
    for (int i=0; i<k; i++)
    {
        if(!isalpha(array[i]))
        {
            printf("Ошибка, повторите попытку\n");
            clearArray(array, SIZE_THIRTY);
            return 0;
        }
    }
    array[0]=toupper(array[0]);
    return 1;
}
void clearArray(char *array, int array_size)
{
    for (int i=0; i<array_size; i++)
    {
        array[i]='\0';
    }
}
int transfer(int *teleport)
{
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strlen(buffer)-1]='\0';
    int k = strlen(buffer);
    if(k=0)
    {
        printf("Ошибка\n");
        return 1;
    }
    for(int i=0; i<k; i++)
    {
        if(!isdigit(buffer[i]))
        {
            printf("Ошибка\n");
            return 1;
        }
    }
    *teleport = atoi(buffer);
    return 0;
}
void printArray(char* array)    //вывод массива
{
    int k = strlen(array);
    for (int i=0; i<k; i++)
        {
            printf("%c", array[i]);
        }
    if(array[k-1]!='\n')
    {
        printf("\n");
    }
}
void readDataBase()
{
    char buffer[MAX_SIZE] = "";
    char *flag = NULL;
    FILE *NameFile = NULL;
    NameFile = fopen(TargetFile, "r");
    while(!feof(NameFile))
    {
        flag = fgets(buffer, MAX_SIZE, NameFile);
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        if(flag != NULL)
        {
            char *bufferFile;
            if(isdigit(buffer[0]))
            {
                numberLesson = 0;
                bufferFile = strtok(buffer, ".");   // когда была точка пробел фамилию записывал как " Чумаченко"
                studentNumber[currStudent] = atoi(bufferFile);
                bufferFile = strtok(NULL, "\t");
                strcpy(Students[currStudent].surName, bufferFile);
                currStudent++;
            }
            else
            {
                bufferFile = strtok(buffer, ":");
                // strcpy(Lesson[currStudent-1][numberLesson], bufferFile);

                // bufferFile = strtok(NULL, " ");
                // while(bufferFile!=NULL)
                // {
                //     Score[currStudent-1][numberLesson][scoreNumber] = atoi(bufferFile);
                //     bufferFile = strtok(NULL, " ");
                //     scoreNumber++;
                // }
                // do
                // {
                //     bufferFile = strtok(NULL, " ");
                //     Score[currStudent-1][numberLesson][scoreNumber] = atoi(bufferFile);
                //     scoreNumber++;
                // }while(bufferFile != NULL);

                numberLesson++;
            }
        }
    }   
    fclose(NameFile); 
}
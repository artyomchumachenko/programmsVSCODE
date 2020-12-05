#define SIZE_THIRTY 30
#define LOT_STUDENTS 5
#define MAX_SIZE 256
#define MAX_NUMBER_LESSONS 3

typedef struct
{
    char surName[SIZE_THIRTY];
    char lesson[SIZE_THIRTY];
    char Student[SIZE_THIRTY];
    int score[SIZE_THIRTY][SIZE_THIRTY];
} StudentStuct[SIZE_THIRTY];
StudentStuct Students;

int menuNumber=0, errorCode=0, NumberStudents=0, NumberLessons=0, studentNumber = 1, numberOfStudents=0;
char TargetFile[MAX_SIZE];
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
void enterLessons()
{
//    NumberLessons = 0;
//    errorCode = 0;
    do
    {
        printf("Введите количество добавляемых предметов: ");
        errorCode = transfer(&NumberLessons);
//        printf("\n%d    %d\n", errorCode, NumberLessons);
    }while((errorCode == 1)||(NumberLessons<1)||(NumberLessons>MAX_NUMBER_LESSONS));
//    fflush(stdin);
    for(int i=0; i<NumberLessons; i++)
    {
        do
        {
            printf("Введите название %d предмета: ", i+1);
            enterArray(Students[i].lesson);
        }while(checkArrayName(Students[i].lesson)==0);
    }
}
int transfer(int *teleport)
{
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strlen(buffer)-1]='\0';
    int k = strlen(buffer);
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
    
}
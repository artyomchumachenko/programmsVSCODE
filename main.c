#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include "head.h"
#include <windows.h>

int main()
{
    setlocale(LC_ALL,"Russian");
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for(int i=0; i<SIZE_THIRTY; i++)
    {
        clearArray(Students[i].surName, SIZE_THIRTY);
        clearArray(Students[i].lesson, SIZE_THIRTY);
        clearArray(Students[i].Student, SIZE_THIRTY);
    }
    enterTargetFile();
    enterLessons();
    do
    {
        do
        {
            printf("\nМеню:\n(1) - добавить студента\n(2) - добавить оценки\n(3) - вывести содержимое txt файла\n(4) - очистить txt файл\n(5) - выбрать другой txt файл\n(0) - завершить работу с программой\n\n");
            errorCode = transfer(&menuNumber);
        }while(errorCode == 1);
        switch(menuNumber)
        {
        case 1:
            {
                char bufferNumber[MAX_SIZE];
                do
                {
                    printf("Введите количество студентов, которых хотите добавить: ");
                    errorCode = transfer(&NumberStudents);
                }while((errorCode == 1)||(NumberStudents<1)||(NumberStudents>LOT_STUDENTS));
                for(int i=0; i<NumberStudents; i++)
                {
                    do
                    {
                        printf("Введите фамилию %d студента: ", studentNumber);
                        enterArray(Students[i].surName);
                    }while(checkArrayName(Students[i].surName)==0);
                    sprintf(bufferNumber, "%d", studentNumber);
                    strcat(Students[i].Student, bufferNumber);
                    strcat(Students[i].Student, ". ");
                    strcat(Students[i].Student, Students[i].surName);
                    studentNumber++;
                    NameFile = fopen(TargetFile,"a");
                    fprintf(NameFile,Students[i].Student);
                    fprintf(NameFile,"\n");
                    fclose(NameFile);
                }
                break;
            }
        case 2:

        case 3:
            {
                printf("\nСписок студентов:\n");
                char tempString[MAX_SIZE];
                NameFile = fopen(TargetFile, "r");
                while(!feof(NameFile))
                {
                    fgets(tempString, MAX_SIZE, NameFile);
                    if(!feof(NameFile))
                    {
                        printArray(tempString);
                    }
                }
                fclose(NameFile);
                break;
            }
        case 4:
            {
                NameFile = fopen(TargetFile, "w");
                fclose(NameFile);
                break;
            }
        case 5:
            {
                enterTargetFile();
                break;
            }
        case 0:
            return 0;
        default:
            {
                printf("Ошибка выбора пункта меню\n");
                break;
            }
        }
    }while(menuNumber!=0);
    return 0;
}

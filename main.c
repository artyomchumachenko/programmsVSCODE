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
        clearArray(Students[i].Student, SIZE_THIRTY);
    }
    for(int i=0; i<SIZE_THIRTY; i++)
    {
        studentNumber[i]=0;
        for(int j=0; j<SIZE_THIRTY; j++)
        {
            Lesson[i][j]=0;
            for(int k=0; k<SIZE_THIRTY; k++)
            {
                Score[i][j][k]=0;
            }
        }
    }
    enterTargetFile();
    readDataBase();
    printf("%s", Students[0].surName);
    // do
    // {
    //     do
    //     {
    //         printf("\n����:\n(1) - �������� ��������\n(2) - �������� ������\n(3) - ������� ���������� txt �����\n(4) - �������� txt ����\n(5) - ������� ������ txt ����\n(0) - ��������� ������ � ����������\n\n");
    //         errorCode = transfer(&menuNumber);
    //     }while(errorCode == 1);
    //     switch(menuNumber)
    //     {
    //     case 1:
    //         {
    //             char bufferNumber[MAX_SIZE];
    //             do
    //             {
    //                 printf("������� ���������� ���������, ������� ������ ��������: ");
    //                 errorCode = transfer(&NumberStudents);
    //             }while((errorCode == 1)||(NumberStudents<1)||(NumberStudents>LOT_STUDENTS));
    //             for(int i=0; i<NumberStudents; i++)
    //             {
    //                 do
    //                 {
    //                     printf("������� ������� %d ��������: ", (studentNumber+1));
    //                     enterArray(Students[studentNumber].surName);
    //                 }while(checkArrayName(Students[studentNumber].surName)==0);
    //                 sprintf(bufferNumber, "%d", (studentNumber+1)); // ????
    //                 strcat(Students[studentNumber].Student, bufferNumber);
    //                 strcat(Students[studentNumber].Student, ". ");
    //                 strcat(Students[studentNumber].Student, Students[studentNumber].surName);
    //                 strcat(Students[studentNumber].Student, "\t");
    //                 NameFile = fopen(TargetFile,"a");
    //                 fprintf(NameFile,Students[studentNumber].Student);
    //                 fprintf(NameFile,"\n");
    //                 fclose(NameFile);
    //                 studentNumber++;
    //             }
    //             break;
    //         }
    //     case 2:
    //         printf("%d %s %s", studentNumber, Students[0].surName, Lesson[0][0]);
    //     case 3:
    //         {
    //             printf("\n������ ���������:\n");
    //             char tempString[MAX_SIZE];
    //             NameFile = fopen(TargetFile, "r");
    //             while(!feof(NameFile))
    //             {
    //                 fgets(tempString, MAX_SIZE, NameFile);
    //                 if(!feof(NameFile))
    //                 {
    //                     printArray(tempString);
    //                 }
    //             }
    //             fclose(NameFile);
    //             break;
    //         }
    //     case 4:
    //         {
    //             NameFile = fopen(TargetFile, "w");
    //             fclose(NameFile);
    //             break;
    //         }
    //     case 5:
    //         {
    //             enterTargetFile();
    //             break;
    //         }
    //     case 0:
    //         return 0;
    //     default:
    //         {
    //             printf("������ ������ ������ ����\n");
    //             break;
    //         }
    //     }
    // }while(menuNumber!=0);
    return 0;
}

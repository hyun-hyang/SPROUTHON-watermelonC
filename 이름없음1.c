/*

���� ���� ���α׷�

*/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <conio.h>

#include <Windows.h>

 

void survey_input(void);

int survey_question_read(char question[][9000], char space[]);

void gotoxy(int x, int y);

 

int main(void)

{

        survey_input();

        return 0;

}

 

void gotoxy(int x, int y)

{

        COORD Pos = { x - 1, y - 1 };

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

 

/*

���� ��°� �������� ���� �ؽ�Ʈ ���Ͽ� �����ϴ� �Լ� survey_input

*/

void survey_input(void)

{

        int i, answer[20], count;

        char yn, question[9000][1000], space[10];

        FILE *fpw;

        count = survey_question_read(question, space);

        fpw = fopen("������.txt", "a");

        do

        {

               system("cls");

               printf("�� ������ ���� ������ ���� �Է��ϰ� Enter�Ͻÿ�.\n");

               printf("������ ���� ���ڸ� ����մϴ�.\n\n");

               for (i = 0; i < count; i++)

                       printf("%d) %s\n", i + 1, question[i]);

               for (i = 0; i < count; i++)

               {

                       fflush(stdin);

                       gotoxy(space[i] + 4, i * 2 + 4);

                       scanf("%d", &answer[i]);

                       fprintf(fpw, "%d ", answer[i]);

               }

               fprintf(fpw, "\n");

               printf("\n");

               printf("�������簡 �������ϴ�. ����� 1, ����� 0�� �Է� ");

               yn = getch();

               printf("\n");

        } while (yn != '0');

        fclose(fpw);

}

 

/*

�ؽ�Ʈ ������ �о� �迭�� �����ϴ� �Լ� survey_question_read

*/

int survey_question_read(char question[][100], char space[])

{

        char chr[100];

        FILE *fpr;

        int count = 0;

        fpr = fopen("��������.txt", "r");

        while (!feof(fpr))

        {

               fgets(chr, 500, fpr);

               space[count] = strlen(chr);

               strcpy(question[count], chr);

               count++;

        }

        fclose(fpr);

        return count; //������ ������ ��ȯ

}


/*

설문 조사 프로그램

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

설문 출력과 응답자의 답을 텍스트 파일에 저장하는 함수 survey_input

*/

void survey_input(void)

{

        int i, answer[20], count;

        char yn, question[9000][1000], space[10];

        FILE *fpw;

        count = survey_question_read(question, space);

        fpw = fopen("조사결과.txt", "a");

        do

        {

               system("cls");

               printf("각 설문에 대해 문항의 답을 입력하고 Enter하시오.\n");

               printf("문항의 답은 숫자만 사용합니다.\n\n");

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

               printf("설문조사가 끝났습니다. 계속은 1, 종료는 0을 입력 ");

               yn = getch();

               printf("\n");

        } while (yn != '0');

        fclose(fpw);

}

 

/*

텍스트 파일을 읽어 배열에 저장하는 함수 survey_question_read

*/

int survey_question_read(char question[][100], char space[])

{

        char chr[100];

        FILE *fpr;

        int count = 0;

        fpr = fopen("설문내용.txt", "r");

        while (!feof(fpr))

        {

               fgets(chr, 500, fpr);

               space[count] = strlen(chr);

               strcpy(question[count], chr);

               count++;

        }

        fclose(fpr);

        return count; //설문의 개수를 반환

}


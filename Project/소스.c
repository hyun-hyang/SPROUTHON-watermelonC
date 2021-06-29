#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define limit 10
#define MAX_NAME_LEN 20

struct student
{
    char name[MAX_NAME_LEN + 1];
    char ID[100];
    char call[100];
    char mail[100];
    char password[100];
};

void join(struct student* info);
void list(struct student* info, struct student* m);
//void insert(struct student* info);
//void covid19_self_exam(struct student* info);
//void schedule_manage(struct student* info);
int main()
{
    struct student m[100];
    char id[limit + 1] = "";
    char password[limit + 1] = "";
    int key_code;
    while (1)
    {
        struct student info[10];
        int i;
        printf("1. 학생 회원가입\n");
        printf("2. 학생 회원목록 확인\n");
        printf("3. 학생 회원정보 수정\n");
        printf("4. 코로나 자가검진 하기\n");
        printf("5. 등교 일정 관리 하기\n");
        printf("6. 종료\n");
        printf("번호를 입력하시오: ");
        scanf("%d", &i);
        printf("\n");

        if (i == 1)
        {
            join(info);
            i = 0;
        }
        if( i == 2)
        {
            list(info, m);
        }
        /* (i == 3)
        {
             insert(info, m);
        }
         ( if (i == 4)
          {
             covid19_self_examination(info);
          }
          if (i == 5)
          {
             schedule_management(info);
          } */
        if (i == 6)
        {
            break;
        }
    }
    
}
void join(struct student* info)
{
    int i, j, k;
    for (i = 0; i < 1001; i++)
    {
        printf("회원가입을 계속 하시겠습니까? 1.Yes 2.No\n");
        scanf("%d", &j);

        if (j == 1)
        {
            printf("이름을 입력하시오: ");
            scanf("%s", info[i].name);
            printf("\n");
            printf("학번을 입력하시오: ");
            scanf("%s", info[i].ID);
            printf("\n");
            printf("전화번호를 입력하시오: ");
            scanf("%s", info[i].call);
            printf("\n");
            printf("이메일을 입력하시오: ");
            scanf("%s", info[i].mail);
            printf("\n");
            printf("비밀번호 입력하시오: ");
            scanf("%s", info[i].password);
            printf("\n");

            FILE* fp;
            fp = fopen("exampleFile.txt", "a");
            if (fp == NULL) {
                printf("실패 - 종료\n");
            }
            fprintf(fp, "%s ", info[i].name);
            fprintf(fp, "%s ", info[i].ID);
            fprintf(fp, "%s ", info[i].call);
            fprintf(fp, "%s ", info[i].mail);
            fprintf(fp, "%s \n", info[i].password);
            fclose(fp);
            printf("완료\n");
        }
        if (j == 2)
            break;
    }
}

void list(struct student* info, struct student* m)
{
    int i, j;
    printf("전체 회원정보를 조회하시겠습니까? 1.Yes 2. No\n");
    scanf("%d", &i);

    FILE* fp;
    fp = fopen("exampleFile.txt", "r");
    char tmp;
    int cnt = 0;
    if (fp == NULL) {
        exit(0);
    }
    if (i == 1)
    {
        while (fscanf(fp, "%c", &tmp) != EOF)
        {
            if (tmp == '\n')
                cnt++;
        }
        printf("회원 수는 %d명입니다.\n", cnt);

        fp = fopen("exampleFile.txt", "r");
        for (int k = 0; k < cnt; k++)
        {
            
            fscanf(fp, "%s %s %s %s %s\n", &m[k].name, &m[k].ID, &m[k].call, &m[k].mail, &m[k].password);
            printf("이름:%s 학번:%s 전화번호:%s 이메일:%s 비밀번호:%s\n", m[k].name, m[k].ID, m[k].call, m[k].mail, m[k].password);

        }
        fclose(fp);
    }
    else
        exit(0);
}

/*
void insert(struct student* info, struct student* m)
{
    char a[MAX_NAME_LEN + 1];
    char b[100];
    int i, j;
    FILE* fp;
    fp = fopen("exampleFile.txt", "r");
    char tmp;
    int cnt = 1;
    if (fp == NULL) {
        exit(0);
    }
    while (fscanf(fp, "%c", &tmp) != EOF) {
        if (tmp == '\n')
            cnt++;
    }
    for (int j = 0; j < cnt; j++)
    {
        fscanf(fp, "%s %d %d %s %s\n", &m[j].name, &m[j].ID, &m[j].call, &m[j].mail, &m[j].password);
        fclose(fp);
    }
    printf("수정하실 회원의 이름을 입력하시오: ");
    scanf("%s", &a);
    printf("\n");
    for (i = 0; i < cnt; i++)
    {
        printf(m[i].name);
        if (strcmp(a, m[i].name) == 0)
        {
            
            while (1)
            {
                printf("수정하실 정보는 무엇입니까? 1.이름 2. 학번 3. 전화번호 4.이메일 5. 비밀번호 6. 종료: ");
                scanf("%d", &j);
            }
            if (j == 1)
            {
                printf("이름 입력: ");
                scanf("%s", m[i].name);
                printf("\n");
            }
        }
    }
} */

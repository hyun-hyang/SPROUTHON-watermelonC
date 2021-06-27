#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 20
int cnt;
struct student
{
	char name[MAX_NAME_LEN + 1];
	char ID[10];
	char call[100];
	char mail[100];
	char password[5];
};
void join(struct student* info);
void login(struct student* info);
//void list(struct student* info);
//void insert(struct student* info);
//void covid19_self_exam(struct student* info);
//void schedule_manage(struct student* info);
int main()
{
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
		printf("7. 로그인\n");ㅂ
		printf("번호를 입력하시오: ");
		scanf("%d", &i);
		printf("\n");

		if (i == 1)
		{
			join(info);
			i = 0;
		}
		/*	if (i == 2)
			{
				list(info);
			}
			if (i == 3)
			{
				insert(info);
			}
			if (i == 4)
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
		if (i == 7)
		{
			login(info);
		}
	}
	return 0;
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
			printf("비밀번호 입력하시오 (4자리 숫자): ");
			scanf("%s", info[i].password);
			printf("\n");
			cnt++;
			/*
			FILE* fp;
			fp = fopen("C:\\Users\\dltmd\\Desktop\\새싹톤\\exampleFile.txt", "a");
			if (fp == NULL) {
				printf("실패 - 종료\n");
			}
			fprintf(fp, "%d. ", i+1);
			fprintf(fp, "이름: %s ", info[i].name);
			fprintf(fp, "학번: %s ", info[i].ID);
			fprintf(fp, "전화번호: %s ", info[i].call);
			fprintf(fp, "이메일 : %s \n", info[i].mail);
			fclose(fp);
			printf("완료\n");		*/
		}
		if (j == 2)
			break;
	}
}
void login(struct student* info)
{
	//학번 입력받고 그에 따른 패스워드 입력받는데, 저장된 정보랑 일치해야
	char Student_ID[10];
	char password[5];

	printf("학번을 입력하십시오: ");
	scanf("%s", Student_ID);
	printf("\n 패스워드를 입력하십시오: ");
	scanf("%s", password);

	int ret = strcmp(Student_ID, password);
	if (ret == 0)
	{
		printf("로그인에 성공하였습니다.\n");
	}
	else
	{
		printf("로그인에 실패하였습니다.\n");
	}
}

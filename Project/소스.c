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
		printf("1. �л� ȸ������\n");
		printf("2. �л� ȸ����� Ȯ��\n");
		printf("3. �л� ȸ������ ����\n");
		printf("4. �ڷγ� �ڰ����� �ϱ�\n");
		printf("5. � ���� ���� �ϱ�\n");
		printf("6. ����\n");
		printf("7. �α���\n");
		printf("��ȣ�� �Է��Ͻÿ�: ");
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
		printf("ȸ�������� ��� �Ͻðڽ��ϱ�? 1.Yes 2.No\n");
		scanf("%d", &j);

		if (j == 1)
		{
			printf("�̸��� �Է��Ͻÿ�: ");
			scanf("%s", info[i].name);
			printf("\n");
			printf("�й��� �Է��Ͻÿ�: ");
			scanf("%s", info[i].ID);
			printf("\n");
			printf("��ȭ��ȣ�� �Է��Ͻÿ�: ");
			scanf("%s", info[i].call);
			printf("\n");
			printf("�̸����� �Է��Ͻÿ�: ");
			scanf("%s", info[i].mail);
			printf("\n");
			printf("��й�ȣ �Է��Ͻÿ� (4�ڸ� ����): ");
			scanf("%s", info[i].password);
			printf("\n");
			cnt++;
			/*
			FILE* fp;
			fp = fopen("C:\\Users\\dltmd\\Desktop\\������\\exampleFile.txt", "a");
			if (fp == NULL) {
				printf("���� - ����\n");
			}
			fprintf(fp, "%d. ", i+1);
			fprintf(fp, "�̸�: %s ", info[i].name);
			fprintf(fp, "�й�: %s ", info[i].ID);
			fprintf(fp, "��ȭ��ȣ: %s ", info[i].call);
			fprintf(fp, "�̸��� : %s \n", info[i].mail);
			fclose(fp);
			printf("�Ϸ�\n");		*/
		}
		if (j == 2)
			break;
	}
}
void login(struct student* info)
{
	//�й� �Է¹ް� �׿� ���� �н����� �Է¹޴µ�, ����� ������ ��ġ�ؾ߉�
	char Student_ID[10];
	char password[5];

	printf("�й��� �Է��Ͻʽÿ�: ");
	scanf("%s", Student_ID);
	printf("\n �н����带 �Է��Ͻʽÿ�: ");
	scanf("%s", password);

	int ret = strcmp(Student_ID, password);
	if (ret == 0)
	{
		printf("�α��ο� �����Ͽ����ϴ�.\n");
	}
	else
	{
		printf("�α��ο� �����Ͽ����ϴ�.\n");
	}
}
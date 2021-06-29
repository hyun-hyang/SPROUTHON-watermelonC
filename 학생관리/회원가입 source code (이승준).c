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

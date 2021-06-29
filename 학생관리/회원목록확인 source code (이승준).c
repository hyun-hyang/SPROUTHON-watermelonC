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

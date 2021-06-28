void list(struct student* info)
{
    int i, j;
    printf("1. 전체 회원정보 조회 2. 개인 회원정보 조회\n");
    scanf("%d", &i);
    
    FILE* fp;
    fp = fopen("exampleFile.txt", "r");
    char tmp;
    int cnt = 1;
    if (fp == NULL) {
        exit(0);
    }
    while (fscanf(fp, "%c", &tmp) != EOF) {
        printf("%c", tmp);
        if (tmp == '\n')
            cnt++;
    }
    return 0;
    for (int j = 0; j < cnt; j++)
    {
        fscanf(fp, "%s %s %s %s %s\n", &m[j].name, &m[j].ID, &m[j].call, &m[j].mail, &m[j].password);
        fclose(fp);
    }
    
    if (i == 1)
    {
        for (int j = 0; j < cnt; j++)
        {
            printf("이름:%s 학번:%s 전화번호:%s 이메일:%s 비밀번호:%s\n", &m[j].name, &m[j].ID, &m[j].call, &m[j].mail, &m[j].password);
        }
    }
}

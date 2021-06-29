void insert(struct student* info)
{
    char a[30], b[30];
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
    printf("수정하실 회원의 학번을 입력하시오: ");
    scanf("%s", a);
    printf("\n");
    for (i = 0; i < cnt; i++)
    {
        if (strcmp(a, m[i].ID) == 0)
        {
            while (1)
            {
                printf("수정하실 정보는 무엇입니까? 1.이름 2. 학번 3. 전화번호 4.이메일 5. 비밀번호 6. 종료: ");
                scanf("%d", &j);
            }
            if (j == 1)
            {
                printf("이름 입력: ");
                scanf("%s", m[j].name);
                printf("\n");
            }
        }
    }
}

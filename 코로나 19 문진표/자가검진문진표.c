void covid19_self_exam(struct student* info, struct survey* sur)
{
    int a1 = 0;
    int a3 = 0;
    int a4 = 0;
    int a5 = 0;
    int a2 = 0;
    puts("<설문조사>");
    printf("각 설문에 대해 문항의 답을 입력하고 Enter를 누르십시오.\n");
    printf("문항의 답은 1,2로 답해주십시오.\n");
    printf("1. 학생의 몸에 열이 있나요? 1)37.5℃미만 2)37.5℃이상 및 발열감 ");
    scanf("%d\n", &a1);
    printf("2. 귀하에게 코로나19가 의심되는 증상이 있나요? 1)아니요 2)예 ");
    scanf("%d\n", &a2);
    printf("3. 귀하는 최근(14일 이내)해외여행을 다녀온 사실이 있나요? 1)아니요 2)예 ");
    scanf("%d\n", &a3);
    printf("4. 동거가족 중 최근(14일 이내) 해외여행을 다녀온 사실이 있나요? (단, 국제선 항공기 및 선박 승무원 등 직업특성상 매번 해외 입출국하고 의심증상이 없는 경우는 제외) 1)아니요 2)예 ");
    scanf("%d\n", &a4);
    printf("5. 동거가족 중 현재 자가격리 중인 가족이 있나요? 1)아니요 2)예 ");
    scanf("%d\n", &a5);
    printf("설문이 완료되었습니다.\n");
    printf("답변: %d, %d, %d, %d, %d\n\n", a1, a2, a3, a4, a5);
    if (a1 + a2 + a3 + a4 + a5 != 5)
    {
        printf("등교 불\n");
    }
    else
        printf("등교 가능\n");
    FILE* fp;
    fp = fopen("name_id.txt", "a");
    if (fp == NULL) {
        printf("실패 - 종료\n");
    }
    fprintf(fp, "1번: %d ", a1);
    fprintf(fp, "2번: %d ", a2);
    fprintf(fp, "3번: %d ", a3);
    fprintf(fp, "4번: %d ", a4);
    fprintf(fp, "5번: %d \n", a5);
    fclose(fp);
    printf("완료\n");
}

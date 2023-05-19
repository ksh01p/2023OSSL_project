#include "TeamProject.h"


int selectMenu(){
    int menu;
    printf("\n*** 학생 정보 관리 시스템 ***\n");
    printf("*                           *\n");
    printf("*     1. 학생 정보 조회     * \n");
    printf("*     2. 학생 정보 추가     * \n");
    printf("*     3. 학생 정보 수정     * \n");
    printf("*     4. 학생 정보 삭제     * \n");
    printf("*     5. 학생 정보 검색     * \n");
    printf("*     6. 학생 파일 저장     * \n");
    printf("*     7. 학생 파일 불러오기 * \n");
    printf("*     0. 종료               * \n");
    printf("*                           *\n");
    printf("* * * * * * * * * * * * * * *\n");
    printf("\n>> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}//(v)

int add_the_stu(student *a,int n){
    printf("학생 이름을 입력하세요 : ");
    scanf("%s",a[n].name);
    printf("학번을 입력하세요 : ");
    scanf("%d",&a[n].student_number);
    printf("학생 성별을 입력하세요 : ");
    scanf("%s",a[n].gender);
    printf("학생 나이를 입력하세요 : ");
    scanf("%d",&a[n].age);
    printf("학생 소속 RC를 입력히세요 : ");
    scanf("%s",a[n].rc);
    printf("학생 소속 기숙사를 입력히세요 : ");
    scanf("%s",a[n].building);
    printf("한동 대학교 이메일을 입력히세요 : ");
    scanf("%s",a[n].email);
    printf("학생 개인 전화번호를 입력히세요 : ");
    scanf("%d",&a[n].phone);
    printf("학생 전공을 입력히세요 : ");
    scanf("%s",a[n].major);
    printf("\n>> 입력완료했습니다. 감사합니다.\n");

    return 1;
}//(v)

void read_stu(student *a){
    printf("%s  %d  %s    %d   %s   %s    %s     %d     %s\n",a->name, a->student_number, a->gender, a->age, a->rc, a->building,a->email,a->phone,a->major);
}//(v)

void show_all_stu(student *a,int n){
    if(n==0) printf(">> 저장된 학생이 없습니다.\n");
    else {
      printf("- - - - - - - - - - - - - - - - - 학생 정보 - - - - - - - - - - - - - - - - -\n");
      printf("   이름    학번      성별  나이  RC     기숙사      전공        이메일        전화번호\n");
      for(int i=0;i<n;i++){
          printf("%2d ", i + 1);
          read_stu(&a[i]);
      }
    }
    
}//(v)

int update_the_stu(student *a, int n){
    if(n==0){
        printf(">> 저장된 학생이 없습니다.\n");
        return 0;
    }

    char studentName[20];
    printf("수정할 학생의 이름을 입력하세요: ");
    scanf("%s", studentName);

    int foundIndex = -1;
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].name, studentName) == 0){
            foundIndex = i;
            break;
        }
    }

    if(foundIndex == -1){
        printf(">> 입력한 이름과 일치하는 학생이 없습니다.\n");
        return 0;
    }

    printf("수정할 학생 학번을 입력하세요: ");
    scanf("%d", &a[foundIndex].student_number);
    printf("수정할 학생 성별을 입력하세요: ");
    scanf("%s", a[foundIndex].gender);
    printf("수정할 학생 나이를 입력하세요: ");
    scanf("%d", &a[foundIndex].age);
    printf("수정할 학생 소속 RC를 입력하세요: ");
    scanf("%s", a[foundIndex].rc);
    printf("수정할 학생 소속 기숙사를 입력하세요: ");
    scanf("%s", a[foundIndex].building);
    printf("수정할 학생 이메일을 입력하세요: ");
    scanf("%s", a[foundIndex].email);
    printf("수정할 학생 개인번호를 입력하세요: ");
    scanf("%d", &a[foundIndex].phone);
    printf("수정할 학생 전공을 입력하세요: ");
    scanf("%s", a[foundIndex].major);

    printf("\n>> 수정이 완료되었습니다.\n");
    return 1;
}//(v)

void find_by_name(student *a,int n){
    char name[10];
    printf("찾는 학생의 이름을 입력하세요 : ");
    scanf("%s",name);
    for(int i=0;i<n;i++){
        if(strcmp(a[i].name,name)==0){
            printf("- - - - - - - - - - - - - - - - - 학생 정보 - - - - - - - - - - - - - - - - -\n");
            printf("   이름    학번      성별  나이  RC     기숙사      전공        이메일        전화번호\n");
            printf("   ");
            read_stu(&a[i]);
            break;
        }
        else printf(">> 찾는 학생이 없습니다.\n");
      }
    
}//(v)

void find_by_student_num(student *a,int n){
    if(n==0) printf(">> 저장된 학생이 없습니다.\n");
    else {
      int std_id[10];
      printf("찾는 학생의 학번을 입력하세요 : ");
      scanf("%d",&(*std_id));
      for(int i=0;i<n;i++){
          if(a[i].student_number == *std_id){
            printf("- - - - - - - - - - - - - - - - - 학생 정보 - - - - - - - - - - - - - - - - -\n");
            printf("   이름    학번      성별  나이  RC     기숙사      전공        이메일        전화번호\n");
            printf("   ");
            read_stu(&a[i]);
            break;
          }
          else printf(">> 찾는 학생이 없습니다.\n");
      }
    }
}//(v)



void find_by_age(student *a, int n) {
    int age;
    printf("찾는 학생의 나이를 입력하세요: ");
    scanf("%d", &age);
    printf("- - - - - - - - - - - - - - - - - 학생 정보 - - - - - - - - - - - - - - - - -\n");
            printf("   이름    학번      성별  나이  RC     기숙사      전공        이메일        전화번호\n");
    int found = 0; 
    for (int i = 0; i < n; i++) {
        if (a[i].age == age) {
            printf("   ");
            read_stu(&a[i]);
            found = 1;
        }
    }
    if (!found) {
        printf(">> 찾는 학생이 없습니다.\n");
    }
}//(v)



void find_by_rc(student *a, int n) {
    char rc[10];
    printf("찾는 학생의 RC를 입력하세요: ");
    scanf("%s", rc);
    printf("- - - - - - - - - - - - - - - - - 학생 정보 - - - - - - - - - - - - - - - - -\n");
            printf("   이름    학번      성별  나이  RC     기숙사      전공        이메일        전화번호\n");
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].rc, rc) == 0) {
            printf("   ");
            read_stu(&a[i]);
            found = 1;
        }
    }

    if (!found) {
        printf(">> 찾는 학생이 없습니다.\n");
    }
}//(v)




void find_by_email(student *a, int n) {
    char email[100];
    printf("찾는 학생의 email을 입력하세요: ");
    scanf("%s", email);
    printf("- - - - - - - - - - - - - - - - - 학생 정보 - - - - - - - - - - - - - - - - -\n");
    printf("   이름    학번      성별  나이  RC     기숙사      전공        이메일        전화번호\n");
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].email, email) == 0) {
            printf("   ");
            read_stu(&a[i]);
            found = 1;
        }
    }

    if (!found) {
        printf(">> 찾는 학생이 없습니다.\n");
    }
}//(v)


void find_by_major(student *a, int n) {
    char major[10];
    printf("찾는 학생의 전공을 입력하세요: ");
    scanf("%s", major);
    printf("- - - - - - - - - - - - - - - - - 학생 정보 - - - - - - - - - - - - - - - - -\n");
    printf("   이름    학번      성별  나이  RC     기숙사      전공        이메일        전화번호\n");
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].major, major) == 0) {
            printf("   ");
            read_stu(&a[i]);
            found = 1;
        }
    }

    if (!found) {
        printf(">> 찾는 학생이 없습니다.\n");
    }
}//(v)



void find_by_phone(student *a,int n){
    if(n==0) printf(">> 저장된 학생이 없습니다.\n");
    else {
      int phone[10];
      printf("찾는 학생의 학번을 입력하세요 : ");
      scanf("%d",&(*phone));
      for(int i=0;i<n;i++){
          if(a[i].phone == *phone){
            printf("- - - - - - - - - - - - - - - - - 학생 정보 - - - - - - - - - - - - - - - - -\n");
            printf("   이름    학번      성별  나이  RC     기숙사      전공        이메일        전화번호\n");
            printf("   ");
            read_stu(&a[i]);
            break;
          }
          else printf(">> 찾는 학생이 없습니다.\n");
      }
    }
}//(v)





int delete_the_stu(student *a, int n) {
    if (n == 0) {
        printf(">> 저장된 학생이 없습니다.\n");
        return n;
    }

    char studentName[20];
    printf("삭제할 학생의 이름을 입력하세요: ");
    scanf("%s", studentName);

    int foundIndex = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].name, studentName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf(">> 입력한 이름과 일치하는 학생이 없습니다.\n");
        return n;
    }

    for (int j = foundIndex; j < n - 1; j++) {
        a[j] = a[j + 1];
    }

    printf(">> 학생 정보가 삭제되었습니다.\n");
    return n - 1;
}



void save_the_stu(student *a, int n) {
    FILE *fp;
    fp = fopen("datalist.txt", "wt");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s\n", a[i].name);
        fprintf(fp, "%d\n", a[i].student_number);
        fprintf(fp, "%s\n", a[i].gender);
        fprintf(fp, "%d\n", a[i].age);
        fprintf(fp, "%s\n", a[i].rc);
        fprintf(fp, "%s\n", a[i].building);
        fprintf(fp, "%s\n", a[i].email);
        fprintf(fp, "%d\n", a[i].phone);
        fprintf(fp, "%s\n", a[i].major);
    }
    fclose(fp);
    printf(">> 성공적으로 저장되었습니다!");
}



int load_the_stu(student *a, int n) {
    FILE *fp;
    fp = fopen("datalist.txt", "rt");

    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%s\n", a[i].name);
        fscanf(fp, "%d\n", &a[i].student_number);
        fscanf(fp, "%s\n", a[i].gender);
        fscanf(fp, "%d\n", &a[i].age);
        fscanf(fp, "%s\n", a[i].rc);
        fscanf(fp, "%s\n", a[i].building);
        fscanf(fp, "%s\n", a[i].email);
        fscanf(fp, "%d\n", &a[i].phone);
        fscanf(fp, "%s\n", a[i].major);
        i++;
    }
    fclose(fp);
    printf("\n>> 성공적으로 불러왔습니다!\n");
    return i;
}




/*
5/8(월) 수정 내용 (KSH) 
1. 학생 출력 시 간격 없이 연달아 출력하여서 \n 을 추가하여 가독성을 용이하게 함
2. 학생 정보 삭제 구현 완료 (delete_the_stu) 
3. 학생 검색 함수(find_the_stu)에서 학번 뒤에 \n 을 붙여서 가독서을 용이하게 함
*/

/*
5/9(화) 수정 내용 (KSH) 
1. 학생 검색(find_the_stu)과 학생 출력(show_all/_stu)에서 가독성을 위해서 세로 출력에서 가로로 출력으로 변경함.
2. 학생 출력(show_all/_stu)에서 저장된 학생이 없을 때 출력하는 문구 밑에 \n을 추가함.
3. 학생 검색(find_the_stu)에서 검색한 학생이 존재하지 않을 경우에 검색한 학생이 존재하지 않다고 flag를 이용해서 출력함.

*/

/*
5/9(화) 수정 내용 (KMS)
1. #define SIZE의 내용 수정
2. 계획한 모든 함수 정의
3. 내용별 찾기 함수 정의 및 내용 구현
4. 한 학생의 조회 함수와 모든 학생 조회 함수를 따로 구현
5. 메뉴창 수정
+
6. 학생 정보 검색 관련 모든 함수 구현 완료
7. 학생 정보 검색 메뉴를 숫자로 먼저 입력해 검색할 수 있도록 만듬
*/

/*
5/11(목) 수정 내용(KSH)
1. team_in_age 구현중 
    <디버깅 해야 하는 항목>
    - 중복 없이 난수 생성하는 방법
    - 2번 실행 시 bus error
2. delete_the_stu 디버깅중
    <디버깅 해야 하는 항목>
    - 삭제 시, int 데이터 타입은 '0'라고 명시된다.
*/

/*
5/15() 수정 내용 (KMS)
1. update_the_stu, load_the_stu 함수 구현 완료
2. save_the_stu, find_by_age, find_by_rc 함수 수정 완료
3. delete_the_stu 구현 완료
*/

/*
5/16(화) 수정 내용(KSH)
1. load_the_file 구현 완료
2. datalist.txt 파일에 미리 학생정보 기입함
3. FileIO 확인(불러오기 후 추가 후 저장 시 실제 txt에 저장되는 지 ) 완료
==> 정상 작동
4. 구조체 안에 학생 개인 이메일, 전화번호 그리고 전공을 추가했습니다.
==> 구조체 안에 새로운 인적사항들을 모든 함수에 다시 적용했습니다.

*/
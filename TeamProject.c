#define SIZE 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h> //srand, rand를 사용하기 위한 헤더파일
#include <time.h> // time을 사용하기 위한 헤더파일


typedef struct{
    char name[20];
    int student_number;
    char gender[2];
    int age;
    char rc[20];
    char building[20];
    }student;
    // 학사 정보를 위한 구조체 


int selectMenu(); // 메뉴 선택 함수
int add_the_stu(student *a,int n); // 학생 정보 추가 함수
void read_stu(student *a); // 한 학생의 정보 조회 함수
void show_all_stu(student *a,int n); // 모든 학생 정보 조회 함수
int update_the_stu(student *a, int n); // 학생 정보 수정
int delete_the_stu( student *a,int n); // 학생 장보 삭제

void find_by_name(student *a,int n); // 학생 이름으로 정보 검색
void find_by_student_num(student *a,int n); // 학생 학번으로 정보 검색
void find_by_age(student *a,int n); // 학생 나이로 정보 검색
void find_by_rc(student *a,int n); // 학생 RC로 정보 검색

void save_the_stu(student *a,int n); // 학생 파일 저장
int load_the_stu(student *a, int n); // 저장된 학생 정보 불러오기

void team_in_age(student *a,int n, int n1, int n2); // 나이로 분류하여 팀 만들기


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
    printf("*     7. 나이로 팀 만들기   * \n");
    printf("*     0. 종료               * \n");
    printf("*                           *\n");
    printf("* * * * * * * * * * * * * * *\n");
    printf("\n>> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

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
    printf("\n>> 입력완료했습니다. 감사합니다.\n");

    return 1;
}

void read_stu(student *a){
    printf("%s  %d  %s    %d   %s   %s\n",a->name, a->student_number, a->gender, a->age, a->rc, a->building);
}

void show_all_stu(student *a,int n){
    if(n==0) printf(">> 저장된 학생이 없습니다.\n");
    else {
      printf("- - - - - - - - - - 학생 정보 - - - - - - - - - -\n");
      printf("   이름    학번      성별  나이  RC     기숙사\n");
      for(int i=0;i<n;i++){
          printf("%2d ", i + 1);
          read_stu(&a[i]);
      }
    }
    
}

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

    printf("\n>> 수정이 완료되었습니다.\n");
    return 1;
}

void find_by_name(student *a,int n){
    char name[10];
    printf("찾는 학생의 이름을 입력하세요 : ");
    scanf("%s",name);
    for(int i=0;i<n;i++){
        if(strcmp(a[i].name,name)==0){
            printf("- - - - - - - - - - 학생 정보 - - - - - - - - - -\n");
            printf("   이름    학번      성별  나이  RC     기숙사\n");
            printf("   ");
            read_stu(&a[i]);
            break;
        }
        else printf(">> 찾는 학생이 없습니다.\n");
      }
    
}

void find_by_student_num(student *a,int n){
    if(n==0) printf(">> 저장된 학생이 없습니다.\n");
    else {
      int std_id[10];
      printf("찾는 학생의 학번을 입력하세요 : ");
      scanf("%d",&(*std_id));
      for(int i=0;i<n;i++){
          if(a[i].student_number == *std_id){
            printf("- - - - - - - - - - 학생 정보 - - - - - - - - - -\n");
            printf("   이름    학번      성별  나이  RC     기숙사\n");
            printf("   ");
            read_stu(&a[i]);
            break;
          }
          else printf(">> 찾는 학생이 없습니다.\n");
      }
    }
}

void find_by_age(student *a, int n) {
    int age;
    printf("찾는 학생의 나이를 입력하세요: ");
    scanf("%d", &age);
    printf("- - - - - - - - - - 학생 정보 - - - - - - - - - -\n");
    printf("   이름    학번      성별  나이  RC     기숙사\n");
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
}

void find_by_rc(student *a, int n) {
    char rc[10];
    printf("찾는 학생의 RC를 입력하세요: ");
    scanf("%s", rc);
    printf("- - - - - - - - - - 학생 정보 - - - - - - - - - -\n");
    printf("   이름    학번      성별  나이  RC     기숙사\n");
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
}

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
        fprintf(fp, "%d.\n", i + 1);
        fprintf(fp, "%s\n", a[i].name);
        fprintf(fp, "%d\n", a[i].student_number);
        fprintf(fp, "%s\n", a[i].gender);
        fprintf(fp, "%d\n", a[i].age);
        fprintf(fp, "%s\n", a[i].rc);
        fprintf(fp, "%s\n", a[i].building);
    }
    fclose(fp);
    printf(">> 성공적으로 저장되었습니다!");
}

int load_the_stu(student *a, int n) {
    FILE *fp;
    fp = fopen("datalist.txt", "rt");

    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%*d.\n");
        fscanf(fp, "%s\n", a[i].name);
        fscanf(fp, "%d\n", &a[i].student_number);
        fscanf(fp, "%s\n", a[i].gender);
        fscanf(fp, "%d\n", &a[i].age);
        fscanf(fp, "%s\n", a[i].rc);
        fscanf(fp, "%s\n", a[i].building);
        i++;
    }
    fclose(fp);
    return i;
}

void team_in_age(student *a,int n , int n1, int n2){
    /*
    a,count,age,team_num
    a,  n  ,n1 , n2
    */
    student slist[n2];
    //int count_0=0;//출력을 끝내기 위한 index
    int index=0;//list의 index
    int random[n2];
    for(int i=0;i<n;i++){
        /*if(count_0==n2){
            printf("---------출력완료---------");
            break;
        }*/
        if(n<n2){
            printf("학생 수가 구성원 수보다 적습니다!");
            break;
        }
        else if(a[i].age==n1){
            slist[index].age=a[i].age;
            slist[index].student_number=a[i].student_number;
            strcpy(slist[index].name,a[i].name);
            strcpy(slist[index].gender,a[index].gender);
            strcpy(slist[index].rc,a[index].rc);
            strcpy(slist[index].building,a[index].building);
            index++;
            //count_0++;
            }
        }
            srand((unsigned)time(NULL));
            printf("- - - - - - - - - - 학생 정보 - - - - - - - - - -\n");
            printf("   이름    학번      성별  나이  RC     기숙사\n");
            printf("   ");
            for(int j=0;j<n2;j++){
                random[j]=rand()%index;
                /*for(int k =0 ;j<k;k++){
                    if(random[j]==random[k]) {
                        
                        j--;
                    }*/
                    
                        //printf("%d\n",random[j]);
                        read_stu(&slist[random[j]]);
                    
            }
                
        }
        

int main() {
    int Menu = 0;
    student a[1000];
    int count = 0;
    int semister = 0;

    count = load_the_stu(a, count);

    if (count == 0) {
        printf(">> 파일에 저장된 학생이 없습니다.\n");
        printf(">> 학생 정보를 불러오는 데 실패했습니다.\n");
    } else {
        printf(">> 성공적으로 학생 정보를 불러왔습니다.\n");
    }

    while (1) {
        Menu = selectMenu();
        if (Menu == 1) {
            show_all_stu(a, count);
        }
        else if (Menu == 2) {
            add_the_stu(a, count);
            count++;
        }
        else if (Menu == 3) {
            update_the_stu(a, count);
        }
        else if (Menu == 4) {
            count = delete_the_stu(a, count);
        }
        else if (Menu == 5) {
            if (count == 0) {
                printf(">> 저장된 학생이 없습니다.\n");
            }
            else {
                int num;
                printf("[1: 이름] [2: 학번] [3: 나이] [4: RC]\n");
                printf("무엇으로 검색하시겠습니까? [숫자입력]: ");
                scanf("%d", &num);
                if (num == 1)
                    find_by_name(a, count);
                else if (num == 2)
                    find_by_student_num(a, count);
                else if (num == 3)
                    find_by_age(a, count);
                else if (num == 4)
                    find_by_rc(a, count);
                else
                    printf("잘못된 입력입니다. 다시 입력해주세요.\n");
            }
        }
        else if (Menu == 6) {
            save_the_stu(a, count);
        }
        else if (Menu == 7) {
            int age = 0;
            int team_num = 0;
            printf("팀으로 만들고 싶은 나이를 입력하세요  : ");
            scanf("%d", &age);
            printf("팀 구성원의 수를 입력하세요 : ");
            scanf("%d", &team_num);
            team_in_age(a, count, age, team_num);
        }
        else if (Menu == 0) {
            printf(">> 프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }

    return 0;
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
5/15(화) 수정 내용 (KMS)
1. update_the_stu, load_the_stu 함수 구현 완료
2. save_the_stu, find_by_age, find_by_rc 함수 수정 완료
3. delete_the_stu 구현 완료
*/

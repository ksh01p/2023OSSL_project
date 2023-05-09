#define SIZE 100
#include <stdio.h>
#include <string.h>


typedef struct{
    char name[20];
    int student_number;
    char gender[2];
    int age;
    char rc[20];
    char building[20];
    }student;
    // 구조체 
    
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
    printf("*     2. 힉생 정보 추가     * \n");
    printf("*     3. 학생 정보 삭제     * \n");
    printf("*     4. 학생 파일 저장     * \n");
    printf("*     5. 학생 검색          * \n");
    printf("*     6. 나이로 팀 만들기   * \n");
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
    printf("\n==> 입력완료했습니다. 감사합니다\n");

    return 1;
}

void read_stu(student *a){
    printf("%s  %d  %s    %d   %s   %s\n",a->name, a->student_number, a->gender, a->age, a->rc, a->building);
}

void show_all_stu(student *a,int n){
    if(n==0) printf("\n ==>저장된 학생이 없습니다.");
    printf("- - - - - - - - - - 학생 정보 - - - - - - - - - -\n");
    printf("   이름    학번      성별  나이  RC     기숙사\n");
    for(int i=0;i<n;i++){
        printf("%2d ", i + 1);
        read_stu(&a[i]);
    }
    
}

int update_the_stu(student *a, int n){
  return 1;
}

void find_by_name(student *a,int n){
    char name[10];
    printf("찾는 학생의 이름을 입력하세요 : ");
    scanf("%s",name);
    for(int i=0;i<n;i++){
        if(strcmp(a[i].name,name)==0){
            printf("이름: %s\n",a[i].name);
            printf("학번 : %d\n",a[i].student_number);
            printf("성별 : %s\n",a[i].gender);
            printf("나이 : %d\n",a[i].age);
            printf("RC : %s\n",a[i].rc);
            printf("기숙사 : %s\n",a[i].building);
        }
    }
}

void find_by_student_num(student *a,int n){
    int std_id[10];
    printf("찾는 학생의 이름을 입력하세요 : ");
    scanf("%d",&(*std_id));
    for(int i=0;i<n;i++){
        if(a[i].student_number == *std_id){
            printf("이름: %s\n",a[i].name);
            printf("학번 : %d\n",a[i].student_number);
            printf("성별 : %s\n",a[i].gender);
            printf("나이 : %d\n",a[i].age);
            printf("RC : %s\n",a[i].rc);
            printf("기숙사 : %s\n",a[i].building);
        }
    }
}

void find_by_age(student *a,int n){
    int age[5];
    printf("찾는 학생의 이름을 입력하세요 : ");
    scanf("%d",age);
    for(int i=0;i<n;i++){
        if(a[i].age == *age){
            printf("이름: %s\n",a[i].name);
            printf("학번 : %d\n",a[i].student_number);
            printf("성별 : %s\n",a[i].gender);
            printf("나이 : %d\n",a[i].age);
            printf("RC : %s\n",a[i].rc);
            printf("기숙사 : %s\n",a[i].building);
        }
    }
}

void find_by_rc(student *a,int n){
    char rc[10];
    printf("찾는 학생의 이름을 입력하세요 : ");
    scanf("%s",rc);
    for(int i=0;i<n;i++){
        if(strcmp(a[i].rc,rc)==0){
            printf("이름: %s\n",a[i].name);
            printf("학번 : %d\n",a[i].student_number);
            printf("성별 : %s\n",a[i].gender);
            printf("나이 : %d\n",a[i].age);
            printf("RC : %s\n",a[i].rc);
            printf("기숙사 : %s\n",a[i].building);
        }
    }
}

int delete_the_stu(student *a,int n){
    char name[10];
    printf("찾는 학생의 이름을 입력하세요 : ");
    scanf("%s",name);
    for(int i=0;i<n;i++){
        if(strcmp(a[i].name,name)==0){
            memcpy( &a[i], &a[i+1], sizeof( student ) );
        }
    }
    
    return 1;
}

void save_the_stu(student *a,int n){
    FILE *fp;
    fp=fopen("datalist.txt","wt");
    for(int i=0;i<n;i++){
        fscanf(fp,"%d. \n",&i);
        fscanf(fp,"%s\n",a[n].name);
        fscanf(fp,"%d\n",&a[n].student_number);
        fscanf(fp,"%s\n",a[n].gender);
        fscanf(fp,"%d\n",&a[n].age);
        fscanf(fp,"%s\n",a[n].rc);
        fscanf(fp,"%s\n",a[n].building);
    }   
}

void team_in_age(student *a,int n, int n1, int n2){
    int count_0=0;
    int index=0;
    while(1){
        if(n<n2){
            printf("학생 수가 구성원 수보다 적습니다!");
            break;
        }
        else if(count_0>n2){
            printf("이상 , 팀원입니다. 감사합니다!");
        }
        if(a[index].age==n1){
            
            count_0++;
            printf("%s",a[index].name);
            index++;
        }
    }
}


int main(){
    int Menu=0;
    student a[1000];
    int count=0;
    while(1){
        Menu=selectMenu();
        if(Menu==1){
                show_all_stu(a,count);
                
            }
        else if(Menu == 2){
                add_the_stu(a,count);
                count++;
            }
        else if(Menu == 3){
                delete_the_stu(a,count);
                count--;
            }
        else if(Menu == 4){
                save_the_stu(a,count);
            }
        else if(Menu == 5){
                find_by_name(a,count);
            }
        else if(Menu == 6){
            int age=0;
            int team_num=0;
            printf("팀으로 만들고 싶은 나이를 입력하세요  : ");
            scanf("%d",&age);
            printf("팀 구성원의 수를 입력하세요 : ");
            scanf("%d",&team_num);
            team_in_age(a,count,age,team_num);
            
        }
        else if(Menu == 0){
                printf("\n>> 종료!\n");
                break;
        }
    }
}



/*
5/8 수정 내용 - 
1. 학생 출력 시 간격 없이 연달아 출력하여서 \n 을 추가하여 가독성을 용이하게 함
2. 학생 정보 삭제 구현 완료 (delete_the_stu) 
3. 학생 검색 함수(find_the_stu)에서 학번 뒤에 \n 을 붙여서 가독서을 용이하게 함
*/

/*
5/9 수정 내용
1. #define SIZE의 내용 수정
2. 계획한 모든 함수 정의
3. 내용별 찾기 함수 정의 및 내용 구현
4. 한 학생의 조회 함수와 모든 학생 조회 함수를 따로 구현
5. 메뉴창 수정
*/

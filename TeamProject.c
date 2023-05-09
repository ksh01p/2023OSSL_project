#define SIZE 100;
#include <stdio.h>
#include <string.h>


typedef struct{
        int student_number;
        char name[20];
        char gender[2];
        int age;
        char rc[20];
        char building[20];
    }student;

int selectMenu();//메뉴 선택 함스
void find_the_stu(student *a,int n);//학생 정보 검색
void show_all_stu(student *a,int n);//학생 정보 조회
int add_the_stu(student *a,int n);//학생 정보 추가
int delete_the_stu( student *a,int n);//학생 장버 삭제
void save_the_stu( student *a,int n);//학생 파일 저장
void team_in_age(student *a,int n, int n1, int n2);//나이로 분류하여 팀 만들기

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 학생 정보 조회  ");
    printf("2. 힉생 정보 추가  ");
    printf("3. 학생 정보 삭제  ");
    printf("4. 학생 파일 저장  ");
    printf("5. 학생 검색 ");
    printf("6. 나이로 팀 만들기 ");
    printf("0. 종료 ");
    printf(" >> ");
    scanf("%d", &menu);
    return menu;
}

void find_the_stu(student *a,int n){
    char name[10];
    int flag=0;
    printf("찾는 학생의 이름을 입력하세요 : ");
    scanf("%s",name);
    for(int i=0;i<n;i++){
        if(strcmp(a[i].name,name)==0){
            printf("이름: %s  //  ",a[i].name);
            printf("학번 : %d  //  ",a[i].student_number);
            printf("성별 : %s  //  ",a[i].gender);
            printf("나이 : %d  //  ",a[i].age);
            printf("RC : %s  //  ",a[i].rc);
            printf("기숙사 : %s  \n",a[i].building);
            flag++;
        }
    }
    if(flag==0){
        printf("검색한 학생은 존재하지 않습니다.\n");
    }
}


void show_all_stu(student *a,int n){
    if(n==0) printf("\n ==>저장된 학생이 없습니다.\n");
    for(int i=0;i<n;i++){
            printf("이름: %s  //  ",a[i].name);
            printf("학번 : %d  //  ",a[i].student_number);
            printf("성별 : %s  //  ",a[i].gender);
            printf("나이 : %d  //  ",a[i].age);
            printf("RC : %s  //  ",a[i].rc);
            printf("기숙사 : %s  \n",a[i].building);
            
    }
    
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
                find_the_stu(a,count);
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
                printf("\n==>종료!\n");
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
5/9 수정 내용-
1. 학생 검색(find_the_stu)과 학생 출력(show_all/_stu)에서 가독성을 위해서 세로 출력에서 가로로 출력으로 변경함.
2. 학생 출력(show_all/_stu)에서 저장된 학생이 없을 때 출력하는 문구 밑에 \n을 추가함.
3. 학생 검색(find_the_stu)에서 검색한 학생이 존재하지 않을 경우에 검색한 학생이 존재하지 않다고 flag를 이용해서 출력함.

*/
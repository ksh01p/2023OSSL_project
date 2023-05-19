#define SIZE 1000
#include "TeamProject.h"

int main() {
    int Menu = 0;
    student a[SIZE];
    int count = 0;
    int semister = 0;

    count = load_the_stu(a, count);

    if (count == 0) {
        printf(">> 파일에 저장된 학생이 없습니다.\n");
        printf(">> 학생 정보를 불러오는 데 실패했습니다.\n");
    } else {
        //printf(">> 성공적으로 학생 정보를 불러왔습니다.\n");
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
                printf("[1: 이름] [2: 학번] [3: 나이] [4: RC] [5: Email] [6: 전화번호] [7: 전공] \n");
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
                else if (num == 5)
                    find_by_email(a, count);
                else if (num == 6)
                    find_by_phone(a, count);
                else if (num == 7)
                    find_by_major(a, count);
                else
                    printf("잘못된 입력입니다. 다시 입력해주세요.\n");
            }
        }

        else if (Menu == 6) {
            save_the_stu(a, count);
        }

        else if(Menu == 7){
            count=load_the_stu(a,count);
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

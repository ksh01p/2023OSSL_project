#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int student_number;
    char gender[2];
    int age;
    char rc[20];
    char building[20];
    char email[100];
    char major[100];
    int phone;

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
void find_by_major(student *a, int n);// 학생 전공으로 정보 검색
void find_by_phone(student *a,int n);// 학생 번호로 정보 검색
void find_by_email(student *a, int n);// 학생 이메일로 정보 검색

void save_the_stu(student *a,int n); // 학생 파일 저장
int load_the_stu(student *a, int n); // 저장된 학생 정보 불러오기




# MiniProject
<div align="center">
<p align="center"><img src="https://cdn.pixabay.com/photo/2019/09/27/13/23/business-4508503_1280.jpg" height="300px" width="500px"></p>

 ### Welcome, This is Han Manage
 <img src="https://img.shields.io/badge/HTML-E34F26?style=flat-square&logo=HTML5&logoColor=white"/>
 <img src="https://img.shields.io/badge/C-00CCFF?style=flat-square&logo=C&logoColor="white"/>
 <img src="https://img.shields.io/badge/VisualStudioCode-0000FF?style=flat-square&logo=VisualStudioCode&logoColor="black"/>
                                                                                                            
 
</div>
  
## 🏢 Han Manage 주제
 - 한동대학교 학생들의 정보를 관리하는 프로그램 

<br/>

## 🏢 Han Manage에 대한 소개
  - 복잡한 학생 정보를 간편하게 관리해주는 Han Manage 입니다. 
  - 간단한 입력을 통하여 학생 정보를 정리해줍니다.
  - 한 정보만으로 학생의 모든 정보를 찾아볼 수 있습니다.

<br/>
  
##  🏢 Han Manage가 가지고 있는 대략적인 기능 설명
  - 학생 정보 추가 기능
  - 학생 정보 수정 기능 
  - 학생 정보 삭제 기능
  - 학생 정보 검색 기능

<br/>

## 🏢 Han Manage CRUD
> 코드 및 기능
```c
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

```

<br/>

## 🏢 개발환경 및 언어
  - git 
  - vs code
  - C

<br/>

## 🏢 팀소개 및 팀원이 맡은 역할
### 팀원
 #### 김수형 [ksh01p GITHUB LINK](https://github.com/ksh01p)
  - Repo Owner
  - 부가기능 구현
  - WIKI 관리
  - 코드 관리 (오류수정)

<br/>

#### 김민서 [meomeking2 GITHUB LINK](https://github.com/meomeoking2)
 - Contributer
 - CRUD 구현
 - 코드 관리 (오류수정)

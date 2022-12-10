#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 40
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma warning(disable:6031)

void seatStatus(int a[]);
void ageTable();
void timetable1();
void train();
void set();
void rail();


int main() {
    srand((unsigned int)time(NULL));//난수 생성(랜덤 예매 기능에 사용
    int pay;//결제 딜레이 변수
    int seat[SIZE] = { 0 };   // 40개 좌석에 대한 변수를 선언하고 0으로 초기화 해준다.
    char menu[10] = { 0 };//메뉴 선택 문자열 변수
    int buy_menu;//예매 옵션 정수 변수
    int ny, nm, nd;//연도, 달, 날 변수 생성
    int tmp, number, age;//좌석, 나이 변수 생성
    int st_time;//시간대 선택 변수 생성
    char line;//좌석 라인 변수 생성
    struct tm* t;
    time_t base = time(NULL);
    t = localtime(&base);//현재 날짜를 출력해줄 변수 생성
    int seatfull = 1;//좌석이 꽉 차있는지 보여줄 변수 생성하고 1로 설정
    int p_number, p;//다인 예매에 사용할 변수
    int key;//키보드 입력시 다음으로 넘어가게할 변수

    ny = t->tm_year + 1900;//연도
    nm = t->tm_mon + 1;//달
    nd = t->tm_mday;//날

    set();//콘솔창 이름과 크기 설정
    train();//기차 출력

    printf("                                                                               DoRail (시작하려면 'space bar'를 누르세요)\n");
    while (1) {//스페이스바 누르면 넘어감

        if (kbhit()) {
            key = getch();
            if (key == 32) {
                system("cls");
                break;
            }


        }
    }

        while (1) {
            seatfull = 1;
            printf("\nDorail 예매 시스템에 오신 것을 환영합니다.\n");
            printf("\n[1] 승차권 예매\t[2] 좌석 조회\t[3] 승차권 확인\t[4] 취소/변경 [5] Dorail 종료\n");
            printf("메뉴 선택 : ");
            scanf(" %s", &menu);//메뉴 입력

            if (menu[3] != '\0')  // 널 체크
                for (int i = 0; i < strlen(menu); i++)
                {
                }

            if (strcmp(menu, "1") == 0) {//메뉴가 1일 경우 실행
                for (int a = 0; a < 40; a++) {
                    if (seat[a] == 0) {//seat에 빈자리가 있을경우 seatfull을 0으로
                        seatfull = 0;
                    }
                }

                if (seatfull == 1) {//seatfull이 0이 되지 않았으면 실행
                    printf("예매할 좌석이 없습니다.\n");
                    continue;
                }

                while (1) {
                    printf("\n예매 옵션을 선택해주세요\n");
                    printf("\n[1] 1인 예매\t[2] 다인 예매\t[3] 랜덤 예매\t[4] 돌아가기\n");
                    printf("메뉴 선택 : ");
                    scanf("%d", &buy_menu);//예매 메뉴 입력
                    switch (buy_menu) {
                    case 1: //buy_menu가 1이면 실행
                        printf("\n1인 예매 옵션이 선택되었습니다.\n");
                        printf("\n");
                        timetable1();//시간대 테이블 출력

                        while (1) {
                            printf("시간대를 선택하세요: ");
                            scanf_s("%d", &st_time);//시간대 메뉴 입력
                            switch (st_time) {
                            case 1: printf("\n1) 05:15 - 07:49 시간대가 선택되었습니다\n\n");//1이면 출력
                                break;
                            case 2: printf("\n2) 13:00 - 15:47 시간대가 선택되었습니다\n\n");//2이면 출력
                                break;
                            case 3: printf("\n3) 19:00 - 21:38시간대가 선택되었습니다\n\n");//3이면 출력
                                break;
                            default://예외처리
                                while (getchar() != '\n');
                                printf("\n잘못 입력되었습니다.\n\n");
                                continue;
                            }
                            break;

                        }

                        printf("좌석 예매로 넘어갑니다. . .");
                        Sleep(3000);//3초 뒤 실행
                        system("cls");

                        printf("\n<현재 좌석 예매 현황>\n");
                        printf("\n");
                        seatStatus(seat); // 좌석 현황 불러오기
                        while (1) {
                            while (1) {
                                printf("예약 좌석 번호 (0을 입력하면 취소됩니다) : ");
                                number = 11;
                                scanf(" %2d%1c", &number, &line);//숫자와문자 입력받음
                                if (number == 0) {//number가 0이면 취소
                                    printf("취소되었습니다\n\n");
                                    break;
                                }

                                else if (line != 'A' && line != 'B' && line != 'C' && line != 'D' || (number < 1 || number > 10)) { //예외처리
                                    while (getchar() != '\n');
                                    printf("\n잘못된 좌석입니다. 다시 입력하세요.\n\n");
                                    continue;
                                }

                                else if (line == 'A') {//문자가 A일 경우 그대로
                                    tmp = number;
                                    break;
                                }
                                else if (line == 'B') {//문자가 B, C, D일 경우 더함
                                    tmp = number + 10;
                                    break;
                                }
                                else if (line == 'C') {
                                    tmp = number + 20;
                                    break;
                                }
                                else if (line == 'D') {
                                    tmp = number + 30;
                                    break;
                                }
                                
                            }
                            if (number != 0) {
                                    if (seat[tmp - 1] == 1) {//이미 예매되어있는 좌석이면 처음부터
                                        printf("\n이미 예약되어있는 좌석입니다. 다시 예약해주십시오.\n\n");
                                        continue;
                                    }
                                    else {
                                        seat[tmp - 1] = 1;   // screen 화면의 좌석은 1번부터 40번까지 이기 때문에, 사용자가 입력한 숫자에서 '-1'을 해준다
                                        printf("\n%d%c 좌석에 배치되었습니다.\n\n", number, line);
                                        ageTable();
                                        break;
                                    }
                                }
                        }

                        

                        if (number != 0) {
                            while (1) {
                                age = 0;
                                printf("나이를 입력해주세요 : ");
                                scanf("%d", &age);//나이 변수 입력
                                if (age < 13 && age > 0) {//1살에서 12살 사이면 실행
                                    printf("\n결제 금액은 5,000원입니다.\n\n");
                                    break;
                                }
                                else if (age >= 13 && age < 65) {//13살에서 64살이면 실행
                                    printf("\n결제 금액은 10,000원입니다.\n\n");
                                    break;
                                }
                                else if (age >= 65) {//65살 이상이면 실행
                                    printf("\n결제 금액은 5,000입니다.\n\n");
                                    break;
                                }
                                else {//예외처리
                                    while (getchar() != '\n');
                                    printf("\n나이가 잘못 입력되었습니다. 다시 입력해주세요.\n\n");
                                    continue;
                                }
                            }
                        }
                        //결제 진행
                        printf("결제를 진행하겠습니다.\n\n");
                        printf("결제 진행중 . . .\n");
                        printf("\n");
                        printf("\n");
                        printf("\n");
                        pay = 3000; // 3초
                        Sleep(pay); // 결제 로딩 sleep
                        printf("결제가 완료되었습니다.\n\n");
                        printf("처음 화면으로 돌아갑니다.\n\n");
                        printf("\n");
                        pay = 2000;
                        Sleep(pay);
                        break;
                        system("cls");

                    case 2://buy_menu가 2이면 실행
                        printf("\n다인 예매 옵션이 선택되었습니다.\n");
                        timetable1();

                        while (1) {
                            printf("시간대를 선택하세요: ");
                            scanf_s("%d", &st_time);
                            switch (st_time) {
                            case 1: printf("\n1) 05:15 - 07:49 시간대가 선택되었습니다\n\n");
                                break;
                            case 2: printf("\n2) 13:00 - 15:47시간대가 선택되었습니다\n\n");
                                break;
                            case 3: printf("\n3) 19:00 - 21:38시간대가 선택되었습니다\n\n");
                                break;
                            default:
                                while (getchar() != '\n');
                                printf("\n잘못 입력되었습니다.\n\n");
                                continue;
                            }

                            printf("좌석 예매로 넘어갑니다. . .");
                            Sleep(3000);
                            system("cls");
                            printf("\n<현재 좌석 예매 현황>\n");
                            printf("\n");
                            seatStatus(seat);

                            while (1) {
                                printf("예매할 인원 수를 입력해주세요(최대 5명 예약 가능): ");
                                scanf(" %d", &p_number);//예매할 인원 수 입력
                                p = 1;//p를 1로 초기화
                                switch (p_number) {
                                case 1://p_number가 1이면 실행
                                    printf("\n다인이 아닙니다. 다시 입력해주세요.\n\n");
                                    continue;

                                case 2:
                                case 3:
                                case 4:
                                case 5://p_number가 2~5이면 실행
                                    printf("%d명을 예약합니다.\n ", p_number);
                                    while (p <= p_number) {//p가 p_number보다 작을 때 까지 반복
                                        while (1) {
                                            number = 11;
                                            printf("\n예약 좌석 번호: ");
                                            scanf(" %2d%1c", &number, &line);
                                            if (line != 'A' && line != 'B' && line != 'C' && line != 'D' || (number < 1 || number > 10)) { //예외처리
                                                while (getchar() != '\n');
                                                printf("\n잘못된 좌석입니다. 다시 입력하세요.\n\n");
                                                continue;
                                            }

                                            else if (line == 'A') {//문자가 A일 경우 그대로
                                                tmp = number;
                                                break;
                                            }
                                            else if (line == 'B') {//문자가 B, C, D일 경우 더함
                                                tmp = number + 10;
                                                break;
                                            }
                                            else if (line == 'C') {
                                                tmp = number + 20;
                                                break;
                                            }
                                            else if (line == 'D') {
                                                tmp = number + 30;
                                                break;
                                            }
                                        }

                                        if (number != 0) {
                                            if (seat[tmp - 1] == 1) {
                                                printf("이미 예약되어있는 좌석입니다. 다시 예약해주십시오.\n");
                                                continue;
                                            }
                                            else {
                                                seat[tmp - 1] = 1;   // screen 화면의 좌석은 1번부터 40번까지 이기 때문에, 사용자가 입력한 숫자에서 '-1'을 해준다
                                                printf("\n%d%c 좌석에 배치되었습니다.\n", number, line);
                                                p++;
                                            }
                                        }
                                    }
                                    break;

                                default://예외처리
                                    while (getchar() != '\n');
                                    printf("\n인원수가 잘못 입력되었습니다. 다시 입력해주세요.\n\n");
                                    continue;
                                }

                                break;

                            }
                            //결제진행
                            printf("\n");
                            ageTable();
                            printf("\n예매가 완료되었습니다. 결제료는 %d원입니다. 결제를 진행하겠습니다.\n", p_number * 7000);
                            printf("결제 진행중 . . .\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            pay = 3000; // 3초
                            pay = 3000; // 3초
                            Sleep(pay); // 결제 로딩 sleep
                            printf("결제가 완료되었습니다.\n\n");
                            printf("처음 화면으로 돌아갑니다.\n\n");
                            printf("\n");
                            printf("\n");
                            pay = 2000;
                            Sleep(pay);
                            break;
                            system("cls");
                        }
                        break;

                        break;

                    case 3://buy_menu가 3이면 실행
                        printf("\n랜덤 예매 옵션이 선택되었습니다.\n");

                        timetable1();

                        while (1) {
                            printf("시간대를 선택하세요: ");
                            scanf_s("%d", &st_time);
                            switch (st_time) {
                            case 1: printf("\n1) 05:15 - 07:49 시간대가 선택되었습니다\n\n");
                                break;
                            case 2: printf("\n2) 13:00 - 15:47시간대가 선택되었습니다\n\n");
                                break;
                            case 3: printf("\n3) 19:00 - 21:38시간대가 선택되었습니다\n\n");
                                break;
                            default:
                                while (getchar() != '\n');
                                printf("\n잘못 입력되었습니다.\n\n");
                                continue;
                            }
                            break;
                        }

                        printf("좌석 예매로 넘어갑니다. . .");
                        Sleep(3000);
                        system("cls");
                        
                        printf("\n");
                        printf("\n<현재 좌석 예매 현황>\n");
                        printf("\n");
                        seatStatus(seat); // 좌석 현황 불러오기
                        printf("\n");
                        ageTable(); // 나이 테이블 출력
                        printf("\n");
                        while (1) {
                            //나이 결제 먼저
                            age = 0;
                            printf("예매하고자 하시는 승차권의 탑승자 나이를 입력해주세요 : ");
                            scanf("%d", &age);
                            if (age < 13 && age > 0) {
                                printf("결제 금액은 5,000원입니다.");
                                printf("\n");
                            }
                            else if (age >= 13 && age < 65) {
                                printf("결제 금액은 10,000원입니다.\n\n");
                                printf("\n");
                            }
                            else if (age >= 65) {
                                printf("결제 금액은 5,000입니다.\n\n");
                                printf("\n");
                            }
                            else {
                                while (getchar() != '\n');
                                printf("\n나이가 잘못 입력되었습니다. 다시 입력해주세요.\n\n");
                                continue;
                            }



                            while (1) {
                                number = rand() % 40;//1부터 39까지 난수 생성
                                if (seat[number] == 1) {//중복값이 있으면
                                    continue;//다시 생성
                                }
                                else
                                    break;
                            }

                            // 랜덤 좌석 line 나누기
                            switch ((number + 1) / 10)
                            {
                            case 4:
                                line = 'D';
                                tmp = number + 1 - 30;
                                break;

                            case 3:
                                line = 'D';
                                tmp = number + 1 - 30;
                                break;

                            case 2:
                                line = 'C';
                                tmp = number + 1 - 20;
                                break;

                            case 1:
                                line = 'B';
                                tmp = number + 1 - 10;
                                break;

                            default:
                                line = 'A';
                                tmp = number + 1 - 0;
                                break;
                            }
                            //결제진행
                            printf("\n");
                            printf("\n");
                            printf("결제 진행중 . . .\n");
                            printf("\n");
                            printf("\n");
                            pay = 3000; // 3초
                            pay = 3000; // 3초
                            Sleep(pay); // 결제 로딩 sleep
                            printf("결제가 완료되었습니다.\n");
                            printf("고객님의 좌석을 배정중입니다 . . .\n");
                            pay = 2000; // 2초
                            Sleep(pay);
                            printf("\n\n무작위 좌석이 배정 완료되었습니다.\n");
                            seat[number] = 1;
                            if (tmp == 0)
                                printf("고객님의 좌석은 %d%c좌석 입니다.\n", tmp + 10, line);
                            else
                                printf("고객님의 좌석은 %d%c좌석 입니다.\n", tmp, line); //랜덤수를 출력하여 몇번 좌석이 예매되었는지 안내
                            printf("\n");
                            printf("\n===================================================================\n\n");
                            break;
                        }
                        system("pause");
                        system("cls");
                        break;

                    case 4://buy_menu가 4이면 실행
                        printf("\n뒤로 돌아갑니다.\n\n");
                        Sleep(1000);
                        break;

                    default://예외처리
                        while (getchar() != '\n');
                        printf("잘못 입력되었습니다.\n");
                        continue;

                    }
                    break;
                }

                system("cls");
            }

            else if (strcmp(menu, "2") == 0) {//메뉴가 2일 경우 실행
                seatStatus(seat);
                printf("\n");
                system("PAUSE");
                system("cls");
            }

            else if (strcmp(menu, "3") == 0) {//메뉴가 3일 경우 실행
                int tmp1, chk = 0;//숫자와 체크변수 생성하고 0으로 초기화
                char tmp2;//문자 변수 생성

                for (int i = 0; i < SIZE; i++) {//i 40번 반복
                    if (seat[i] == 1) {//좌석이 있는지 확인
                        chk = 1;//체크 변수를 1로 설정
                        if (i >= 0 && i < 10) {//i를 판단하여 문자와 숫자 출력
                            tmp1 = i + 1;
                            tmp2 = 'A';
                        }
                        else if (i >= 10 && i < 20) {
                            tmp1 = i - 10 + 1;
                            tmp2 = 'B';
                        }
                        if (i >= 20 && i < 30) {
                            tmp1 = i - 20 + 1;
                            tmp2 = 'C';
                        }
                        if (i >= 30 && i < 40) {
                            tmp1 = i - 30 + 1;
                            tmp2 = 'D';
                        }
                        printf("\n%4d년 %2d월 %2d일\n1호차 %d%c\n\n", ny, nm, nd, tmp1, tmp2);//연도, 월, 일 호차, 좌석 출력
                    }
                }

                if (chk == 0) {//체크된 변수가 없을 경우 출력
                    printf("\n예매된 승차권이 없습니다.\n\n");
                }

                system("PAUSE");
                system("cls");
            }


            else if (strcmp(menu, "4") == 0) {//메뉴가 4일 경우 실행
                seatStatus(seat);
                while (1) {
                    printf("취소 좌석 번호 : ");
                    scanf("%d%c", &number, &line);
                    if (line != 'A' && line != 'B' && line != 'C' && line != 'D' || (number < 1 || number > 10)) { //예외처리
                        while (getchar() != '\n');
                        printf("\n잘못된 좌석입니다. 다시 입력하세요.\n\n");
                        continue;
                    }
                    else if (line == 'A') {//문자가 A일 경우 그대로
                        tmp = number;
                        break;
                    }
                    else if (line == 'B') {//문자가 B, C, D일 경우 더함
                        tmp = number + 10;
                        break;
                    }
                    else if (line == 'C') {
                        tmp = number + 20;
                        break;
                    }
                    else if (line == 'D') {
                        tmp = number + 30;
                        break;
                    }
                }

                if (seat[tmp - 1] == 0)//이미 좌석변수가 0일 경우 실행
                    printf("\n이미 비어있는 좌석입니다.\n\n");
                else {//좌석 변수가 1이면 실행
                    printf("\n%d%c 좌석의 예매가 취소되었습니다.\n\n", number, line);
                    seat[tmp - 1] = 0;
                }
                system("PAUSE");
                system("cls");
            }




            else if (strcmp(menu, "5") == 0) {//메뉴가 5이면 실행, 프로그램 종료
                break;
            }

            else {//예외처리
                while (getchar() != '\n');
                printf("\n잘못된 입력입니다\n");
            }

        }

        printf("\n프로그램을 종료합니다.\n");
        menu[9] = "";//메뉴 변수 초기화
        return 0;
    }


void seatStatus(int seat[]) {   // 1A번 부터 10D까지 좌석의 현황을 나타내는 함수이다.
    printf("\n  서울 -> 부산 1호차\n");
    printf("\n =======================================================================\n");
    printf(" ==    1A]   2A]   3A]   4A]   5A]   6A]   7A]   8A]   9A]   10A]   == ==\n");
    printf(" ==-----------------------------------------------------------------==  ==\n");
    printf(" ==");
    for (int i = 0; i < 10; i++) {
        printf("%5d ", seat[i]);
    }
    printf("     ==   ==");
    printf("\n =====================================================================    ==");
    printf("\n ==    1B]   2B]   3B]   4B]   5B]   6B]   7B]   8B]   9B]   10B]   ==     ==\n");
    printf(" ==-----------------------------------------------------------------==      ==\n");
    printf(" ==");
    for (int i = 10; i < 20; i++) {
        printf("%5d ", seat[i]);
    }
    printf("     ==       ==");
    printf("\n =====================================================================        ==");
    printf("\n ==    1C]   2C]   3C]   4C]   5C]   6C]   7C]   8C]   9C]   10C]   ==         ==\n");
    printf(" ==-----------------------------------------------------------------==          ==\n");
    printf(" ==");
    for (int i = 20; i < 30; i++) {
        printf("%5d ", seat[i]);
    }
    printf("     ==           ==");
    printf("\n =====================================================================            ==");
    printf("\n ==    1D]   2D]   3D]   4D]   5D]   6D]   7D]   8D]   9D]   10D]   ==             ==\n");
    printf(" ==-----------------------------------------------------------------==              ==\n");
    printf(" ==");
    for (int i = 30; i < 40; i++) {
        printf("%5d ", seat[i]);
    }
    printf("     ==             ==");
    printf("\n ===================================================================================\n\n\n");
}

void  ageTable() {//나이,가격표 출력
    printf(" =========================================\n");
    printf("        어린이(~12세) : 5,000원\n");
    printf(" -----------------------------------------\n");
    printf("      성인(13세~64세) : 10,000원\n");
    printf(" -----------------------------------------\n");
    printf("        노약자(65세~) : 5,000원\n");  
    printf(" -----------------------------------------\n");
    printf("        다인 예매시  :  7,000원\n");
    printf(" =========================================\n\n");
}

void timetable1() {//시간표 출력
    printf("\n ======[시간대]======\n");
    printf("┏━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃  1)05:15 - 07:49  ┃\n");
    printf("┃  2)13:00 - 15:47  ┃\n");
    printf("┃  3)19:00 - 21:38  ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━┛\n\n\n");
}

void set() {//콘솔창 이름과 크기 설정
    system("title 기차예매시스템");
    system("mode con:cols=191 lines=50");
}

void rail() {//기차 선로

    printf("===============================================================================================================================================================================================\n");
    printf("            ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==                    == \n");
    printf("        ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==     \n");
    printf("    ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==         \n");
    printf("===============================================================================================================================================================================================\n");
    printf("\n");
    printf("\n");

    return 0;
}



void train() {//기차
    int SleepCount = 250;
    printf("\n"); printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n==");
    printf("\n===");
    printf("\n");
    printf("\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("==\n");
    printf(" ==\n");
    printf("  ==\n");
    printf("=====\n");
    printf("    ==\n");
    printf("     ==\n");
    printf("=======\n");
    printf("\n");
    printf("\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("=============\n");
    printf("    =       ==\n");
    printf("     =       ==\n");
    printf("      ==========\n");
    printf("               ==\n");
    printf("                ==\n");
    printf("==================\n");
    printf("    =\n");
    printf("\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("     ======================\n");
    printf("====              =       ==\n");
    printf(" =                 =       ==\n");
    printf(" =                  ==========\n");
    printf(" =                           ==\n");
    printf(" =                            ==\n");
    printf("================================\n");
    printf("              =   =\n");
    printf("               ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("==========     ======================\n");
    printf("          ====              =       ==\n");
    printf("           =                 =       ==\n");
    printf("           =                  ==========\n");
    printf("           =                           ==\n");
    printf("           =                            ==\n");
    printf("==========================================\n");
    printf("                        =   =\n");
    printf("                         ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("   ======================     ======================\n");
    printf("===                      ====              =       ==\n");
    printf("=                         =                 =       ==\n");
    printf("=                         =                  ==========\n");
    printf("=                         =                           ==\n");
    printf("=                         =                            ==\n");
    printf("=========================================================\n");
    printf("         =   =                         =   =\n");
    printf("          ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("==========     ======================     ======================\n");
    printf("           ====                      ====              =       ==\n");
    printf("            =                         =                 =       ==\n");
    printf("            =                         =                  ==========\n");
    printf("            =                         =                           ==\n");
    printf("            =                         =                            ==\n");
    printf("=====================================================================\n");
    printf("                      =   =                         =   =\n");
    printf("                       ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");


    printf("\n"); printf("\n");
    printf("   ======================     ======================     ======================\n");
    printf("===                       ====                      ====              =       ==\n");
    printf("=                          =                         =                 =       ==\n");
    printf("=                          =                         =                  ==========\n");
    printf("=                          =                         =                           ==\n");
    printf("=                          =                         =                            ==\n");
    printf("====================================================================================\n");
    printf("          =   =                      =   =                         =   =\n");
    printf("           ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("=========    ======================     ======================     ======================\n");
    printf("         ====                       ====                      ====              =       ==\n");
    printf("          =                          =                         =                 =       ==\n");
    printf("          =                          =                         =                  ==========\n");
    printf("          =                          =                         =                           ==\n");
    printf("          =                          =                         =                            ==\n");
    printf("==============================================================================================\n");
    printf("                   =   =                      =   =                         =   =\n");
    printf("                    ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf(" =====================    =======================    ======================     ======================\n");
    printf("=                     ====                       ====                      ====              =       ==\n");
    printf("=                      =                          =                         =                 =       ==\n");
    printf("=                      =                          =                         =                  ==========\n");
    printf("=                      =                          =                         =                           ==\n");
    printf("=                      =                          =                         =                            ==\n");
    printf("===========================================================================================================\n");
    printf("        =   =                   =   =                      =   =                         =   =\n");
    printf("         ===                     ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");


    printf("\n"); printf("\n");
    printf("========    =====================    ======================     ======================     ======================\n");
    printf("          ====                   ====                       ====                      ====              =       ==\n");
    printf("           =                      =                          =                         =                 =       ==\n");
    printf("           =                      =                          =                         =                  ==========\n");
    printf("           =                      =                          =                         =                           ==\n");
    printf("           =                      =                          =                         =                            ==\n");
    printf("======================================================================================================================\n");
    printf("                   =   =                   =   =                      =   =                         =   =\n");
    printf("                    ===                     ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf(" ====================    ===================    ======================     ======================     ======================\n");
    printf("=                    ====                   ====                       ====                      ====              =       ==\n");
    printf("=                     =                      =                          =                         =                 =       ==\n");
    printf("=                     =                      =                          =                         =                  ==========\n");
    printf("=                     =                      =                          =                         =                           ==\n");
    printf("=                     =                      =                          =                         =                            ==\n");
    printf("=================================================================================================================================\n");
    printf("        =   =                 =   =                   =   =                      =   =                         =   =\n");
    printf("         ===                   ===                     ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("==========    ====================    =====================    ======================     ======================     ======================\n");
    printf("          ====                    ====                     ====                       ====                      ====              =       ==\n");
    printf("           =                       =                        =                          =                         =                 =       ==\n");
    printf("           =                       =                        =                          =                         =                  ==========\n");
    printf("           =                       =                        =                          =                         =                           ==\n");
    printf("           =                       =                        =                          =                         =                            ==\n");
    printf("================================================================================================================================================\n");
    printf("                       =   =                 =   =                   =   =                      =   =                         =   =\n");
    printf("                        ===                   ===                     ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("====================    ====================    =====================    ======================     ======================     ======================\n");
    printf("                    ====                    ====                     ====                       ====                      ====              =       ==\n");
    printf("                     =                       =                        =                          =                         =                 =       ==\n");
    printf("                     =                       =                        =                          =                         =                  ==========\n");
    printf("                     =                       =                        =                          =                         =                           ==\n");
    printf("                     =                       =                        =                          =                         =                            ==\n");
    printf("==========================================================================================================================================================\n");
    printf("       =   =                      =   =                 =   =                   =   =                      =   =                         =   =\n");
    printf("        ===                        ===                   ===                     ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("=========    ===================    ====================    =====================    ======================     ======================     ======================\n");
    printf("         ====                   ====                    ====                     ====                       ====                      ====              =       ==\n");
    printf("          =                      =                       =                        =                          =                         =                 =       ==\n");
    printf("          =                      =                       =                        =                          =                         =                  ==========\n");
    printf("          =                      =                       =                        =                          =                         =                           ==\n");
    printf("          =                      =                       =                        =                          =                         =                            ==\n");
    printf("======================================================================================================================================================================\n");
    printf("                  =   =                      =   =                 =   =                   =   =                      =   =                         =   =\n");
    printf("                   ===                        ===                   ===                     ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("==================    ===================    ====================    =====================    ======================     ======================     ======================\n");
    printf("                  ====                   ====                    ====                     ====                       ====                      ====              =       ==\n");
    printf("                   =                      =                       =                        =                          =                         =                 =       ==\n");
    printf("                   =                      =                       =                        =                          =                         =                  ==========\n");
    printf("                   =                      =                       =                        =                          =                         =                           ==\n");
    printf("                   =                      =                       =                        =                          =                         =                            ==\n");
    printf("===============================================================================================================================================================================\n");
    printf("    =   =                   =   =                      =   =                 =   =                   =   =                      =   =                         =   =\n");
    printf("     ===                     ===                        ===                   ===                     ===                        ===                           ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");


    printf("\n"); printf("\n");
    printf("==============    ==================    =================    ====================    =====================    ======================     ======================     ======================\n");
    printf("==            ====                  ====                 ====                    ====                     ====                       ====                      ====              =       ==\n");
    printf("==             =                     =                    =                       =                        =                          =                         =                 =       ==\n");
    printf("==             =                     =                    =                       =                        =                          =                         =                  ==========\n");
    printf("==             =                     =                    =                       =                        =                          =                         =                           ==\n");
    printf("==             =                     =                    =                       =                        =                          =                         =                            ==\n");
    printf("===============================================================================================================================================================================================\n");
    printf("     =   =                =   =                  =   =                    =   =                 =   =                   =   =                      =   =                       =   =\n");
    printf("      ===                  ===                    ===                      ===                   ===                     ===                        ===                         ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("   ====================    ==================    =================    ====================    ====================     ======================     =====================     ===================\n");
    printf("===                    ====                  ====                 ====                    ====                     ====                       ====                      ====                  =\n");
    printf("=                       =                     =                    =                       =                        =                          =                         =                    =\n");
    printf("=                       =                     =                    =                       =                        =                          =                         =                    =\n");
    printf("=                       =                     =                    =                       =                        =                          =                         =                    =\n");
    printf("=                       =                     =                    =                       =                        =                          =                         =                    =\n");
    printf("===============================================================================================================================================================================================\n");
    printf("        =   =                =   =                  =   =                    =   =                 =   =                   =   =                      =   =                       =   =\n");
    printf("         ===                  ===                    ===                      ===                   ===                     ===                        ===                         ===\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("========    ====================    ==================    =================    ====================    ====================     ======================     =====================     ==========\n");
    printf("        ====                    ====                  ====                 ====                    ====                     ====                       ====                      ====          \n");
    printf("         =                       =                     =                    =                       =                        =                          =                         =           =\n");
    printf("         =                       =                     =                    =                       =                        =                          =                         =           =\n");
    printf("         =                       =                     =                    =                       =                        =                          =                         =           =\n");
    printf("         =                       =                     =                    =                       =                        =                          =                         =           =\n");
    printf("===============================================================================================================================================================================================\n");
    printf("                   =   =                =   =                  =   =                    =   =                 =   =                   =   =                      =   =                       = \n");
    printf("                    ===                  ===                    ===                      ===                   ===                     ===                        ===                         =\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("   =====================    ==================    =================    ====================    ====================     ======================     =====================     ==================\n");
    printf("===     ==              ====                  ====                 ====                    ====                     ====                       ====                      ====                  \n");
    printf("==    ==                 =                     =                    =                       =                        =                          =                         =                   =\n");
    printf("======                   =                     =                    =                       =                        =                          =                         =                   =\n");
    printf("==                       =                     =                    =                       =                        =                          =                         =                   =\n");
    printf("==                       =                     =                    =                       =                        =                          =                         =                   =\n");
    printf(" ==============================================================================================================================================================================================\n");
    printf("                   =   =                =   =                  =   =                    =   =                 =   =                   =   =                      =   =                       = \n");
    printf("                    ===                  ===                    ===                      ===                   ===                     ===                        ===                         =\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                  =====================    ==================    =================    ====================    ====================     ======================     ===================    ======\n");
    printf("               ===     ==              ====                  ====                 ====                    ====                     ====                       ====                   ====      \n");
    printf("               ==    ==                 =                     =                    =                       =                        =                          =                      =        \n");
    printf("               ======                   =                     =                    =                       =                        =                          =                      =        \n");
    printf("               ==                       =                     =                    =                       =                        =                          =                      =        \n");
    printf("               ==                       =                     =                    =                       =                        =                          =                      =        \n");
    printf("                ===============================================================================================================================================================================\n");
    printf("                                  =   =                =   =                  =   =                    =   =                 =   =                   =   =                      =   =          \n");
    printf("                                   ===                  ===                    ===                      ===                   ===                     ===                        ===           \n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                                     =====================    ==================    =================    ====================    ====================     ======================     ==========\n");
    printf("                                  ===     ==              ====                  ====                 ====                    ====                     ====                       ====          \n");
    printf("    ###  #                        ==    ==                 =                     =                    =                       =                        =                          =            \n");
    printf("     #   #                        ======                   =                     =                    =                       =                        =                          =            \n");
    printf("     #   #                        ==                       =                     =                    =                       =                        =                          =            \n");
    printf("#    #   #                        ==                       =                     =                    =                       =                        =                          =            \n");
    printf(" #  ###  ######                   =============================================================================================================================================================\n");
    printf("                                                     =   =                =   =                  =   =                    =   =                 =   =                   =   =                  \n");
    printf("                                                      ===                  ===                    ===                      ===                   ===                     ===                   \n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                                                         =====================    ==================    =================    ====================    ====================     =================\n");
    printf("                                                      ===     ==              ====                  ====                 ====                    ====                     ====                 \n");
    printf("#    ####        #      ###  #                        ==    ==                 =                     =                    =                       =                        =                   \n");
    printf(" #   #   #      # #      #   #                        ======                   =                     =                    =                       =                        =                   \n");
    printf("  #  # ##      #####     #   #                        ==                       =                     =                    =                       =                        =                   \n");
    printf(" #   #   #    #     #    #   #                        ==                       =                     =                    =                       =                        =                   \n");
    printf("#    #    #  #       #  ###  ######                   =========================================================================================================================================\n");
    printf("                                                                         =   =                =   =                  =   =                    =   =                 =   =                   =  \n");
    printf("                                                                          ===                  ===                    ===                      ===                   ===                     ==\n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                                                                                   =====================    ==================    =================    ====================    ================\n");
    printf("                                                                                ===     ==              ====                  ====                 ====                    ====                \n");
    printf("                ###      ##    ####        #      ###  #                        ==    ==                 =                     =                    =                       =                  \n");
    printf("                # ##    #  #   #   #      # #      #   #                        ======                   =                     =                    =                       =                  \n");
    printf("                #   #  #    #  # ##      #####     #   #                        ==                       =                     =                    =                       =                  \n");
    printf("                # ##    #  #   #   #    #     #    #   #                        ==                       =                     =                    =                       =                  \n");
    printf("                ###      ##    #    #  #       #  ###  ######                   ===============================================================================================================\n");
    printf("                                                                                                   =   =                =   =                  =   =                    =   =                 =\n");
    printf("                                                                                                    ===                  ===                    ===                      ===                   \n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                                                                                                             =====================    ==================    =================    ==============\n");
    printf("                                                                                                            ===     ==              ====                  ====                 ====            \n");
    printf("                                           ###      ##    ####        #      ###  #                        ==    ==                 =                     =                    =               \n");
    printf("                                           # ##    #  #   #   #      # #      #   #                        ======                   =                     =                    =               \n");
    printf("                                           #   #  #    #  # ##      #####     #   #                        ==                       =                     =                    =               \n");
    printf("                                           # ##    #  #   #   #    #     #    #   #                        ==                       =                     =                    =               \n");
    printf("                                           ###      ##    #    #  #       #  ###  ######                   ====================================================================================\n");
    printf("                                                                                                                             =   =                =   =                  =   =                 \n");
    printf("                                                                                                                              ===                  ===                    ===                  \n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                                                                                                                                     =====================    ==================    ===========\n");
    printf("                                                                                                                                   ===     ==              ====                  ====          \n");
    printf("                                                               ###      ##    ####        #      ###  #                            ==    ==                 =                     =            \n");
    printf("                                                               # ##    #  #   #   #      # #      #   #                            ======                   =                     =            \n");
    printf("                                                               #   #  #    #  # ##      #####     #   #                            ==                       =                     =            \n");
    printf("                                                               # ##    #  #   #   #    #     #    #   #                            ==                       =                     =            \n");
    printf("                                                               ###      ##    #    #  #       #  ###  ######                       ============================================================\n");
    printf("                                                                                                                                                     =   =                =   =                \n");
    printf("                                                                                                                                                      ===                  ===                 \n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                                                                                                                                                            =====================    ==========\n");
    printf("                                                                                                                                                          ===     ==              ====         \n");
    printf("                                                                              ###      ##    ####        #      ###  #                                    ==    ==                 =           \n");
    printf("                                                                              # ##    #  #   #   #      # #      #   #                                    ======                   =           \n");
    printf("                                                                              #   #  #    #  # ##      #####     #   #                                    ==                       =           \n");
    printf("                                                                              # ##    #  #   #   #    #     #    #   #                                    ==                       =           \n");
    printf("                                                                              ###      ##    #    #  #       #  ###  ######                               =====================================\n");
    printf("                                                                                                                                                                            =   =              \n");
    printf("                                                                                                                                                                             ===               \n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                                                                                                                                                                                ===============\n");
    printf("                                                                                                                                                                              ===     ==       \n");
    printf("                                                                              ###      ##    ####        #      ###  #                                                        ==    ==         \n");
    printf("                                                                              # ##    #  #   #   #      # #      #   #                                                        ======           \n");
    printf("                                                                              #   #  #    #  # ##      #####     #   #                                                        ==               \n");
    printf("                                                                              # ##    #  #   #   #    #     #    #   #                                                        ==               \n");
    printf("                                                                              ###      ##    #    #  #       #  ###  ######                                                   =================\n");
    printf("                                                                                                                                                                                               \n");
    printf("                                                                                                                                                                                               \n");
    rail();
    Sleep(SleepCount);
    system("cls");

    printf("\n"); printf("\n");
    printf("                                                                                                                                                                                               \n");
    printf("                                                                                                                                                                                               \n");
    printf("                                                                              ###      ##    ####        #      ###  #                                                                         \n");
    printf("                                                                              # ##    #  #   #   #      # #      #   #                                                                         \n");
    printf("                                                                              #   #  #    #  # ##      #####     #   #                                                                         \n");
    printf("                                                                              # ##    #  #   #   #    #     #    #   #                                                                         \n");
    printf("                                                                              ###      ##    #    #  #       #  ###  ######                                                                    \n");
    printf("                                                                                                                                                                                               \n");
    printf("                                                                                                                                                                                               \n");
    rail();
    Sleep(SleepCount);

    return 0;
}
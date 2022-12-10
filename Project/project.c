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
    srand((unsigned int)time(NULL));//���� ����(���� ���� ��ɿ� ���
    int pay;//���� ������ ����
    int seat[SIZE] = { 0 };   // 40�� �¼��� ���� ������ �����ϰ� 0���� �ʱ�ȭ ���ش�.
    char menu[10] = { 0 };//�޴� ���� ���ڿ� ����
    int buy_menu;//���� �ɼ� ���� ����
    int ny, nm, nd;//����, ��, �� ���� ����
    int tmp, number, age;//�¼�, ���� ���� ����
    int st_time;//�ð��� ���� ���� ����
    char line;//�¼� ���� ���� ����
    struct tm* t;
    time_t base = time(NULL);
    t = localtime(&base);//���� ��¥�� ������� ���� ����
    int seatfull = 1;//�¼��� �� ���ִ��� ������ ���� �����ϰ� 1�� ����
    int p_number, p;//���� ���ſ� ����� ����
    int key;//Ű���� �Է½� �������� �Ѿ���� ����

    ny = t->tm_year + 1900;//����
    nm = t->tm_mon + 1;//��
    nd = t->tm_mday;//��

    set();//�ܼ�â �̸��� ũ�� ����
    train();//���� ���

    printf("                                                                               DoRail (�����Ϸ��� 'space bar'�� ��������)\n");
    while (1) {//�����̽��� ������ �Ѿ

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
            printf("\nDorail ���� �ý��ۿ� ���� ���� ȯ���մϴ�.\n");
            printf("\n[1] ������ ����\t[2] �¼� ��ȸ\t[3] ������ Ȯ��\t[4] ���/���� [5] Dorail ����\n");
            printf("�޴� ���� : ");
            scanf(" %s", &menu);//�޴� �Է�

            if (menu[3] != '\0')  // �� üũ
                for (int i = 0; i < strlen(menu); i++)
                {
                }

            if (strcmp(menu, "1") == 0) {//�޴��� 1�� ��� ����
                for (int a = 0; a < 40; a++) {
                    if (seat[a] == 0) {//seat�� ���ڸ��� ������� seatfull�� 0����
                        seatfull = 0;
                    }
                }

                if (seatfull == 1) {//seatfull�� 0�� ���� �ʾ����� ����
                    printf("������ �¼��� �����ϴ�.\n");
                    continue;
                }

                while (1) {
                    printf("\n���� �ɼ��� �������ּ���\n");
                    printf("\n[1] 1�� ����\t[2] ���� ����\t[3] ���� ����\t[4] ���ư���\n");
                    printf("�޴� ���� : ");
                    scanf("%d", &buy_menu);//���� �޴� �Է�
                    switch (buy_menu) {
                    case 1: //buy_menu�� 1�̸� ����
                        printf("\n1�� ���� �ɼ��� ���õǾ����ϴ�.\n");
                        printf("\n");
                        timetable1();//�ð��� ���̺� ���

                        while (1) {
                            printf("�ð��븦 �����ϼ���: ");
                            scanf_s("%d", &st_time);//�ð��� �޴� �Է�
                            switch (st_time) {
                            case 1: printf("\n1) 05:15 - 07:49 �ð��밡 ���õǾ����ϴ�\n\n");//1�̸� ���
                                break;
                            case 2: printf("\n2) 13:00 - 15:47 �ð��밡 ���õǾ����ϴ�\n\n");//2�̸� ���
                                break;
                            case 3: printf("\n3) 19:00 - 21:38�ð��밡 ���õǾ����ϴ�\n\n");//3�̸� ���
                                break;
                            default://����ó��
                                while (getchar() != '\n');
                                printf("\n�߸� �ԷµǾ����ϴ�.\n\n");
                                continue;
                            }
                            break;

                        }

                        printf("�¼� ���ŷ� �Ѿ�ϴ�. . .");
                        Sleep(3000);//3�� �� ����
                        system("cls");

                        printf("\n<���� �¼� ���� ��Ȳ>\n");
                        printf("\n");
                        seatStatus(seat); // �¼� ��Ȳ �ҷ�����
                        while (1) {
                            while (1) {
                                printf("���� �¼� ��ȣ (0�� �Է��ϸ� ��ҵ˴ϴ�) : ");
                                number = 11;
                                scanf(" %2d%1c", &number, &line);//���ڿ͹��� �Է¹���
                                if (number == 0) {//number�� 0�̸� ���
                                    printf("��ҵǾ����ϴ�\n\n");
                                    break;
                                }

                                else if (line != 'A' && line != 'B' && line != 'C' && line != 'D' || (number < 1 || number > 10)) { //����ó��
                                    while (getchar() != '\n');
                                    printf("\n�߸��� �¼��Դϴ�. �ٽ� �Է��ϼ���.\n\n");
                                    continue;
                                }

                                else if (line == 'A') {//���ڰ� A�� ��� �״��
                                    tmp = number;
                                    break;
                                }
                                else if (line == 'B') {//���ڰ� B, C, D�� ��� ����
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
                                    if (seat[tmp - 1] == 1) {//�̹� ���ŵǾ��ִ� �¼��̸� ó������
                                        printf("\n�̹� ����Ǿ��ִ� �¼��Դϴ�. �ٽ� �������ֽʽÿ�.\n\n");
                                        continue;
                                    }
                                    else {
                                        seat[tmp - 1] = 1;   // screen ȭ���� �¼��� 1������ 40������ �̱� ������, ����ڰ� �Է��� ���ڿ��� '-1'�� ���ش�
                                        printf("\n%d%c �¼��� ��ġ�Ǿ����ϴ�.\n\n", number, line);
                                        ageTable();
                                        break;
                                    }
                                }
                        }

                        

                        if (number != 0) {
                            while (1) {
                                age = 0;
                                printf("���̸� �Է����ּ��� : ");
                                scanf("%d", &age);//���� ���� �Է�
                                if (age < 13 && age > 0) {//1�쿡�� 12�� ���̸� ����
                                    printf("\n���� �ݾ��� 5,000���Դϴ�.\n\n");
                                    break;
                                }
                                else if (age >= 13 && age < 65) {//13�쿡�� 64���̸� ����
                                    printf("\n���� �ݾ��� 10,000���Դϴ�.\n\n");
                                    break;
                                }
                                else if (age >= 65) {//65�� �̻��̸� ����
                                    printf("\n���� �ݾ��� 5,000�Դϴ�.\n\n");
                                    break;
                                }
                                else {//����ó��
                                    while (getchar() != '\n');
                                    printf("\n���̰� �߸� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n\n");
                                    continue;
                                }
                            }
                        }
                        //���� ����
                        printf("������ �����ϰڽ��ϴ�.\n\n");
                        printf("���� ������ . . .\n");
                        printf("\n");
                        printf("\n");
                        printf("\n");
                        pay = 3000; // 3��
                        Sleep(pay); // ���� �ε� sleep
                        printf("������ �Ϸ�Ǿ����ϴ�.\n\n");
                        printf("ó�� ȭ������ ���ư��ϴ�.\n\n");
                        printf("\n");
                        pay = 2000;
                        Sleep(pay);
                        break;
                        system("cls");

                    case 2://buy_menu�� 2�̸� ����
                        printf("\n���� ���� �ɼ��� ���õǾ����ϴ�.\n");
                        timetable1();

                        while (1) {
                            printf("�ð��븦 �����ϼ���: ");
                            scanf_s("%d", &st_time);
                            switch (st_time) {
                            case 1: printf("\n1) 05:15 - 07:49 �ð��밡 ���õǾ����ϴ�\n\n");
                                break;
                            case 2: printf("\n2) 13:00 - 15:47�ð��밡 ���õǾ����ϴ�\n\n");
                                break;
                            case 3: printf("\n3) 19:00 - 21:38�ð��밡 ���õǾ����ϴ�\n\n");
                                break;
                            default:
                                while (getchar() != '\n');
                                printf("\n�߸� �ԷµǾ����ϴ�.\n\n");
                                continue;
                            }

                            printf("�¼� ���ŷ� �Ѿ�ϴ�. . .");
                            Sleep(3000);
                            system("cls");
                            printf("\n<���� �¼� ���� ��Ȳ>\n");
                            printf("\n");
                            seatStatus(seat);

                            while (1) {
                                printf("������ �ο� ���� �Է����ּ���(�ִ� 5�� ���� ����): ");
                                scanf(" %d", &p_number);//������ �ο� �� �Է�
                                p = 1;//p�� 1�� �ʱ�ȭ
                                switch (p_number) {
                                case 1://p_number�� 1�̸� ����
                                    printf("\n������ �ƴմϴ�. �ٽ� �Է����ּ���.\n\n");
                                    continue;

                                case 2:
                                case 3:
                                case 4:
                                case 5://p_number�� 2~5�̸� ����
                                    printf("%d���� �����մϴ�.\n ", p_number);
                                    while (p <= p_number) {//p�� p_number���� ���� �� ���� �ݺ�
                                        while (1) {
                                            number = 11;
                                            printf("\n���� �¼� ��ȣ: ");
                                            scanf(" %2d%1c", &number, &line);
                                            if (line != 'A' && line != 'B' && line != 'C' && line != 'D' || (number < 1 || number > 10)) { //����ó��
                                                while (getchar() != '\n');
                                                printf("\n�߸��� �¼��Դϴ�. �ٽ� �Է��ϼ���.\n\n");
                                                continue;
                                            }

                                            else if (line == 'A') {//���ڰ� A�� ��� �״��
                                                tmp = number;
                                                break;
                                            }
                                            else if (line == 'B') {//���ڰ� B, C, D�� ��� ����
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
                                                printf("�̹� ����Ǿ��ִ� �¼��Դϴ�. �ٽ� �������ֽʽÿ�.\n");
                                                continue;
                                            }
                                            else {
                                                seat[tmp - 1] = 1;   // screen ȭ���� �¼��� 1������ 40������ �̱� ������, ����ڰ� �Է��� ���ڿ��� '-1'�� ���ش�
                                                printf("\n%d%c �¼��� ��ġ�Ǿ����ϴ�.\n", number, line);
                                                p++;
                                            }
                                        }
                                    }
                                    break;

                                default://����ó��
                                    while (getchar() != '\n');
                                    printf("\n�ο����� �߸� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n\n");
                                    continue;
                                }

                                break;

                            }
                            //��������
                            printf("\n");
                            ageTable();
                            printf("\n���Ű� �Ϸ�Ǿ����ϴ�. ������� %d���Դϴ�. ������ �����ϰڽ��ϴ�.\n", p_number * 7000);
                            printf("���� ������ . . .\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            pay = 3000; // 3��
                            pay = 3000; // 3��
                            Sleep(pay); // ���� �ε� sleep
                            printf("������ �Ϸ�Ǿ����ϴ�.\n\n");
                            printf("ó�� ȭ������ ���ư��ϴ�.\n\n");
                            printf("\n");
                            printf("\n");
                            pay = 2000;
                            Sleep(pay);
                            break;
                            system("cls");
                        }
                        break;

                        break;

                    case 3://buy_menu�� 3�̸� ����
                        printf("\n���� ���� �ɼ��� ���õǾ����ϴ�.\n");

                        timetable1();

                        while (1) {
                            printf("�ð��븦 �����ϼ���: ");
                            scanf_s("%d", &st_time);
                            switch (st_time) {
                            case 1: printf("\n1) 05:15 - 07:49 �ð��밡 ���õǾ����ϴ�\n\n");
                                break;
                            case 2: printf("\n2) 13:00 - 15:47�ð��밡 ���õǾ����ϴ�\n\n");
                                break;
                            case 3: printf("\n3) 19:00 - 21:38�ð��밡 ���õǾ����ϴ�\n\n");
                                break;
                            default:
                                while (getchar() != '\n');
                                printf("\n�߸� �ԷµǾ����ϴ�.\n\n");
                                continue;
                            }
                            break;
                        }

                        printf("�¼� ���ŷ� �Ѿ�ϴ�. . .");
                        Sleep(3000);
                        system("cls");
                        
                        printf("\n");
                        printf("\n<���� �¼� ���� ��Ȳ>\n");
                        printf("\n");
                        seatStatus(seat); // �¼� ��Ȳ �ҷ�����
                        printf("\n");
                        ageTable(); // ���� ���̺� ���
                        printf("\n");
                        while (1) {
                            //���� ���� ����
                            age = 0;
                            printf("�����ϰ��� �Ͻô� �������� ž���� ���̸� �Է����ּ��� : ");
                            scanf("%d", &age);
                            if (age < 13 && age > 0) {
                                printf("���� �ݾ��� 5,000���Դϴ�.");
                                printf("\n");
                            }
                            else if (age >= 13 && age < 65) {
                                printf("���� �ݾ��� 10,000���Դϴ�.\n\n");
                                printf("\n");
                            }
                            else if (age >= 65) {
                                printf("���� �ݾ��� 5,000�Դϴ�.\n\n");
                                printf("\n");
                            }
                            else {
                                while (getchar() != '\n');
                                printf("\n���̰� �߸� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n\n");
                                continue;
                            }



                            while (1) {
                                number = rand() % 40;//1���� 39���� ���� ����
                                if (seat[number] == 1) {//�ߺ����� ������
                                    continue;//�ٽ� ����
                                }
                                else
                                    break;
                            }

                            // ���� �¼� line ������
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
                            //��������
                            printf("\n");
                            printf("\n");
                            printf("���� ������ . . .\n");
                            printf("\n");
                            printf("\n");
                            pay = 3000; // 3��
                            pay = 3000; // 3��
                            Sleep(pay); // ���� �ε� sleep
                            printf("������ �Ϸ�Ǿ����ϴ�.\n");
                            printf("������ �¼��� �������Դϴ� . . .\n");
                            pay = 2000; // 2��
                            Sleep(pay);
                            printf("\n\n������ �¼��� ���� �Ϸ�Ǿ����ϴ�.\n");
                            seat[number] = 1;
                            if (tmp == 0)
                                printf("������ �¼��� %d%c�¼� �Դϴ�.\n", tmp + 10, line);
                            else
                                printf("������ �¼��� %d%c�¼� �Դϴ�.\n", tmp, line); //�������� ����Ͽ� ��� �¼��� ���ŵǾ����� �ȳ�
                            printf("\n");
                            printf("\n===================================================================\n\n");
                            break;
                        }
                        system("pause");
                        system("cls");
                        break;

                    case 4://buy_menu�� 4�̸� ����
                        printf("\n�ڷ� ���ư��ϴ�.\n\n");
                        Sleep(1000);
                        break;

                    default://����ó��
                        while (getchar() != '\n');
                        printf("�߸� �ԷµǾ����ϴ�.\n");
                        continue;

                    }
                    break;
                }

                system("cls");
            }

            else if (strcmp(menu, "2") == 0) {//�޴��� 2�� ��� ����
                seatStatus(seat);
                printf("\n");
                system("PAUSE");
                system("cls");
            }

            else if (strcmp(menu, "3") == 0) {//�޴��� 3�� ��� ����
                int tmp1, chk = 0;//���ڿ� üũ���� �����ϰ� 0���� �ʱ�ȭ
                char tmp2;//���� ���� ����

                for (int i = 0; i < SIZE; i++) {//i 40�� �ݺ�
                    if (seat[i] == 1) {//�¼��� �ִ��� Ȯ��
                        chk = 1;//üũ ������ 1�� ����
                        if (i >= 0 && i < 10) {//i�� �Ǵ��Ͽ� ���ڿ� ���� ���
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
                        printf("\n%4d�� %2d�� %2d��\n1ȣ�� %d%c\n\n", ny, nm, nd, tmp1, tmp2);//����, ��, �� ȣ��, �¼� ���
                    }
                }

                if (chk == 0) {//üũ�� ������ ���� ��� ���
                    printf("\n���ŵ� �������� �����ϴ�.\n\n");
                }

                system("PAUSE");
                system("cls");
            }


            else if (strcmp(menu, "4") == 0) {//�޴��� 4�� ��� ����
                seatStatus(seat);
                while (1) {
                    printf("��� �¼� ��ȣ : ");
                    scanf("%d%c", &number, &line);
                    if (line != 'A' && line != 'B' && line != 'C' && line != 'D' || (number < 1 || number > 10)) { //����ó��
                        while (getchar() != '\n');
                        printf("\n�߸��� �¼��Դϴ�. �ٽ� �Է��ϼ���.\n\n");
                        continue;
                    }
                    else if (line == 'A') {//���ڰ� A�� ��� �״��
                        tmp = number;
                        break;
                    }
                    else if (line == 'B') {//���ڰ� B, C, D�� ��� ����
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

                if (seat[tmp - 1] == 0)//�̹� �¼������� 0�� ��� ����
                    printf("\n�̹� ����ִ� �¼��Դϴ�.\n\n");
                else {//�¼� ������ 1�̸� ����
                    printf("\n%d%c �¼��� ���Ű� ��ҵǾ����ϴ�.\n\n", number, line);
                    seat[tmp - 1] = 0;
                }
                system("PAUSE");
                system("cls");
            }




            else if (strcmp(menu, "5") == 0) {//�޴��� 5�̸� ����, ���α׷� ����
                break;
            }

            else {//����ó��
                while (getchar() != '\n');
                printf("\n�߸��� �Է��Դϴ�\n");
            }

        }

        printf("\n���α׷��� �����մϴ�.\n");
        menu[9] = "";//�޴� ���� �ʱ�ȭ
        return 0;
    }


void seatStatus(int seat[]) {   // 1A�� ���� 10D���� �¼��� ��Ȳ�� ��Ÿ���� �Լ��̴�.
    printf("\n  ���� -> �λ� 1ȣ��\n");
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

void  ageTable() {//����,����ǥ ���
    printf(" =========================================\n");
    printf("        ���(~12��) : 5,000��\n");
    printf(" -----------------------------------------\n");
    printf("      ����(13��~64��) : 10,000��\n");
    printf(" -----------------------------------------\n");
    printf("        �����(65��~) : 5,000��\n");  
    printf(" -----------------------------------------\n");
    printf("        ���� ���Ž�  :  7,000��\n");
    printf(" =========================================\n\n");
}

void timetable1() {//�ð�ǥ ���
    printf("\n ======[�ð���]======\n");
    printf("������������������������������������������\n");
    printf("��  1)05:15 - 07:49  ��\n");
    printf("��  2)13:00 - 15:47  ��\n");
    printf("��  3)19:00 - 21:38  ��\n");
    printf("������������������������������������������\n\n\n");
}

void set() {//�ܼ�â �̸��� ũ�� ����
    system("title �������Žý���");
    system("mode con:cols=191 lines=50");
}

void rail() {//���� ����

    printf("===============================================================================================================================================================================================\n");
    printf("            ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==                    == \n");
    printf("        ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==     \n");
    printf("    ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==                    ==         \n");
    printf("===============================================================================================================================================================================================\n");
    printf("\n");
    printf("\n");

    return 0;
}



void train() {//����
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
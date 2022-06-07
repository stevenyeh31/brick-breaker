#include<iostream>
#include<stdlib.h>//exit
#include <windows.h>//gotoxy
#include <string> 
#include <vector>
using namespace std;

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 20
int visibleBricks[24] = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1 };
int bricks[24][2] = {
						{2,7},{2,12},{2,17},{2,22},{2,27},{2,32},{2,37},{2,42},
						{4,7},{4,12},{4,17},{4,22},{4,27},{4,32},{4,37},{4,42},
						{6,7},{6,12},{6,17},{6,22},{6,27},{6,32},{6,37},{6,42}
};


void gotoxy(int xpos, int ypos)//�ƪ���m
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void breaksCreate(int x, int y) {
	gotoxy(x * 5, y); cout << "====";
}

//�e���
void drawBorder() {
	gotoxy(0, 0); cout << "---------------------------------------------------";
	gotoxy(0, SCREEN_HEIGHT); cout << "---------------------------------------------------";

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		gotoxy(0, i); cout << "|";
		gotoxy(SCREEN_WIDTH, i); cout << "|";
	}
}

void drawBricks() {
	for (int i = 0; i < 24; i++) {
		if (visibleBricks[i] == 1) {
			gotoxy(bricks[i][1], bricks[i][0]);
			cout << "====";
		}
	}
}


//�}�l�C��
void gamestart(char a, char d) {
	while (1) {
		drawBorder();//���
		drawBricks();//�j��

		int pole[2] = { 19,22 };//�e��l
		gotoxy(pole[1], pole[0]);
		cout << "�ӡӡӡӡӡӡ�";

		int ball[2] = { 18,25 };//�e�y
		gotoxy(ball[1], ball[0]);
		cout << "0";

		char ch = 0;
		

		int lose = 0, win = 0;
		int breaks = 24, life = 1;
		vector<vector<int> > breakerKeep(5, vector<int>(4)); {

			for (int i = 0; i < 5; i++) {
				vector<int> bkk;
				for (int j = 0; j < 4; j++) {
					bkk.push_back(1);
				}
				breakerKeep.push_back(bkk);

			}
		}

		//��l����
		if (ch == 'd' || ch == 'D' || ch == 77) {
			if (pole[1] < 23)
				pole[1] = pole[1] + 2;
		}
		if (ch == 'a' || ch == 'A' || ch == 75) {
			if (pole[1] > 2)
				pole[1] = pole[1] - 2;
		}

		if (breaks == 0 && life == 1)
			win++;
		else if (life == 0)
			lose++;
		else {
			system("cls");
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 4; j++) {
					if (breakerKeep[i].at(j) == 1) {
						breaksCreate(i, j);
					}
				}
				cout << endl;
			}

		}



		if (lose == 1) {
			system("cls");

			gotoxy(6, 5); cout << " --------------------- ";
			gotoxy(6, 6); cout << " |      �A��F       | ";
			gotoxy(6, 7); cout << " --------------------- ";

			gotoxy(6, 9); cout << " ���U ���N�� �^��D�e�� ";
			cin >> a;
		}

		if (win == 1) {
			system("cls");
			gotoxy(6, 5); cout << " --------------------- ";
			gotoxy(6, 6); cout << " |      �AĹ�F       | ";
			gotoxy(6, 7); cout << " --------------------- ";

			gotoxy(10, 9); cout << " ���U ���N�� �^��D�e�� ";
			cin >> d;
		}
	}
}

//���л���
void instruction(char select) {

	system("cls");
	cout << "���k" << endl << endl;

	cout << "1. ���U a ��l�V������" << endl;
	cout << "2. ���U d ��l�V�k����" << endl;
	cout << "3. ���U ���N�� �^��D�e�� " << endl << endl;
	cout << "" << endl;
	cout << "�z��J :";
	cin >> select;

}

//�D�{��
int main() {

	do {
		system("cls");
		char select;
		char a = '0', d = '0';
		gotoxy(6, 5); cout << " -------------------------- ";
		gotoxy(6, 6); cout << " |        ���j��           |";
		gotoxy(6, 7); cout << " -------------------------  ";
		gotoxy(6, 8); cout << "    �п�J1�}�l�C��";
		gotoxy(6, 9); cout << "    �п�J2�}�ҹC�����еe��";
		gotoxy(6, 10); cout << "    �п�J3�ӵ����C��";
		gotoxy(6, 13); cout << "�z��J :";

		cin >> select;
		if (select == '1')
			gamestart(a, d);
		else if (select == '2')
			instruction(select);
		else if (select == '3')
			exit(0);

	} while (1);




	cout << endl << endl;
	return 0;
}
// caiquan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "string.h"
#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"             
#include "time.h"                 //一个随机数种子，用来给猜拳时判断使用
#include "fstream"
#include "ostream"

using namespace std;
void menu(); 
int chinese();
int english();
int espanul();
int japan();
//----------------    ↑菜单的定义
void chinese_game();
//----------------    ↑不同界面的游戏
void shitou();
void bu();
void jiandao();
//---------------     ↑定义拳头的界面
void start_game();
//---------------     ↑游戏运行
void menu()
{
	int number;
	printf("-------------じゃんけんゲーム-------------");
	cout << endl;
	printf("------------------------------------------");
	cout << endl;
	printf("------------- Guessing   game-------------");
	cout << endl;
	printf("------------------------------------------");
	cout << endl;
	printf("-------------猜---拳---游---戏------------");
	cout << endl;
	printf("------------------------------------------");
	cout << endl;
	printf("------------- Juego  de  boxeo------------");
	cout << endl;
	printf("------------------------------------------");
	cout << endl;
	printf("-------------   1.開始する   -------------");
	cout << endl;
	printf("-------------   2. 开 始     -------------");
	cout << endl;
	printf("-------------   3.Start      -------------");
	cout << endl;
	printf("-------------   4.Adelante   -------------");
	cout << endl;
	printf("------------------------------------------");
	cout << endl;
	printf("------------------------------------------");
	cout << endl;
	printf("Por favor, elija el idioma apropiado ");
	cout << endl;
	printf("请选择合适的语言开始");
	cout << endl;
	printf("Please choose the right language to start.");
	cout << endl;
	printf("適切な言語を選択してください。");
	cout << endl;
	printf("------------    Push 1~4    -------------");
	cout << endl;
	cin >> number;
	if (number == 1)
	{
		cout << "Japan Start Game" << endl; japan();
	}
	else if (number==2)
	{
		cout << "接下来进入中文模式-并进入游戏" << endl; chinese();
	}
	else if (number == 3)
	{
		cout << "English Start Game" << endl; english();
	}
	else if (number == 4)
	{
		cout << "Espanul Start Game" << endl; espanul();
	}
	
}
void start_game()
{  	       }
int chinese()
{
	//-------------------------chinese-------------------------------
	char code_a[] = "这是一个猜拳的小游戏，请输入你要出的拳头：";
	char code_b[] = "A:剪刀\nB:石头\nC:布\nD:不玩了";
	char code_c[] = "你的选择为 %c 选择错误,退出...";   //printf("你的选择为 %c 选择错误,退出...\n", gamer);
	char code_d[] = "电脑出了";
	char code_e[] = "你出了";
	char code_f[] = "你赢了!";
	char code_j[] = "平手";
	char gamer; // 玩家出拳
	int computer; // 电脑出拳
	int result; // 比赛结果
	
	ofstream outfile;
	outfile.open("date-chinese.txt");

		while (1) {
			cout << code_a << endl;
			cout << code_b << endl;
			cin >> gamer;
			switch (gamer) {
			case 65 | 97: // A | a
				gamer = 4; break;
			case 66 | 98: // B | b
				gamer = 7; break;
			case 67 | 99: // C | c
				gamer = 10; break;
			case 68 | 100: // D | d
				return 0;
			default:
				cout << code_c + gamer << endl;
				getchar();
				system("cls"); // 清屏
				outfile << code_c + gamer << endl;
				return 0;
				break;
			}
			srand((unsigned)time(NULL)); // 随机数种子    unsigned无符号的。    
			computer = rand() % 3; // 产生随机数并取余，得到电脑出拳
			result = (int)gamer + computer; // gamer 为 char 类型，数学运算时要强制转换类型
			cout << endl;
			cout << code_d << endl;
			outfile << code_d << endl;
			cout << endl;
			cout << endl;
			switch (computer)
			{
			case 0:jiandao(); break; //4 1
			case 1:shitou(); break; //7 2
			case 2:bu(); break; //10 3
			}
			cout << endl;
			cout << code_e << endl;
			outfile << code_e << endl;
			cout << endl;
			cout << endl;
			switch (gamer)
			{
			case 4:jiandao(); break;
			case 7:shitou(); break;
			case 10:bu(); break;
			}
			if (result == 6 || result == 7 || result == 11) { cout << code_f; outfile << code_f << endl; }
			else if (result == 5 || result == 9 || result == 10) printf("电脑赢了!");
			else { cout << code_j; outfile << code_j << endl; }
			system("pause>nul&&cls"); // 暂停并清屏
		}
		// 为了避免玩一次游戏就退出程序，可以将代码放在循环中

	
}
void chinese_game()
{	              }
int english()
{
	//=========================English=============================
	char code_a_1[] = "This is a game of finger guessing game. Please input the fist you want to play\n";
	char code_b_1[] = "A: scissors \nB: stone \nC: cloth \nD: does not play\n";
	char code_c_1[] = "Your choice is for%c to choose a mistake and quit.";
	char code_d_1[] = "Computer is";
	char code_e_1[] = "You is";
	char code_f_1[] = "You Win";
	char code_j_1[] = "Hand in hand";
	char gamer; // 玩家出拳
	int computer; // 电脑出拳
	int result; // 比赛结果

	ofstream outfile;
	outfile.open("date-english.txt");
	while (1) {
		cout << code_a_1 << endl;
		cout << code_b_1<< endl;
		cin >> gamer;
		switch (gamer) {
		case 65 | 97: // A | a
			gamer = 4; break;
		case 66 | 98: // B | b
			gamer = 7; break;
		case 67 | 99: // C | c
			gamer = 10; break;
		case 68 | 100: // D | d
			return 0;
		default:
			cout << code_c_1 + gamer << endl;
			getchar();
			system("cls"); // 清屏
			outfile << code_c_1 + gamer << endl;
			return 0;
			break;
		}
		srand((unsigned)time(NULL)); // 随机数种子    unsigned无符号的。    
		computer = rand() % 3; // 产生随机数并取余，得到电脑出拳
		result = (int)gamer + computer; // gamer 为 char 类型，数学运算时要强制转换类型
		cout << endl;
		cout << code_d_1 << endl;
		outfile << code_d_1 << endl;
		cout << endl;
		cout << endl;
		switch (computer)
		{
		case 0:jiandao(); break; //4 1
		case 1:shitou(); break; //7 2
		case 2:bu(); break; //10 3
		}
		cout << endl;
		cout << code_e_1 << endl;
		cout << code_e_1 << endl;
		cout << endl;
		cout << endl;
		switch (gamer)
		{
		case 4:jiandao(); break;
		case 7:shitou(); break;
		case 10:bu(); break;
		}
		if (result == 6 || result == 7 || result == 11) { cout << code_f_1; outfile << code_f_1 << endl; }
		else if (result == 5 || result == 9 || result == 10) printf("电脑赢了!");
		else { cout << code_j_1; outfile << code_j_1 << endl; }
		system("pause>nul&&cls"); // 暂停并清屏
	}
	// 为了避免玩一次游戏就退出程序，可以将代码放在循环中
}
int espanul()
{
	//------------------------Espanul--------------------------------
	char code_a_2[] = "Es un juego de boxeo, por favor, introduzca el boxeo que tienes que salir:\n";
	char code_b_2[] = "A: Corte a, B: piedra, C: B, D: no juego.\n";
	char code_c_2[] = "Tu elección para el% C es un error.\n";
	char code_d_2[] = "El ordenador salió.\n";
	char code_e_2[] = "Estás fuera.\n";
	char code_f_2[] = "Tú ganaste\n";
	char code_j_2[] = "PPA";
	char gamer; // 玩家出拳
	int computer; // 电脑出拳
	int result; // 比赛结果
	
	ofstream outfile;
	outfile.open("date-espanul.txt");
	cout << "push text" << endl;
	while (1) {
		cout << code_a_2<< endl;
		cout << code_b_2 << endl;
		cin >> gamer;
		switch (gamer) {
		case 65 | 97: // A | a
			gamer = 4; break;
		case 66 | 98: // B | b
			gamer = 7; break;
		case 67 | 99: // C | c
			gamer = 10; break;
		case 68 | 100: // D | d
			return 0;
		default:
			cout << code_c_2 + gamer << endl;
			getchar();
			system("cls"); // 清屏
			outfile << code_c_2 + gamer << endl;
			return 0;
			break;
		}
		srand((unsigned)time(NULL)); // 随机数种子    unsigned无符号的。    
		computer = rand() % 3; // 产生随机数并取余，得到电脑出拳
		result = (int)gamer + computer; // gamer 为 char 类型，数学运算时要强制转换类型
		cout << endl;
		cout << code_d_2 << endl;
		outfile << code_d_2 << endl;
		cout << endl;
		cout << endl;
		switch (computer)
		{
		case 0:jiandao(); break; //4 1
		case 1:shitou(); break; //7 2
		case 2:bu(); break; //10 3
		}
		cout << endl;
		cout << code_e_2 << endl;
		outfile << code_d_2 << endl;
		cout << endl;
		cout << endl;
		switch (gamer)
		{
		case 4:jiandao(); break;
		case 7:shitou(); break;
		case 10:bu(); break;
		}
		if (result == 6 || result == 7 || result == 11) { cout << code_f_2; outfile << code_f_2 << endl; }
		else if (result == 5 || result == 9 || result == 10) printf("电脑赢了!");
		else { cout << code_j_2; outfile << code_j_2 << endl; }
		system("pause>nul&&cls"); // 暂停并清屏
	}
	// 为了避免玩一次游戏就退出程序，可以将代码放在循环中
}
int japan()
{
	//-----------------------Japan-------------------------------
	char code_a_3[] = "これは、あなたの拳を入力してください。";
	char code_b_3[] = "A :はさみ\ nB :石\ nC :布\ nD :遊びません";
	char code_c_3[] = "あなたの選択は% cにエラーを選択し、終了します。";
	char code_d_3[] = "パソコンが出た";
	char code_e_3[] = "あなたが出てきた";
	char code_f_3[] = "勝った！";
	char code_j_3[] = "平手";
	char gamer; // 玩家出拳
	int computer; // 电脑出拳
	int result; // 比赛结果
	//--------------------------------push text
	
	
	
	char date[100];
	
	ofstream outfile;
	outfile.open("date-Japan.txt");
	
	cout << "push text  " << endl;
	outfile << date << endl;
	

	while (1) {
		cout << code_a_3<< endl;
		cout << code_b_3<< endl;
		cin >> gamer;
		switch (gamer) {
		case 65 | 97: // A | a
			gamer = 4; break;
		case 66 | 98: // B | b
			gamer = 7; break;
		case 67 | 99: // C | c
			gamer = 10; break;
		case 68 | 100: // D | d
			return 0;
		default:
			cout << code_c_3 + gamer << endl;
			getchar();
			system("cls"); // 清屏
			outfile << code_c_3 + gamer <<endl;   ///
			return 0;
			break;
		}
		srand((unsigned)time(NULL)); // 随机数种子    unsigned无符号的。    
		computer = rand() % 3; // 产生随机数并取余，得到电脑出拳
		result = (int)gamer + computer; // gamer 为 char 类型，数学运算时要强制转换类型
		cout << endl;
		cout << code_d_3 << endl;
		outfile << code_d_3 << endl;  ///
		cout << endl;
		cout << endl;
		switch (computer)
		{
		case 0:jiandao(); break; //4 1
		case 1:shitou(); break; //7 2
		case 2:bu(); break; //10 3
		}
		cout << endl;
		cout << code_e_3 << endl;
		outfile << code_e_3 << endl;  ///
		cout << endl;
		cout << endl;
		switch (gamer)
		{
		case 4:jiandao(); break;
		case 7:shitou(); break;
		case 10:bu(); break;
		}
		if (result == 6 || result == 7 || result == 11) { cout << code_f_3; outfile << code_f_3 << endl; }  ///
		else if (result == 5 || result == 9 || result == 10) printf("电脑赢了!");
		else { cout << code_j_3; outfile << code_j_3 << endl;}  ///
		system("pause>nul&&cls"); // 暂停并清屏
	}
	// 为了避免玩一次游戏就退出程序，可以将代码放在循环中
}
int main()
{
	menu();
    
}

//---------------------------------------------------------------
void shitou()
{
	printf("....................]]/@@O[\@@\]]....................\n");
	printf("..............,/[`.,]]@@@@@@@@O]]..,[\`..............\n");
	printf(".........../[.,/@@@@@@@@@@@@@@@@@@@@@\..\\...........\n");
	printf("........,/.,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`.\`........\n"); 
	printf("......//./@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\.\`......\n");
	printf("....,/./@@@@@@@@@@@@@@@@/[[[@@@@O[[[\@@@@@@@@\.O.....\n");
	printf("...=`,@@@@@@@@@@O[`,[[.     .^  `     .@@@@@@@@.=^...\n");
	printf("..=`=@@@@@@@@@/.    .`      .^  ^      \@@@@@@@@`=^..\n");
	printf(".=^,@@@@@/. .`       ^        .`,      =@@@@@@@@@`=`.\n");
	printf("./.@@@@@^`   =.      .[`      ,=.      =@@@@@@@@@O.@.\n");
	printf("=`=@@@@@@.   .=\.     `\.      =`      .@@@@@@@@@@^=^\n");
	printf("@.O@@@@@@^     \.      =.      .^      .@@@@@@@@@@^.^\n");
	printf("@.@@@@@@@@.    .^      =^      .^      .@@@@@@@@@@^.^\n");
	printf("@.@@@@@@@@^    .\.     .^.     .\.      O@@@@@@@@@^.^\n");
	printf("=.=@@@@@@@@`    ,^      \.      @.     .O@@@@@@@@@^=^\n");
	printf(".^.@@@@@@@@@`    \.     ,^      =^     .@@@@@@@@@@.O.\n");
	printf(".=`=@@@@@@@@@@@@@/[@@@@@[[O@\]O@@O@@@@O\@@@@@@@@@`=^.\n");
	printf("..\`=@@@@@@@@@@@@@@\`.     ,@`       . .\@@@@@@@`,^..\n");
	printf("...\`,@@@@@@@@@@@@@@@@@@@@@@.  ,..,^./]`.@@@@@@`=^...\n");
	printf("....,\.\@@@@@@@@@@@@@@@@@@@@. /.../..,.,@@@@@/./`....\n");
	printf("......\`.\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/ /^......\n");
	printf("........\].[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`./`........\n");
	printf("..........,\` ,@@@@@@@@@@@@@@@@@@@@@@/`.]/...........\n");
	printf("..............[\]..[[O@@@@@@@@@/[`..]O[..............\n");
}
void bu()
{
	printf("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooooooooooooooooooooooooO@@@@Ooooooooooooooooooooooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooooooooooooooooooooooO@/...,@@\oooooooooooooooooooooooooooooooooo\n");
	printf("oooooooooooooooooooooooooooooooooo\@@@Ooooooooooo/@^.   ..@\oooooooooooooooooooooooooooooooooo\n");
	printf("oooooooooooooooooooooooooooooooo@@`...\@Ooooooooo@@.    ..=@ooooo/@\Oooooooooooooooooooooooooo\n");
	printf("oooooooooooooooooooooooooooooooO@`..   =@Oooooooo=@.    ..=@=oo@/...,@@ooooooooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooo\@...   .@@ooooooo@^.    ..=@oo@@. ...,@Ooooooooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooo=^.     .\@ooooooo@^.    ..@@oo@^.   ..@@oooooooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooo@^.     . = @OoooooO@..    . = @=oo@^.   ..@@oooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooo=^.     .=@Oooooo\@..    .=@ooo@^.   ..@@ooooooO@@@@@@ooooooooo\n");
	printf("ooooooooooooooooooooooooooooooo=@.    ...@Oooooo@^..  ...=@ooo@^.   ..@@oooooO@`...,@@oooooooo\n");
	printf("ooooooooooooooooooooooooooooooo@@.    ...@@oooo^@^..  ...=@ooo@^.   ..@OooooO@`.....@@oooooooo\n");
	printf("oooooooooooooooooooooooooooooooo@^..   ..=@Oooo=@...    .=@ooO@^.   .=@Oooo//..  ...@/oooooooo\n");
	printf("oooooooooooooooooooooooooooooooo@^..     .@@ooo=@...    .=@oo@@..   .=@Ooo\@`..   .=@ooooooooo\n");
	printf("oooooooooooooooooooooooooooooooo@@..     .=@ooo@@...    .=@oo@^.    .=@ooo@^.     =@oooooooooo\n");
	printf("oooooO\@@@@\Ooooooooooooooooooooo@^.       \@oo@^...  ...@@o@@.   ...@@o@@.     ./@ooooooooooo\n");
	printf("oo@@.............\@@ooooooooooooo@..      ........    ...,@@@`.   ../@o/@..  ...=@Oooooooooooo\n");
	printf("ooO@`..        ....=@@ooooooooooO@..                    .......   .,@Oo@^..  ...=@oooooooooooo\n");
	printf("ooooooO@@`..         .\@ooooooooo@^.                              ..@@@`.     .=@\oooooooooooo\n");
	printf("ooooooooooO@\.         .\@ooooooo@`.                                          ,@Oooooooooooooo\n");
	printf("ooooooooooooooO@^.        .,@@@`..                                          ..@@oooooooooooooo\n");
	printf("ooooooooooooooooO@^.                                                        .,@=oooooooooooooo\n");
	printf("ooooooooooooooooooO@^.                                                    ...@Oooooooooooooooo\n");
	printf("oooooooooooooooooooo@@...                                                 ..@\oooooooooooooooo\n");
	printf("ooooooooooooooooooooo@@.                                                  .=@/oooooooooooooooo\n");
	printf("oooooooooooooooooooooooo@@`..                                           ..@Ooooooooooooooooooo\n");
}
void jiandao()
{
	printf("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
	printf("oooooooooooooooooooooooooooooooooooooooo\o\\]]/o/oooooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooooooooooooO@@[[[[@@Oooooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooooooooo\\@@`.   ..=@/oooooooooooooooooo\n");
	printf("ooooooooooooooooooooooooooooooooooooo\\@@`.   ..=@/oooooooooooooooooo\n");
	printf("ooooooooooooooooooo///[[[oooooooooooo=/@.     ..=@^oooooooooooooooooo\n");
	printf("oooooooooooooooooo\/@/[[@@\oooooooooo]@^.     ..=@/oooooooooooooooooo\n");
	printf("oooooooooooooooo/\@/.....=@\/ooooooo\/@..     ..@@=oooooooooooooooooo\n");
	printf("ooooooooooooooo^`@@.     .@@=ooooooo^@^       ..@@ooooooooooooooooooo\n");
	printf("ooooooooooooooooo@^.     .=@ooooooo^O@.       .=@\/oooooooooooooooooo\n");
	printf("ooooooooooooooo/=@^.     .=@ooooooo\/@.       .@@\ooooooooooooooooooo\n");
	printf("ooooooooooooooooO@^.     .@@\oooooo^@^.       .@@]ooooooooooooooooooo\n");
	printf("ooooooooooooooo\O@..     .@@oooooooO@`.     ..=@^oooooooooooooooooooo\n");
	printf("ooooooooooooooo\=@..     .=@oooooo,@^...    ..@@ooooooooooooooooooooo\n");
	printf("ooooooooooooooo^=@..     .=@^ooooo@/.       .=@=ooooooooooooooooooooo\n");
	printf("ooooooooooooooo^=@..     .=@\oooo^@^.       .@@/ooooooooooooooooooooo\n");
	printf("ooooooooooooooo^=@..     ..@@oooo/@..     ...@@oooooooooooooooooooooo\n");
	printf("ooooooooooooooo\=@..       @@=ooo=@.      ...@^oooooooooooooooooooooo\n");
	printf("ooooooooooooooo\/@..       @@/ooo@@.      ..=@Ooooooooooooooooooooooo\n");
	printf("oooooooooooooooo@@..       =@/oo`@^.      ..=@=oooooooooooooooooooooo\n");
	printf("ooooooooooooooooO@`.       =@^o//@^.      ..@^ooooooooooooooooooooooo\n");
	printf("oooooooooooooooo^@^.       .@@/\@/..  .../@@[[[@@@@/\oooooooooooooooo\n");
	printf("ooooooooooooooooo@^.             ..,/@@/[.. ..,\@`.\@oooooooooooooooo\n");
	printf("ooooooooooooooo\o@^.       ..]]@@@[`.         ..=@^=@^/=\]]/`o\oooooo\n");
	printf("oooooooooooooooo*@^.   ../@@[`....              =@^=@@@/....[@@[ooooo\n");
	printf("oooooooooooooooo]@^. ../@`..                  ..=@`/@`.     ..=@/o\oo\n");
	printf("ooooooooooooooo@^,@@..                  .,@@/`=@^         ./^.=@=oooo\n");
	printf("ooooooooooooo^\@@@`.                 ,]@@/`...@@.       .,@`..@@ooooo\n");
	printf("oooooooooooo[@@`..             ,@@`..     ..,@^..     .=@`. ..@@ooooo\n");
	printf("ooooooooooo/@/..             .,@@@..      .,@/.       ,@^.. ..@@/oooo\n");
	printf("oooooooooo[@/. .             .=@@^..      .@/..     .=@^.   ..@/ooooo\n");
	printf("oooooooooo/@^.               .=@@.      ..=@^     ../@`..   ..@^=oooo\n");
	printf("oooooooooo/@^.                 @@.      .=@^[@@@@@[..       ./@oooooo\n");
	printf("oooooooooo^@^.                 @@.    .../@......         ...@\=/oooo\n");
	printf("oooooooooo^@^.                 \@...  ..,@^               ..=@=ooooo \n");
	printf("ooooooooooo\@...               .\@\]..,/@^.               ..@^/oooooo\n");
	printf("oooooooooo^/@...               ...,[\@[`.                 .=@*ooooooo\n");
	printf("ooooooooooo/@^..                                        ..,@^oooooooo\n");
	printf("oooooooooooo=@..                                      ...=@^ooooooooo\n");
	printf("oooooooooooo=@.. .......                              ..=@Oo/oooooooo\n");
}

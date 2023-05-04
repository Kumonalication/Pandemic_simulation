//±©Ò»³À 202130270029

#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "character.h"
#include "basis.h"
#include "place.h"

using namespace std;

place build(30000,0.95);
double Rt = 0.5;
bool report = false;
int main() {
	//ofstream fout;
	//fout.open("C:\\Users\\byc51\\Desktop\\8848.txt",ios::out);
	cencus student(18888,88);
	srand((unsigned)time(NULL));
	printf("Hello world!\n");
	int time = 0;
	//fout << time << "," << student.infected() << endl;
	printf("%d\n%d %d\n", time, student.infected(), 18888);
	while (student.infected() < 18888) {
		Sleep(500);
		system("cls");
		++time;
		student.move(time);
		//fout << time << "," << student.infected() << endl;
		printf("%d\n%d %d\n", time, student.infected(), 18888);
		
	}
	//fout << time << "," << student.infected() << endl;
	return 0;
}
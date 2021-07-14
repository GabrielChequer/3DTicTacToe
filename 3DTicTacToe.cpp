#include <iostream>
#include <time.h>
#include <random>
#include <conio.h>

using namespace std;

/*
This program allows computers to play a 10 games of 3D Tic-Tac-Toe in a Round Robbin Fashion
*/

#define COMP3NUM 27

void draw();
void play1_2();
void play2_3();
void play1_3();
void checkWinner1();
void checkWinner2();
void checkWinner3();


const int PopulationSize = 27;
const int ArraySize = 14;
char board[PopulationSize];
int win1 = 0, win2 = 0, win3 = 0, points1 = 0, points2 = 0, points3 = 0;

int main() {
	//Comp 1 against comp 2
	for (int i = 0; i < 10; i++) {
		system("CLS");
		win1 = 0;
		win2 = 0;
		play1_2();
		draw();
		checkWinner1();
		cout << "\nPlayer 1: " << win1 << ".";
		cout << "\nPlayer 2: " << win2 << ".";
		if (win1 > win2) {
			points1++;
		}
		if (win1 < win2) {
			points2++;
		}
		if (win1 == win2) {
			points1 = points1;
			points2 = points2;
		}
	}
	if (points1 > points2) {
		cout << "\n\nPlayer 1 wins.\nPress Enter";
	}
	if (points1 < points2) {
		cout << "\n\nPlayer 2 wins.\nPress Enter";
	}
	if (points1 == points2) {
		cout << "\n\nIt's a tie.\nPress Enter";
	}
	getchar();
	//End Comp1 against Comp2
	//Comp 2 against Comp 3
	for (int i = 0; i < 10; i++) {
		//Clean board
		for (int i = 0; i < PopulationSize; i++) {
			board[i] = ' ';
		}
		system("CLS");
		win2 = 0;
		win3 = 0;
		play2_3();
		draw();
		checkWinner1();
		cout << "\nPlayer 2: " << win2 << ".";
		cout << "\nPlayer 3: " << win3 << ".";
		if (win2 > win3) {
			points2++;
		}
		if (win2 < win3) {
			points3++;
		}
		if (win2 == win3) {
			points2 = points2;
			points3 = points3;
		}
	}
	if (points2 > points3) {
		cout << "\n\nPlayer 2 wins.\nPress Enter";
	}
	if (points2 < points3) {
		cout << "\n\nPlayer 3 wins.\nPress Enter";
	}
	if (points2 == points3) {
		cout << "\n\nIt's a tie.\nPress Enter";
	}
	getchar();
	//End Comp2 against Comp3
	//Comp1 against Comp3
	for (int i = 0; i < 10; i++) {
		system("CLS");
		win1 = 0;
		win3 = 0;
		play1_3();
		draw();
		checkWinner3();
		cout << "\nPlayer 1: " << win1 << ".";
		cout << "\nPlayer 3: " << win3 << ".";
		if (win1 > win3) {
			points1++;
		}
		if (win1 < win3) {
			points3++;
		}
		if (win1 == win3) {
			points1 = points1;
			points3 = points3;
		}
	}
	if (points1 > points3) {
		cout << "\n\nPlayer 1 wins.\nPress Enter";
	}
	if (points1 < points3) {
		cout << "\n\nPlayer 3 wins.\nPress Enter";
	}
	if (points1 == points3) {
		cout << "\n\nIt's a tie.\nPress Enter";
	}
	getchar();
	//End of Comp1 against Comp3
	return 0;
}
void draw() {
	cout << "Board 1:\n";
	for (int i = 0; i < 9; i++) {
		if ((i < 2) || ((i > 2) && (i < 5)) || ((i > 5) && (i < 8))) {
			cout << board[i] << " |";
		}
		else {
			if (i == 8) {
				cout << board[i];
			}
			else {
				cout << board[i] << "\n--------\n";
			}
		}
	}
	cout << "\n\nBoard 2:\n";
	for (int i = 9; i < 18; i++) {
		if ((i < 11) || ((i > 11) && (i < 14)) || ((i > 14) && (i < 17))) {
			cout << board[i] << " |";
		}
		else {
			if (i == 17) {
				cout << board[i];
			}
			else {
				cout << board[i] << "\n--------\n";
			}
		}
	}
	cout << "\n\nBoard 3:\n";
	for (int i = 18; i < 27; i++) {
		if ((i < 20) || ((i > 20) && (i < 23)) || ((i > 23) && (i < 26))) {
			cout << board[i] << " |";
		}
		else {
			if (i == 26) {
				cout << board[i];
			}
			else {
				cout << board[i] << "\n--------\n";
			}
		}
	}

}
void play1_2() {
	for (int i = 0; i < PopulationSize; i++) {
		board[i] = ' ';
	}
	int population[PopulationSize];
	for (int i = 0; i < PopulationSize; i++) {
		population[i] = i + 1;
	}
	int arreglo[ArraySize];
	srand(time(0));
	for (int i = 0; i < PopulationSize; i++) {
		int j = rand() % PopulationSize;
		if (i == j) {
			j = (i + 1) % PopulationSize;
		}
		swap(population[i], population[j]);
	}

	for (int i = 0; i < ArraySize; ++i) {
		arreglo[i] = population[i] - 1;
		for (int j = 0; j < PopulationSize; j++) {
			if (j == arreglo[i]) {
				board[j] = 'x';
			}
			else {
				board[j] = board[j];
			}
		}
	}
	for (int i = 0; i <= PopulationSize; i++) {
		if (board[i] == ' ') {
			board[i] = 'o';
		}
	}
}
void play2_3() {
	int numbers[COMP3NUM];
	int arreglo[ArraySize];
	int i, n, tmp;
	srand(time(NULL));
	// Array Initialization
	for (i = 0; i < COMP3NUM; ++i)
		numbers[i] = i;
	//Array Shuffle
	for (i = COMP3NUM; i > 1;)
	{
		n = rand() % i;
		--i;
		tmp = numbers[n];
		numbers[n] = numbers[i];
		numbers[i] = tmp;
	}
	// Iterate through the array. Your numbers are already random
	for (i = 0; i < 14; i++) {
		arreglo[i] = numbers[i];
	}

	for (int i = 0; i < ArraySize; ++i) {
		arreglo[i] = numbers[i] - 1;
		for (int j = 0; j < PopulationSize; j++) {
			if (j == arreglo[i]) {
				board[j] = 'x';
			}
			else {
				board[j] = board[j];
			}
		}
	}
	for (int i = 0; i <= PopulationSize; i++) {
		if (board[i] == ' ') {
			board[i] = 'o';
		}
	}
}
void play1_3() {
	for (int i = 0; i < PopulationSize; i++) {
		board[i] = ' ';
	}
	int population[PopulationSize];
	for (int i = 0; i < PopulationSize; i++) {
		population[i] = i + 1;
	}
	int arreglo[ArraySize];
	srand(time(0));
	for (int i = 0; i < PopulationSize; i++) {
		int j = rand() % PopulationSize;
		if (i == j) {
			j = (i + 1) % PopulationSize;
		}
		swap(population[i], population[j]);
	}

	for (int i = 0; i < ArraySize; ++i) {
		arreglo[i] = population[i] - 1;
		for (int j = 0; j < PopulationSize; j++) {
			if (j == arreglo[i]) {
				board[j] = 'x';
			}
			else {
				board[j] = board[j];
			}
		}
	}
	for (int i = 0; i <= PopulationSize; i++) {
		if (board[i] == ' ') {
			board[i] = 'o';
		}
	}
}
void checkWinner1() {
	//Left to right
//Top row
	if ((board[0] == board[1]) && (board[1] == board[2])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[9] == board[10]) && (board[10] == board[11])) {
		if (board[9] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[18] == board[19]) && (board[19] == board[20])) {
		if (board[18] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Middle row
	if ((board[3] == board[4]) && (board[4] == board[5])) {
		if (board[3] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[12] == board[13]) && (board[13] == board[14])) {
		if (board[12] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[21] == board[22]) && (board[22] == board[23])) {
		if (board[21] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Bottom row
	if ((board[6] == board[7]) && (board[7] == board[8])) {
		if (board[6] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[15] == board[16]) && (board[16] == board[17])) {
		if (board[15] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[24] == board[25]) && (board[25] == board[26])) {
		if (board[24] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Top to bottom
//Left row
	if ((board[0] == board[3]) && (board[3] == board[6])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[9] == board[12]) && (board[12] == board[15])) {
		if (board[9] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[18] == board[21]) && (board[21] == board[24])) {
		if (board[18] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Middle row
	if ((board[1] == board[4]) && (board[4] == board[7])) {
		if (board[1] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[10] == board[13]) && (board[13] == board[16])) {
		if (board[10] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[19] == board[22]) && (board[22] == board[25])) {
		if (board[19] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Right row
	if ((board[2] == board[5]) && (board[5] == board[8])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[11] == board[14]) && (board[14] == board[17])) {
		if (board[11] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[20] == board[23]) && (board[23] == board[26])) {
		if (board[20] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Diagonal
//Top left to bottom right
	if ((board[0] == board[4]) && (board[4] == board[8])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[9] == board[13]) && (board[13] == board[17])) {
		if (board[9] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[18] == board[22]) && (board[22] == board[26])) {
		if (board[18] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Top right to bottom left
	if ((board[2] == board[4]) && (board[4] == board[6])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[11] == board[13]) && (board[13] == board[15])) {
		if (board[11] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[20] == board[22]) && (board[22] == board[24])) {
		if (board[20] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Up to Down(3D)
	if ((board[0] == board[9]) && (board[9] == board[18])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[1] == board[10]) && (board[10] == board[19])) {
		if (board[1] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[2] == board[11]) && (board[11] == board[20])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[3] == board[12]) && (board[12] == board[21])) {
		if (board[3] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[4] == board[13]) && (board[13] == board[22])) {
		if (board[4] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[5] == board[14]) && (board[14] == board[23])) {
		if (board[5] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[6] == board[15]) && (board[15] == board[24])) {
		if (board[6] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[7] == board[16]) && (board[16] == board[25])) {
		if (board[7] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[8] == board[17]) && (board[17] == board[26])) {
		if (board[8] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Up AND down
//Left to right
	if ((board[0] == board[10]) && (board[10] == board[20])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[3] == board[13]) && (board[13] == board[23])) {
		if (board[3] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[6] == board[16]) && (board[16] == board[26])) {
		if (board[6] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Right to left
	if ((board[2] == board[10]) && (board[10] == board[18])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[5] == board[13]) && (board[13] == board[21])) {
		if (board[5] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[8] == board[16]) && (board[16] == board[24])) {
		if (board[8] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Top to bottom
	if ((board[0] == board[12]) && (board[12] == board[24])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[1] == board[13]) && (board[13] == board[25])) {
		if (board[1] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[2] == board[14]) && (board[14] == board[26])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	//Bottom to top
	if ((board[6] == board[12]) && (board[12] == board[18])) {
		if (board[6] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[7] == board[13]) && (board[13] == board[19])) {
		if (board[7] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
	if ((board[8] == board[14]) && (board[14] == board[20])) {
		if (board[8] == 'x') {
			win1++;
		}
		else {
			win2++;
		}
	}
}
void checkWinner2() {
	//win2 and win3
			//Left to right
		//Top row
	if ((board[0] == board[1]) && (board[1] == board[2])) {
		if (board[0] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[9] == board[10]) && (board[10] == board[11])) {
		if (board[9] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[18] == board[19]) && (board[19] == board[20])) {
		if (board[18] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Middle row
	if ((board[3] == board[4]) && (board[4] == board[5])) {
		if (board[3] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[12] == board[13]) && (board[13] == board[14])) {
		if (board[12] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[21] == board[22]) && (board[22] == board[23])) {
		if (board[21] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Bottom row
	if ((board[6] == board[7]) && (board[7] == board[8])) {
		if (board[6] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[15] == board[16]) && (board[16] == board[17])) {
		if (board[15] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[24] == board[25]) && (board[25] == board[26])) {
		if (board[24] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Top to bottom
//Left row
	if ((board[0] == board[3]) && (board[3] == board[6])) {
		if (board[0] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[9] == board[12]) && (board[12] == board[15])) {
		if (board[9] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[18] == board[21]) && (board[21] == board[24])) {
		if (board[18] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Middle row
	if ((board[1] == board[4]) && (board[4] == board[7])) {
		if (board[1] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[10] == board[13]) && (board[13] == board[16])) {
		if (board[10] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[19] == board[22]) && (board[22] == board[25])) {
		if (board[19] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Right row
	if ((board[2] == board[5]) && (board[5] == board[8])) {
		if (board[2] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[11] == board[14]) && (board[14] == board[17])) {
		if (board[11] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[20] == board[23]) && (board[23] == board[26])) {
		if (board[20] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Diagonal
//Top left to bottom right
	if ((board[0] == board[4]) && (board[4] == board[8])) {
		if (board[0] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[9] == board[13]) && (board[13] == board[17])) {
		if (board[9] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[18] == board[22]) && (board[22] == board[26])) {
		if (board[18] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Top right to bottom left
	if ((board[2] == board[4]) && (board[4] == board[6])) {
		if (board[2] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[11] == board[13]) && (board[13] == board[15])) {
		if (board[11] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[20] == board[22]) && (board[22] == board[24])) {
		if (board[20] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Up to Down(3D)
	if ((board[0] == board[9]) && (board[9] == board[18])) {
		if (board[0] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[1] == board[10]) && (board[10] == board[19])) {
		if (board[1] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[2] == board[11]) && (board[11] == board[20])) {
		if (board[2] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[3] == board[12]) && (board[12] == board[21])) {
		if (board[3] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[4] == board[13]) && (board[13] == board[22])) {
		if (board[4] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[5] == board[14]) && (board[14] == board[23])) {
		if (board[5] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[6] == board[15]) && (board[15] == board[24])) {
		if (board[6] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[7] == board[16]) && (board[16] == board[25])) {
		if (board[7] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[8] == board[17]) && (board[17] == board[26])) {
		if (board[8] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Up AND down
//Left to right
	if ((board[0] == board[10]) && (board[10] == board[20])) {
		if (board[0] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[3] == board[13]) && (board[13] == board[23])) {
		if (board[3] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[6] == board[16]) && (board[16] == board[26])) {
		if (board[6] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Right to left
	if ((board[2] == board[10]) && (board[10] == board[18])) {
		if (board[2] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[5] == board[13]) && (board[13] == board[21])) {
		if (board[5] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[8] == board[16]) && (board[16] == board[24])) {
		if (board[8] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Top to bottom
	if ((board[0] == board[12]) && (board[12] == board[24])) {
		if (board[0] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[1] == board[13]) && (board[13] == board[25])) {
		if (board[1] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[2] == board[14]) && (board[14] == board[26])) {
		if (board[2] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	//Bottom to top
	if ((board[6] == board[12]) && (board[12] == board[18])) {
		if (board[6] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[7] == board[13]) && (board[13] == board[19])) {
		if (board[7] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
	if ((board[8] == board[14]) && (board[14] == board[20])) {
		if (board[8] == 'x') {
			win2++;
		}
		else {
			win3++;
		}
	}
}
void checkWinner3() {
	//win1 and win3
			//Left to right
		//Top row
	if ((board[0] == board[1]) && (board[1] == board[2])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[9] == board[10]) && (board[10] == board[11])) {
		if (board[9] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[18] == board[19]) && (board[19] == board[20])) {
		if (board[18] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Middle row
	if ((board[3] == board[4]) && (board[4] == board[5])) {
		if (board[3] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[12] == board[13]) && (board[13] == board[14])) {
		if (board[12] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[21] == board[22]) && (board[22] == board[23])) {
		if (board[21] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Bottom row
	if ((board[6] == board[7]) && (board[7] == board[8])) {
		if (board[6] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[15] == board[16]) && (board[16] == board[17])) {
		if (board[15] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[24] == board[25]) && (board[25] == board[26])) {
		if (board[24] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Top to bottom
//Left row
	if ((board[0] == board[3]) && (board[3] == board[6])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[9] == board[12]) && (board[12] == board[15])) {
		if (board[9] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[18] == board[21]) && (board[21] == board[24])) {
		if (board[18] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Middle row
	if ((board[1] == board[4]) && (board[4] == board[7])) {
		if (board[1] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[10] == board[13]) && (board[13] == board[16])) {
		if (board[10] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[19] == board[22]) && (board[22] == board[25])) {
		if (board[19] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Right row
	if ((board[2] == board[5]) && (board[5] == board[8])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[11] == board[14]) && (board[14] == board[17])) {
		if (board[11] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[20] == board[23]) && (board[23] == board[26])) {
		if (board[20] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Diagonal
//Top left to bottom right
	if ((board[0] == board[4]) && (board[4] == board[8])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[9] == board[13]) && (board[13] == board[17])) {
		if (board[9] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[18] == board[22]) && (board[22] == board[26])) {
		if (board[18] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Top right to bottom left
	if ((board[2] == board[4]) && (board[4] == board[6])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[11] == board[13]) && (board[13] == board[15])) {
		if (board[11] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[20] == board[22]) && (board[22] == board[24])) {
		if (board[20] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Up to Down(3D)
	if ((board[0] == board[9]) && (board[9] == board[18])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[1] == board[10]) && (board[10] == board[19])) {
		if (board[1] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[2] == board[11]) && (board[11] == board[20])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[3] == board[12]) && (board[12] == board[21])) {
		if (board[3] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[4] == board[13]) && (board[13] == board[22])) {
		if (board[4] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[5] == board[14]) && (board[14] == board[23])) {
		if (board[5] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[6] == board[15]) && (board[15] == board[24])) {
		if (board[6] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[7] == board[16]) && (board[16] == board[25])) {
		if (board[7] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[8] == board[17]) && (board[17] == board[26])) {
		if (board[8] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Up AND down
//Left to right
	if ((board[0] == board[10]) && (board[10] == board[20])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[3] == board[13]) && (board[13] == board[23])) {
		if (board[3] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[6] == board[16]) && (board[16] == board[26])) {
		if (board[6] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Right to left
	if ((board[2] == board[10]) && (board[10] == board[18])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[5] == board[13]) && (board[13] == board[21])) {
		if (board[5] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[8] == board[16]) && (board[16] == board[24])) {
		if (board[8] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Top to bottom
	if ((board[0] == board[12]) && (board[12] == board[24])) {
		if (board[0] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[1] == board[13]) && (board[13] == board[25])) {
		if (board[1] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[2] == board[14]) && (board[14] == board[26])) {
		if (board[2] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	//Bottom to top
	if ((board[6] == board[12]) && (board[12] == board[18])) {
		if (board[6] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[7] == board[13]) && (board[13] == board[19])) {
		if (board[7] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
	if ((board[8] == board[14]) && (board[14] == board[20])) {
		if (board[8] == 'x') {
			win1++;
		}
		else {
			win3++;
		}
	}
}

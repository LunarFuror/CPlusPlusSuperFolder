/*
 * diceRolling.cpp
 *  7.16: Week7
 *   Created on: Feb 28, 2014
 *      Author: lunarfuror
 */
#include <cstdlib>
#include <array>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	array<int, 11> sum = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i < 36000; i++){
		sum[rand()%6 + rand()%6] ++;
	}
	cout << left;
	for(int i = 2; i < 13; i ++){
		cout << setw(7) << i << "|";
	}

  cout << endl;

	for(int times: sum){
		cout << setw(7) << times << "|";
	}
	return 0;
}

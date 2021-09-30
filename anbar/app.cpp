#include <iostream>
using namespace std;


class Shop {
public:
	int C; //hazine anbar kardane har kamioon
	int K; //hazine har bar sefaresh
	int S; //size anbar
	int I; //tedad mahayi ke pishbiniashoono darim
	int D[999]; //pishbini mizaan foroosh [mah]
	int minHazine(int i,int s) {
		if (i == 0)
			return 0;
		if (s + D[i] > s) {
			return minHazine(i-1,0)+ K;
		}
		else {
			if (minHazine(i - 1, 0)+ K < minHazine(i - 1, s + D[i]) + s*C){
				return minHazine(i - 1, 0)+ K;
            }
			else{
				return minHazine(i - 1, s + D[i]) + s*C;
            }
		}
	}
	void set() {
		cout << "hazine anbar kardane har kamioon =";
		cin >> C;
		cout << "hazine har bar sefaresh =";
		cin >> K;
		cout << "size anbar =";
		cin >> S;
		cout << "tedad mahayi ke pishbiniashoono darim =";
		cin >> I;
		D[0] = 0;
		for (int i = 1; i <= I;i++) {
			cout << "mizan forooshe mahe"<<i<<"m =";
			cin >> D[i];
		}
	}
	void printMinHazine() {
		cout << "kamtarin Hazine =" << minHazine(I,0);
	}
};

int main() {
	Shop shop;
	shop.set();
	shop.printMinHazine();

    system("pause");
	return 0;
}
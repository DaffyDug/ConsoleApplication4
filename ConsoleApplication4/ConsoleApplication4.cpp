#include <iostream>
#include <vector>
using namespace std;

class GAME
{
public:
	virtual int GamePlay() = 0;
	virtual int getmoney() = 0;
};

class Win50or50 : public GAME
{
protected:
	int levl;
	int money;
	int ChoiceComputer;
public:
	Win50or50(int levl, int newmoney, int ChoiceComputer)
	{
		this->levl = levl;
		money = newmoney;
		this->ChoiceComputer = ChoiceComputer;
	}
	virtual int GamePlay() override
	{

		if (levl == 1)
		{
			if (money >= 100)
			{
				cout << "выберите: \n1. орел \n2. решка" << endl;
				int inputvalue;
				cin >> inputvalue;
				ChoiceComputer = 0 + rand() % 2;
				if (inputvalue == ChoiceComputer)
				{
					money *= levl + 1;
					cout << "на счету у вас: " << money << "$" << endl;
				}
				else
				{
					cout << "вы проиграли" << endl;
					money = 0;
					cout << "на счету у вас: " << money << "$" << endl;
				}
			}
			else
			{
				cout << "слишком мало денег" << endl;
			}
		}
		return money;
	}
	int getmoney() override
	{
		return money;
	}
};
class Win33or66 : public Win50or50
{
public:
	Win33or66(int levl, int money, int ChoiceComputer) :Win50or50(this->levl, this->money, this->ChoiceComputer)
	{

	}
	virtual int GamePlay() override
	{
		if (levl == 2)
		{
			if (Win50or50::money >= 100)
			{
				cout << "выберите: \n1. орел \n2. решка" << endl;
				int inputvalue;
				cin >> inputvalue;
				ChoiceComputer = 1 + rand() % 2;
				ChoiceComputer = 1 + rand() % 2;
				if (inputvalue == ChoiceComputer)
				{
					money *= levl + 1;
					cout << "на счету у вас: " << money << "$" << endl;
				}
				else
				{
					cout << "вы проиграли" << endl;
					money = 0;
					cout << "на счету у вас: " << money << "$" << endl;
				}
			}
			else
			{
				cout << "слишком мало денег" << endl;
			}
		}
		return money;
	}
	virtual int getmoney() override
	{
		return money;
	}
};



int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");

	Win50or50 game(1, 400, 0);
	Win50or50 game2(2, 400, 0);
	game.GamePlay();
	game.GamePlay();

	GAME* AppGame[2];
	AppGame[0] = &game;
	AppGame[1] = &game2;

	if (AppGame[1]->getmoney() > 0)
	{
		for (int i = 0; i < 2; i++)
		{
			AppGame[i]->GamePlay();
		}
	}
}

/*
#include <iostream>
#include <vector>
#include<cstdlib>
using namespace std;

class Game {
protected:
	double balance;
public:
	Game(double inbalance) : balance(inbalance){}

	virtual double play() = 0;
};

class x2 : public Game {
public:
	x2(double inbalance) : Game(inbalance) {}

	double play() {
		if (balance <= 100) {
			cout << "Деньги кончились, вы проиграли" << endl;
		}
		int result = 0 + rand() % 2;
		if (result == 1) {
			balance *= 2;
			cout << "Вы победили, ваш баланс: " << balance << endl;
		}
		else {
			balance = 0;
			cout << "Вы проиграли" << endl;
		}
		return balance;
	}
};
class x4 : public x2 {
public:
	x4(double inbalance) : x2(inbalance) {}

	double play() {
		if (balance <= 0) {
			cout << "Деньги кончились, вы проиграли" << endl;
		}
		int result = 0 + rand() % 2;
		if (result == 1) {
			balance *= 2;
			cout << "Вы победили, ваш баланс: " << balance << endl;
		}
		else {
			balance = 0;
			cout << "Вы проиграли" << endl;
		}
		return balance;
	}
};


int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int money;
	cout << "Хотите играть?\n 1 - да, 2 - нет" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) {

		cout << "Введите сумму"<<endl;
		cin >> money;
		if (money >= 100) {
			x2 game1(money);
			game1.play();

		}
		else {
			cout << "Маловато денег";
		}
	}


}




*/
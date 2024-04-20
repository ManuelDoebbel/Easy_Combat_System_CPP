#pragma once
#include <iostream>
#include <string>
#include <random>
#include <stdlib.h>

using namespace std;

class Game {
private:
	const int basicPlayerHP = 100;
	int playerHP = 100;
	int currentPlayerHP = 100;

	const int basicEnemyHP = 100;
	int enemyHP = 100;
	int currentEnemyHP = 100;

	const int playerBasicDamage = 10;
	int playerDamage = 10;

	const int enemyBasicDamage = 10;
	int enemyDamage = 10;

	const int basicHealAmount = 5;
	int healAmount = 5;

	int StatRandomizer() {
		random_device statRnd;
		mt19937 statGen(statRnd());
		uniform_int_distribution<> distr(10, 40);

		int statRandNumber = distr(statGen);
		return statRandNumber;
	}

	int PlayerHP(int sRN, int bPHP) {
		int statRandNumber = sRN;
		int basicPlayerHP = bPHP;

		playerHP = statRandNumber += basicPlayerHP;
		return playerHP;
	}

	int EnemyHP(int sRN, int bEHP) {
		int statRandNumber = sRN;
		int basicEnemyHP = bEHP;

		enemyHP = statRandNumber += basicEnemyHP;
		return enemyHP;
	}

	int PlayerDamage(int sRN, int bPD) {
		int statRandNumber = sRN;
		int basicPlayerDamage = bPD;

		playerDamage = statRandNumber += basicPlayerDamage;
		return playerDamage;
	}

	int EnemyDamage(int sRN, int bED) {
		int statRandNumber = sRN;
		int basicEnemyDamage = bED;

		enemyDamage = statRandNumber += basicEnemyDamage;
		return enemyDamage;
	}

	int HealAmount(int sRN, int bHA) {
		int statRandNumber = sRN;
		int basicHealAmount = bHA;

		healAmount = statRandNumber += basicHealAmount;
		return healAmount;
	}

public:
	Game() {
		PlayerHP(StatRandomizer(), basicPlayerHP);
		EnemyHP(StatRandomizer(), basicEnemyHP);
		healAmount = StatRandomizer() + basicHealAmount;
	}

	void DisplayStats() {
		cout << "Your HP: " << playerHP << endl;
		cout << "Enemy HP: " << enemyHP << endl;
	}

	void StartGame() {
		random_device enemyRnd;
		mt19937 enemyGen(enemyRnd());
		uniform_int_distribution<> enemyDistr(0, 1);

		random_device healRnd;
		mt19937 healGen(healRnd());
		uniform_int_distribution<> distr(10, 25);

		while (playerHP > 0 && enemyHP > 0) {
			cout << "----- Player turn -----" << endl;
			cout << "Player HP: " << playerHP << " - Enemy HP: " << enemyHP << endl;
			cout << "Enter 'a' to attack or 'h' to heal." << endl;

			string playerInput;
			cin >> playerInput;

			if (playerInput == "a")
			{
				playerDamage = PlayerDamage(StatRandomizer(), playerBasicDamage);
				enemyHP -= playerDamage;
				cout << "Player attack enemy and deals " << playerDamage << " damage" << endl;
			}
			else if (playerInput == "h")
			{
				healAmount = HealAmount(StatRandomizer(), basicHealAmount);
				playerHP += healAmount;
				cout << "Player restores " << healAmount << " health Points!" << endl;
			}
			else
			{
				cout << "Enter valid input!" << endl;
			}

			// Enemy turn
			if (enemyHP > 0)
			{
				cout << "----- Enemy turn -----" << endl;
				int enemyRandNumber = enemyDistr(enemyGen);

				if (enemyRandNumber == 0)
				{
					enemyDamage = EnemyDamage(StatRandomizer(), enemyBasicDamage);
					playerHP -= enemyDamage;
					cout << "Enemy attacks and deals " << enemyDamage << " damage!" << endl;
				}
				else
				{
					healAmount = HealAmount(StatRandomizer(), basicHealAmount);
					enemyHP += healAmount;
					cout << "Enemy restores " << healAmount << " health points!" << endl;
				}
			}
		}

		if (playerHP > 0)
		{
			cout << "Congratulations! You have won!" << endl;
		}
		else
		{
			cout << "You lose!" << endl;
		}
	}
};
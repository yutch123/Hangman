// Программа Hangman (виселица)

#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <iostream>
using namespace std;

int main()
{
	// подготовка
	const int Max_wrong = 8; // кол-во попыток
	vector<string>words; // подборка слов для загадывания
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0]; // слово для отгадывания
	int wrong = 0; // количество ошибочных вариантов
	string soFar(THE_WORD.size(), '-'); // часть слова открытая на данный момент
	string used = ""; // уже отгаданные буквы
	cout << "Welcome to Hangman! Good Luck!\n";
	// основной цикл
	while ((wrong < Max_wrong) && (soFar != THE_WORD)) // если кол-чо попыток не кончилось и слово не отгадано
	{
		cout << "\n\nYou have " << (Max_wrong - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far. The word is:\n" << soFar << endl;
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess); // перевод в верхний регистр
		// так как загаданное слово записано в верхнем регистре
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";
			// обновить переменную soFar, включив в неё новую угаданную букву
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " isn't in the word.\n";
			++wrong;
		}
	}
		// конец игры 
		if (wrong == Max_wrong)
		{
			cout << "\nYou've been hanged!";
		}
		else
		{
			cout << "\nYou guessed it!";
		}
		cout << "\nThe word was " << THE_WORD << endl;
		return 0;

}


#include <iostream>
#include <fstream>
#include <string>
/* Программа РЫБАЛКА.
   Из файла river последавательно читаем слова и сравниваем с введённым словом (названием рыбы)
   Если названия совпадают, то пойманную рыбу кладём в корзину.
   Особо тут коментировать нечего
*/
int main()
{
	std::string fish, take;
	int haul = 0, sumHaul = 0;
	bool finish = false;
	// Открываем файл РЕКА но ввод
	std::ifstream river("River.txt");
	// Открываем файл КОРЗИНКА на запись
	std::ofstream basket("Basket.txt", std::ios::app);
	if (river.is_open())
	{
		while(!finish)
		{
			std::cout << "What kind of fish will you catch? For exit type - quit.";
			// Вводим название рыбы, которую хочется изловить.
			std::cin >> fish;
			// Можно было обойтись без булевой переменной, но переделвать уже лень
			// Надо было while (fish != "quit")
			// Если попалась рыба quit, то идём домой.
			if (fish == "quit")
				finish = true;
			else
			{
				while (!river.eof())
				{
					river >> take;         // И закинул старик невод
					if (take == fish)      // Пришел невод с одною тиной.
					{
						haul++;            // Пришел невод с одною рыбкой.
						sumHaul++;
					}
				}
				if (haul > 0)
				{
					// Вывод на экран улова
					std::cout << "You take " << haul << ' ' << fish << '\n';
					if (basket.is_open())
					{
						basket.width(10);
						basket << fish;
						basket.width(3);
						basket << haul << '\n';
					}
					else
						std::cout << "You forgot the basket at home.\n";
				}
				else
					std::cout << "This fish not present into the river.\n";
				river.seekg(0, std::ios::beg);
				haul = 0;
			}
		}
	}
	else
		std::cout << "No fish in the river.\n";
	river.close();
	std::cout << "\nYour haul was " << sumHaul << " fishes.\ Program finished.\n";
}
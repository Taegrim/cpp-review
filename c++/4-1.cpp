#include <iostream>

class Animal {
public:
	Animal() {}
	Animal(int _food, int _weight) : food{ _food }, weight{ _weight } {}
	~Animal() = default;

	void SetAnimal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}

	void IncreaseFood(int inc) {
		food += inc;
		weight += (inc / 3);
	}

	void ViewStat() {
		std::cout << "food   : " << food << std::endl;
		std::cout << "weight : " << weight << std::endl;
	}

private:
	int food;
	int weight;
};

class Date {
public:
	void SetDate(int year, int month, int date);

	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc) { year_ += inc; }

	void ShowDate();

private:
	bool CheckLeapYear() {
		if ((year_ % 4 == 0) && (year_ % 100 == 0) && (year_ % 400 == 0))
			return true;
		else if ((year_ % 4 == 0) && (year_ % 100 == 0))
			return false;
		else if ((year_ % 4 == 0))
			return true;
		return false;
	}

	int year_;
	int month_;
	int day_;
};

void Date::SetDate(int year, int month, int date) {
	year_ = year;
	month_ = month;
	day_ = date;
}

void Date::AddDay(int inc)
{
	day_ += inc;

	while (true) {
		switch (month_) {
			// 31老
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day_ > 31) {
				day_ -= 31;
				AddMonth(1);
			}
			else
				return;
			break;

			// 30老
		case 4:
		case 6:
		case 9:
		case 11:
			if (day_ > 30) {
				day_ -= 30;
				AddMonth(1);
			}
			else
				return;
			break;

			// 28老 or 29老
		case 2:
			if (CheckLeapYear()) {
				if (day_ > 29) {
					day_ -= 29;
					AddMonth(1);
				}
				else
					return;
			}
			else {
				if (day_ > 28) {
					day_ -= 28;
					AddMonth(1);
				}
				else
					return;
			}
			break;

		}
	}
}

void Date::AddMonth(int inc) {
	month_ += inc;
	while (month_ > 12) {
		month_ -= 12;
		AddYear(1);
	}
}

void Date::ShowDate() {
	std::cout << year_ << "斥 " << month_ << "岿 " << day_ << "老\n";
}

int main()
{
	Animal animal{ 100,50 };
	animal.IncreaseFood(30);
	animal.ViewStat();

	Animal a;
	a.SetAnimal(200, 100);
	a.ViewStat();



	// ------------------------ 朝楼 拌魂扁 ----------------------
	std::cout << std::endl;

	Date date;
	date.SetDate(2022, 12, 28);

	while (true) {
		std::cout << "1. 老 歹窍扁\n";
		std::cout << "2. 岿 歹窍扁\n";
		std::cout << "3. 斥 歹窍扁\n";

		int command{};
		std::cin >> command;

		int num{};
		switch (command) {
		case 1:
			std::cout << "眠啊且 朝楼甫 涝仿 : ";
			std::cin >> num;
			date.AddDay(num);
			break;

		case 2:
			std::cout << "眠啊且 崔阑 涝仿 : ";
			std::cin >> num;
			date.AddMonth(num);

			break;

		case 3:
			std::cout << "眠啊且 斥档甫 涝仿 : ";
			std::cin >> num;
			date.AddYear(num);

			break;

		}


		date.ShowDate();
	}
}
#include <iostream>
#include <string>

enum BeverageSize {
	TALL,
	GRANDE,
	VENTI,
};

class Beverage {
protected:
	std::string description = "Unknown Beverage";
	BeverageSize size;
public:
	virtual std::string getDescription() {
		return description;
	};
	virtual double cost() = 0;

	void displayDescription() {
		std::cout << getDescription() << std::endl;
		std::cout << cost() << std::endl;
	}
	BeverageSize getSize() {
		return size;
	}
	void setSize(BeverageSize size) {
		this->size = size;
	}

	virtual ~Beverage() {}
};

class DarkRoast : public Beverage {
public:
	DarkRoast(BeverageSize size) {
		description = "DarkRoast";
		setSize(size);
	}
	double cost() {
		if (getSize() == TALL)
			return .89;
		else if (getSize() == GRANDE)
			return .99;
		else if (getSize() == VENTI)
			return 1.09;
	}
};

class Decaf : public Beverage {
public:
	Decaf(BeverageSize size) {
		description = "Decaf Coffee";
		setSize(size);
	}
	double cost() {
		if (getSize() == TALL)
			return .95;
		else if (getSize() == GRANDE)
			return 1.05;
		else if (getSize() == VENTI)
			return 1.15;
	}
};

class Espresso : public Beverage {
public:
	Espresso(BeverageSize size) {
		description = "Espresso";
		setSize(size);
	}
	double cost() {
		if (getSize() == TALL)
			return 1.89;
		else if (getSize() == GRANDE)
			return 1.99;
		else if (getSize() == VENTI)
			return 2.09;
	}
};

class HouseBlend : public Beverage {
public:
	HouseBlend(BeverageSize size) {
		description = "House Blend Coffee";
		setSize(size);
	}
	double cost() {
		if (getSize() == TALL)
			return .79;
		else if (getSize() == GRANDE)
			return .89;
		else if (getSize() == VENTI)
			return .99;
	}
};


class CondimentDecorator : public Beverage {
protected:
	Beverage* beverage;
public:
	CondimentDecorator(Beverage* beverage) {
		this->beverage = beverage;
	}
	~CondimentDecorator()
	{
		delete beverage;
	}
};

class Milk : public CondimentDecorator {
public:
	Milk(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() {
		return beverage->getDescription() + ", Milk";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + .05;
		else if (getSize() == GRANDE)
			return beverage->cost() + .10;
		else if (getSize() == VENTI)
			return beverage->cost() + .15;
	}
};

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() {
		return beverage->getDescription() + ", Mocha";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + .15;
		else if (getSize() == GRANDE)
			return beverage->cost() + .20;
		else if (getSize() == VENTI)
			return beverage->cost() + .25;
	}
};

class Soy : public CondimentDecorator {
public:
	Soy(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() {
		return beverage->getDescription() + ", Soy";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + .10;
		else if (getSize() == GRANDE)
			return beverage->cost() + .15;
		else if (getSize() == VENTI)
			return beverage->cost() + .20;
	}
};

class Whip : public CondimentDecorator {
public:
	Whip(Beverage* beverage) : CondimentDecorator(beverage) {}
	std::string getDescription() {
		return beverage->getDescription() + ", Whip";
	}
	double cost() {
		if (getSize() == TALL)
			return beverage->cost() + .05;
		else if (getSize() == GRANDE)
			return beverage->cost() + .10;
		else if (getSize() == VENTI)
			return beverage->cost() + .15;
	}
};


int main() {
	Beverage* bever1 = new DarkRoast(TALL);
	bever1 = new Milk(bever1);
	bever1 = new Mocha(bever1);
	bever1 = new Milk(bever1);
	bever1->displayDescription();

	Beverage* bever2 = new Espresso(GRANDE);
	bever2 = new Milk(bever2);
	bever2 = new Milk(bever2);
	bever2 = new Milk(bever2);
	bever2->displayDescription();

	Beverage* bever3 = new HouseBlend(VENTI);
	bever3 = new Whip(bever3);
	bever3 = new Milk(bever3);
	bever3 = new Soy(bever3);
	bever3 = new Mocha(bever3);
	bever3->displayDescription();

	return 0;
}
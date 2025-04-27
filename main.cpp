#include <iostream>
#include <string>
#include <vector>
#include <memory>

class DrinkingStrategy
{
public:
    virtual ~DrinkingStrategy() = default;
    virtual void Drink() const = 0;
};

class InSipsDrinkingStrategy : public DrinkingStrategy
{
public:
    void Drink() const override
    {
        std::cout << "drinking in small sips." << std::endl;
    }
};

class UseStrawDrinkingStrategy : public DrinkingStrategy
{
public:
    void Drink() const override
    {
        std::cout << "drinking through a straw." << std::endl;
    }
};

class UseSpoonDrinkingStrategy : public DrinkingStrategy
{
public:
    void Drink() const override
    {
        std::cout << "drinking with a spoon." << std::endl;
    }
};

class Tea
{
protected:
    std::string name;
    std::unique_ptr<DrinkingStrategy> drinkingStrategy;

public:
    Tea(const std::string& name, std::unique_ptr<DrinkingStrategy> strategy)
        : name(name), drinkingStrategy(std::move(strategy)) {}

    void Drink() const
    {
        BrewTea();
        PourTea();
        drinkingStrategy->Drink();
        EnjoyTea();
    }

    virtual void BrewTea() const
    {
        std::cout << "Brewing " << name << "..." << std::endl;
    }

    virtual void PourTea() const
    {
        std::cout << "Pouring " << name << "..." << std::endl;
    }

    virtual void EnjoyTea() const
    {
        std::cout << "Enjoy your " << name << "!" << std::endl;
    }
};

class BlackTea : public Tea
{
public:
    BlackTea(std::unique_ptr<DrinkingStrategy> strategy)
        : Tea("Black tea", std::move(strategy)) {}

    void BrewTea() const override
    {
        std::cout << "Brewing black tea..." << std::endl;
    }

    void PourTea() const override
    {
        std::cout << "Pouring black tea..." << std::endl;
    }
};

class GreenTea : public Tea
{
public:
    GreenTea(std::unique_ptr<DrinkingStrategy> strategy)
        : Tea("Green tea", std::move(strategy)) {}

    void BrewTea() const override
    {
        std::cout << "Brewing green tea..." << std::endl;
    }

    void PourTea() const override {
        std::cout << "Pouring green tea..." << std::endl;
    }
};

class HibiscusTea : public Tea
{
public:
    HibiscusTea(std::unique_ptr<DrinkingStrategy> strategy)
        : Tea("Hibiscus tea", std::move(strategy)) {}

    void BrewTea() const override
    {
        std::cout << "Brewing hibiscus tea..." << std::endl;
    }

    void PourTea() const override
    {
        std::cout << "Pouring hibiscus tea..." << std::endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<Tea>> teas;
    teas.push_back(std::make_unique<BlackTea>(std::make_unique<InSipsDrinkingStrategy>()));
    teas.push_back(std::make_unique<GreenTea>(std::make_unique<UseStrawDrinkingStrategy>()));
    teas.push_back(std::make_unique<HibiscusTea>(std::make_unique<UseSpoonDrinkingStrategy>()));

    for (const auto& tea : teas)
    {
        tea->Drink();
    }

    return 0;
}

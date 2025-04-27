#include <iostream>
#include <string>
#include <vector>

enum class The_drinking_rule
{
    in_sips,
    use_straw,
    use_spoon
};

class Tea
{
protected:
    std::string name;
    The_drinking_rule drinkingRule;

public:
    Tea(const std::string& name, The_drinking_rule rule)
        : name(name), drinkingRule(rule) {}

    void Drink() const
    {
        BrewTea();
        PourTea();
        switch (drinkingRule)
        {
            case The_drinking_rule::in_sips:
                std::cout << "drinking in small sips." << std::endl;
                break;
            case The_drinking_rule::use_straw:
                std::cout << "drinking through a straw." << std::endl;
                break;
            case The_drinking_rule::use_spoon:
                std::cout << "drinking with a spoon." << std::endl;
                break;
        }
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
        std::cout << "Enjoy your " << name << " tea!" << std::endl;
    }
};

class BlackTea : public Tea
{
public:
    BlackTea(The_drinking_rule rule)
        : Tea("Black tea", rule) {}

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
    GreenTea(The_drinking_rule rule)
        : Tea("Green tea", rule) {}

    void BrewTea() const override
    {
        std::cout << "Brewing green tea..." << std::endl;
    }

    void PourTea() const override
    {
        std::cout << "Pouring green tea..." << std::endl;
    }
};

class HibiscusTea : public Tea
{
public:
    HibiscusTea(The_drinking_rule rule)
        : Tea("Hibiscus tea", rule) {}

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
    std::vector<Tea*> teas;
    teas.push_back(new BlackTea(The_drinking_rule::in_sips));
    teas.push_back(new GreenTea(The_drinking_rule::use_straw));
    teas.push_back(new HibiscusTea(The_drinking_rule::use_spoon));

    for (const auto& tea : teas)
    {
        tea->Drink();
    }

    for (auto& tea : teas)
    {
        delete tea;
    }

    return 0;
}

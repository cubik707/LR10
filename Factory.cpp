#include "Factory.h"

unique_ptr<Product> ComputerFactory::create() const
{
    return make_unique<Computer>();
}

unique_ptr<Product> ComputerFactory::create(const string& name, double price) const
{
    return make_unique<Computer>(name, price);
}

unique_ptr<Product> LaptopFactory::create() const
{
    return make_unique<Laptop>();
}

unique_ptr<Product> LaptopFactory::create(const string& name, double price) const
{
    return make_unique<Laptop>(name, price);
}

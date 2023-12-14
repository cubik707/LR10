#include "Factory.h"

unique_ptr<Product> ComputerFactory::create() const
{
    return make_unique<Computer>();
}

unique_ptr<Product> LaptopFactory::create() const
{
    return make_unique<Laptop>();
}

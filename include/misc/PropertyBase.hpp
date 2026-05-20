/**
 * KnoKan
 * Graph Library.
 * Property Base Class (virtual)
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */

#ifndef _KNOKAN_PROPERTYBASE_HPP
#define _KNOKAN_PROPERTYBASE_HPP

namespace KnoKan
{
namespace Property {

class Base
{
  public:
    virtual ~Base()           = default;
    virtual double get_weight() const = 0;
};
namespace Predefined
{
    
class SimpleWeight : public KnoKan::Property::Base
{
  public:
    SimpleWeight() : weight(0)
    {
    }
    SimpleWeight(double weight) : weight(weight)
    {
    }
    double weight;

    double get_weight() const override
    {
        return weight;
    }
};

class UniWeight : public KnoKan::Property::Base
{
  public:
    double get_weight() const override
    {
        return 1.0;
    }
};

class NoWeight : public KnoKan::Property::Base
{
  public:
    double get_weight() const override
    {
        return 0.0;
    }
};
}
}

} // namespace KnoKan

#endif // _KNOKAN_PROPERTYBASE_HPP
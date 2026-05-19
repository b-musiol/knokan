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

class PropertyBase
{
  public:
    virtual ~PropertyBase()           = default;
    virtual double get_weight() const = 0;
};

class UniWeightProperty : public KnoKan::PropertyBase
{
    double get_weight() const override
    {
        return 1.0;
    }
};

} // namespace KnoKan

#endif // _KNOKAN_PROPERTYBASE_HPP
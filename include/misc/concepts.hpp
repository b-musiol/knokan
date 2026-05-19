/**
 * KnoKan
 * Graph Library.
 * concepts
 *
 * Author: Bartek Musiol (bmusiol@proton.me)
 *
 * See LICENSE
 */

#ifndef _KNOKAN_CONCEPTS_HPP
#define _KNOKAN_CONCEPTS_HPP

#include <concepts>
#include <string>
#include <type_traits>

namespace KnoKan
{

template <typename T>
concept StringLike = std::same_as<std::remove_cvref_t<T>, std::string> ||
                     std::same_as<std::remove_cvref_t<T>, std::string_view> ||
                     std::convertible_to<T, const char *>;

template <typename T>
concept IntegralOrString = std::integral<T> || StringLike<T>;

} // namespace KnoKan

#endif // _KNOKAN_CONCEPTS_HPP
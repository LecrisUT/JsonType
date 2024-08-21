#pragma once

#include <list>
#include <map>
#include <string>
#include <variant>

namespace JsonType {
// Basic json data type
class object;
class list;
using null = std::nullptr_t;
using json_type =
    std::variant<bool, int, double, null, std::string, list, object>;

// Other aliases
using vector = list;
using dict = object;
using map = object;

// Define the container types
class list : public std::list<json_type> {};
class object : public std::map<std::string, json_type> {};

}  // namespace JsonType

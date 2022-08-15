#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <utility>

std::string json_entry(std::pair<std::string, std::string> entry)
{
    return "\"" + entry.first + "\": \"" + entry.second + "\"";
}

std::string json_entry(std::pair<std::string, double> entry)
{
    std::stringstream ss;
    ss << std::setprecision(2) << std::fixed << std::showpoint << entry.second;

    return "\"" + entry.first + "\": \"" + ss.str() + "\"";
}

template<typename T>
std::string parse_entry(T t)
{
    return json_entry(t);
}

template<typename FIRST, typename... REST>
std::string parse_entry(FIRST first, REST... rest)
{
    return json_entry(first) + ", " + parse_entry(rest...);
}

template<typename... ENTRIES>
std::string make_json(ENTRIES... entries)
{
    return "{ " + parse_entry(entries...) + " }";
}
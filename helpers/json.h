#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <utility>

#include "utils.h"

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

std::pair<std::string, std::string> entry_to_pair(std::string entry)
{

    remove_char(entry, '\"');

    std::string delimiter = ":";
    int start = 0;
    int end = entry.find(delimiter);

    auto key = entry.substr(start, end - start);
    start = end + delimiter.size();
    end = entry.find(delimiter, start);

    auto value = entry.substr(start, end - start);

    return {trim(key), trim(value)};
}

std::map<std::string, std::string> simple_str_json_to_map(std::string str_json)
{
    std::map<std::string, std::string> output{};

    remove_char(str_json, '{');
    remove_char(str_json, '}');
    remove_char(str_json, '\n');

    std::string delimiter = ",";

    int start = 0;
    int end = str_json.find(delimiter);

    while (end != -1)
    {
        output.insert(entry_to_pair(str_json.substr(start, end - start)));

        start = end + delimiter.size();
        end = str_json.find(delimiter, start);
    }

    output.insert(entry_to_pair(str_json.substr(start, end - start)));

    return output;
}
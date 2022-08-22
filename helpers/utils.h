#pragma once

#include <bits/stdc++.h>
#include <string>

void wait_for_initialization(std::function<bool(void)> checker, uint8_t max_number_of_retries = 0, std::function<void(void)> failure_action = nullptr)
{
    uint8_t current_retry = 0;
    while (checker())
    {
        delay(500);

        if (max_number_of_retries == 0)
        {
            continue;
        }

        if (current_retry++ > max_number_of_retries)
        {
            if (failure_action)
            {
                failure_action();
            }
            break;
        }
    }
}

void remove_char(std::string & input, char to_be_removed)
{
    input.erase(remove(input.begin(), input.end(), to_be_removed), input.end());
}

std::string & ltrim(std::string & s)
{
    auto it = std::find_if(s.begin(), s.end(), [](char c) { return !std::isspace<char>(c, std::locale::classic()); });
    s.erase(s.begin(), it);
    return s;
}

std::string & rtrim(std::string & s)
{
    auto it = std::find_if(s.rbegin(), s.rend(), [](char c) { return !std::isspace<char>(c, std::locale::classic()); });
    s.erase(it.base(), s.end());
    return s;
}

std::string & trim(std::string & s)
{
    return ltrim(rtrim(s));
}
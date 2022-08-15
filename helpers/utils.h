#pragma once

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
};

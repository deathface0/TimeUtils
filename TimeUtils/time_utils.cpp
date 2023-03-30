#include "time_utils.h"

time_t TimeUtils::getUnixTimestamp()
{
    const auto p1 = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(
        p1.time_since_epoch()).count();
}

std::string TimeUtils::currentDateTime(std::string params) //"%Y-%m-%d %H:%M:%S" (24h)  /  "%Y-%m-%d %I:%M:%S %p" (12h)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm time_info;
#ifdef _WIN32
    localtime_s(&time_info, &now_c);
#else
    localtime_r(&timestamp, &time_info);
#endif
    std::stringstream ss;
    ss << std::put_time(&time_info, params.c_str());
    return ss.str();
}

time_t TimeUtils::TimeElapsed(time_t start, time_t end)
{
    return end - start;
}

std::string TimeUtils::timestampToDateTime(time_t timestamp, std::string params)
{
    std::tm time_info;
#ifdef _WIN32
    localtime_s(&time_info, &timestamp);
#else
    localtime_r(&timestamp, &time_info);
#endif
    std::stringstream ss;
    ss << std::put_time(&time_info, params.c_str());
    return ss.str();
}

Time TimeUtils::secondsToHMS(size_t seconds)
{
    Time time;

    time.hours = seconds / 3600;
    time.minutes = (seconds % 3600) / 60;
    time.seconds = seconds % 60;

    return time;
}

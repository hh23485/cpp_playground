//
// Created by minghu on 2019/8/21.
//

#ifndef CPP_PRIMER5_STATIC_TEST_H
#define CPP_PRIMER5_STATIC_TEST_H

#include <map>
#include <vector>
#include <string>
#include <chrono>

typedef __int64 UInt64;

namespace StaticTest {
    class ConfigTimer {
        static std::map<std::string, std::string> stageParentMap;
        static std::map<std::string, double> stageCostMap;
        static std::map<std::string, UInt64> stageCountMap;
        static std::vector<std::string> stageOrderList;

    public:

        static void RecordStageTimerCost(std::string &&stageName, std::chrono::system_clock::time_point begin,
                                         std::chrono::system_clock::time_point end, std::string &&parentName) {
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            auto cost = double(duration.count());
            auto result = stageCountMap.find(stageName);
            if (result == stageCountMap.end()) {
                // first time
                stageCountMap.insert_or_assign(stageName, 1);
                stageCostMap.insert_or_assign(stageName, cost);
                if (parentName.length() != 0) {
                    stageParentMap.insert_or_assign(stageName, parentName);
                }
                stageOrderList.push_back(stageName);
            } else {
                stageCountMap.insert_or_assign(stageName, result->second + 1);
                stageCostMap.insert_or_assign(stageName, stageCostMap.find(stageName)->second + cost);
            }
            // std::string msg = parentName + ">" + stageName + " cost: " + std::to_string(cost) + " microseconds.";
            // Log(LogID_Answers, LogLevel_Error, "init timer", msg.c_str() );
        };
    };
}

#endif //CPP_PRIMER5_STATIC_TEST_H

/*
 * twoSum.h
 *
 *  Created on: 2017Äê1ÔÂ6ÈÕ
 *      Author: lzd
 */

#ifndef SUM_TWOSUM_H_
#define SUM_TWOSUM_H_

#include<vector>
#include<tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class twoSum {
public:
    vector<int> f(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numToFind = target - nums[i];
            if (hash.find(numToFind) != hash.end()) {
                result.push_back(hash[numToFind]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

#endif /* SUM_TWOSUM_H_ */

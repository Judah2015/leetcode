/*
 * threeSum.h
 *
 *  Created on: 2017��1��6��
 *      Author: lzd
 */

#ifndef SUM_THREESUM_H_
#define SUM_THREESUM_H_

#include<vector>
#include<algorithm>

using namespace std;

class ThreeSum {
public:
    vector<vector<int>> f(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i + 1;
            int rear = nums.size() - 1;
            while (front < rear) {
                int sum = nums[front] + nums[rear];
                if (sum < target) {
                    front++; //�����ظ�����ʹ����ظ������Բ��ô���
                }
                else if (sum > target) {
                    rear--;
                }
                else {
                    vector<int> subRes(3, 0);
                    subRes[0] = nums[i];
                    subRes[1] = nums[front];
                    subRes[2] = nums[rear];
                    res.push_back(subRes);
                    while (front < rear && nums[front] == subRes[1]) front++;
                    //ע��1.front < rear;2.һ����ִ��һ��ѭ��
                    while (front < rear && nums[rear] == subRes[2]) rear--;
                }
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};

#endif /* SUM_THREESUM_H_ */

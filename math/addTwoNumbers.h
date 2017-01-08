/*
 * addTwoNumbers.h
 *
 *  Created on: 2017年1月6日
 *      Author: lzd
 */

#ifndef ADDTWONUMBERS_H_
#define ADDTWONUMBERS_H_

#include <cstddef>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

class addTwoNumbers {
public:
	//这是自己的
	/*ListNode *f(ListNode *l1, ListNode *l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *res = new ListNode(0);
		ListNode *p3 = res;
		bool carry = false;
		bool isFirstLoop = true;
		while (p1 != NULL && p2 != NULL) {
			if (!isFirstLoop) {
				ListNode *p4 = new ListNode(0);
				p3->next = p4;
				p3 = p4;
			}
			else {
				isFirstLoop = false;
			}
			int sum = p1->val + p2->val;
			if (carry) sum++;
			p3->val = (sum >= 10) ? (sum - 10) : sum;
			carry = (sum >= 10) ? true : false;
			p1 = p1->next;
			p2 = p2->next;
 		}
		if (p1 == NULL && p2 == NULL) { //这个要第一个判断
			if (carry) {
				ListNode *p4 = new ListNode(0);
				p3->next = p4;
				p3 = p4;
				p3->val = 1;
				carry = false;
			}
		}
		else if (p1 != NULL) {
			while (p1 != NULL) { //这里忽略了
				ListNode *p4 = new ListNode(0);
				p3->next = p4;
				p3 = p4;
				p3->val = p1->val;
				if (carry) {
					p3->val++;
					if (p3->val == 10) {
						p3->val = 0; //忽略这里1 + 99就得出0->10了
						carry = true;
					}
					else {
						carry = false;
					}
				}
				p1 = p1 ->next;
			}
		}
		else {
			while (p2 != NULL) {
				ListNode *p4 = new ListNode(0);
				p3->next = p4;
				p3 = p4;
				p3->val = p2->val;
				if (carry) {
					p3->val++;
					if (p3->val == 10) {
						p3->val = 0;
						carry = true;
					}
					else {
						carry = false;
					}
				}
				p2 = p2->next;
			}
		}
		if (carry) { //处理类似1 + 99的
			ListNode *p4 = new ListNode(0);
			p3->next = p4;
			p3 = p4;
			p3->val = 1;
		}
		return res;
	}*/

	//这个代码超短
	ListNode *f(ListNode *l1, ListNode *l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *res = new ListNode(0);
		ListNode *p3 = res;
		int sum = 0;
		while (p1 != NULL || p2 != NULL) { //这里用“或”
			sum /= 10; //进位
			if (p1 != NULL) { //这样一来位数不同的就不用分开讨论了
				sum += p1->val;
				p1 = p1->next;
			}
			if (p2 != NULL) {
				sum += p2->val;
				p2 = p2->next;
			}
			p3->next = new ListNode(sum % 10); //不用新建指针
			p3 = p3->next;
		}
		if (sum >= 10) {
			p3->next = new ListNode(1);
		}
		return res->next; //这样就省了不少讨论
	}
};

#endif /* ADDTWONUMBERS_H_ */

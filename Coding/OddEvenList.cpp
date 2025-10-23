#include <cstddef>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildLinkList(std::vector<int> nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* lastNode = nullptr;
    ListNode* headNode = nullptr;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        auto currentNode = new ListNode(num);
        if (lastNode != nullptr) {
            lastNode->next = currentNode;
        } else {
            headNode = currentNode;
        }
        lastNode = currentNode;
    }
    return headNode;
}

void logLinkList(ListNode* head) {
    std::string log = "[";
    while (head != nullptr) {
        log += std::to_string(head->val);
        if (head->next != nullptr) {
            log += ",";
        }
        head = head->next;
    }
    log += "]";
    printf("logLinkList: %s\n", log.c_str());
}

class OddEvenList {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* ptr = head;
        ListNode* evenHead = nullptr;
        while (ptr->next != nullptr) {
            ListNode* tmpNext = ptr->next;
            if (evenHead == nullptr) {
                evenHead = tmpNext;
            }
            ptr->next = tmpNext->next;
            if (ptr->next == nullptr) {
                break;
            }
            tmpNext->next = ptr->next->next;
            ptr = ptr->next;
        }
        ptr->next = evenHead;
        return head;
    }
};

int main() {
    std::vector<int> nums = {1,2,3,4,5,6};
    ListNode* head = buildLinkList(nums);
    auto solution = std::unique_ptr<OddEvenList>();
    auto answer = solution->oddEvenList(head);
    logLinkList(answer);
    return 0;
}
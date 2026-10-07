// Define the node structure outside the class
struct NODE {
    int data;
    NODE* next;
};

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize <= 1) return false;

        int capacity = 2 * numsSize;
        NODE** hash_table = (NODE**)calloc(capacity, sizeof(NODE*));

        for (int i = 0; i < numsSize; i++) {
            unsigned int bucket = (unsigned int)nums[i] % capacity;
            NODE* cur = hash_table[bucket];

            while (cur) {
                if (cur->data == nums[i]) {
                    free(hash_table);
                    return true;
                }
                cur = cur->next;
            }

            NODE* new_node = (NODE*)malloc(sizeof(NODE));
            new_node->data = nums[i];
            new_node->next = hash_table[bucket];
            hash_table[bucket] = new_node;
        }

        free(hash_table);
        return false;
    }
};
// brute force approach
struct Node {
    int key, val, ct;
    Node* next;
    Node* back;

    Node(int k1, int v1) {
        key = k1;
        val = v1;
        ct = 1;
        next = nullptr;
        back = nullptr;
    }
};

void deletion(Node* temp) {
    Node* nextNode = temp->next;
    Node* prevNode = temp->back;

    prevNode->next = nextNode;
    nextNode->back = prevNode;
}

void insertion(Node* temp, Node* head) {
    Node* nextNode = head->next;
    head->next = temp;
    temp->back = head;
    temp->next = nextNode;
    nextNode->back = temp;
}

void deletionOfTail(Node* head, Node* tail, map<int, Node*>& mpp) {
    Node* minFreqNode = tail->back;
    Node* mover = tail->back;
    while (mover != head) {
        if ((minFreqNode->ct) > (mover->ct)) {
            minFreqNode = mover;
        }
        mover = mover->back;
    }

    Node* nextNode = minFreqNode->next;
    Node* prevNode = minFreqNode->back;

    nextNode->back = prevNode;
    prevNode->next = nextNode;
    int key = minFreqNode->key;
    mpp.erase(key);
    delete minFreqNode;
}

class LFUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    map<int, Node*> mpp;
    int sz;
    LFUCache(int capacity) {
        sz = capacity;

        head->next = tail;
        tail->back = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* temp = mpp[key];
        temp->ct += 1;

        deletion(temp);
        insertion(temp, head);

        return temp->val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            temp->ct++;
            temp->val = value;
            deletion(temp);
            insertion(temp, head);
        } else {
            if (mpp.size() == sz && sz!=0) {
                deletionOfTail(head, tail,mpp); // deletion of the LRU and delete from mpp also.
            }
            Node* temp = new Node(key, value);
            insertion(temp, head); // insertion at head as this is MRU now
            mpp[key] = temp;
        }
    }
}
;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
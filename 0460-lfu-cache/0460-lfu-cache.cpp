// optimal approach
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

struct List {
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->back = head;
        size = 0;
    }

    void deletionOfNode(Node* temp) {
        Node* prevNode = temp->back;
        Node* nextNode = temp->next;

        prevNode->next = nextNode;
        nextNode->back = prevNode;
        size--;
    }

    void addFront(Node* temp) {
        Node* nextNode = head->next;

        head->next = temp;
        temp->back = head;
        temp->next = nextNode;
        nextNode->back = temp;
        size++;
    }
};

class LFUCache {
public:
    map<int, Node*> mpp;
    map<int, List*> freqMap; // will store ct as key and lists as value
    int sz;
    int minFreq;
    LFUCache(int capacity) {
        sz = capacity;
        minFreq = 0;
    }

    void updateFreqMap(Node* temp) {
        mpp.erase(temp->key);
        freqMap[temp->ct]->deletionOfNode(temp);

        if ((temp->ct) == minFreq && freqMap[temp->ct]->size == 0) {
            minFreq++;
            ;
        }

        List* nextFreqList = new List();
        if (freqMap.find(temp->ct + 1) != freqMap.end()) {
            nextFreqList = freqMap[(temp->ct) + 1];
        }
        temp->ct += 1;
        nextFreqList->addFront(
            temp); // as this node will be the MRU in its new list
        freqMap[temp->ct] = nextFreqList; // updating that list in freqMap
        mpp[temp->key] = temp;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            int val = temp->val;
            updateFreqMap(temp);
            return val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (sz == 0) {
            return;
        }
        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            temp->val = value;
            updateFreqMap(temp);
        } else {
            if (mpp.size() == sz) {
                List* list = freqMap[minFreq];
                Node* node = list->tail->back;
                int key = node->key;
                mpp.erase(key);
                list->deletionOfNode(node);
            }
            minFreq = 1; // as new value is added
            List* freqList = new List();
            if (freqMap.find(minFreq) != freqMap.end()) {
                freqList = freqMap[minFreq];
            }

            Node* node = new Node(key, value);
            freqList->addFront(node);
            mpp[key] = node;
            freqMap[minFreq] = freqList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
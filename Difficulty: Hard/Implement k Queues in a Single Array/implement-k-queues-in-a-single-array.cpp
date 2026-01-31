class kQueues {
    int n, k;
    vector<int> arr,front,rear,next;
    int freeSpot;

public:
    kQueues(int n, int k) : n(n), k(k), arr(n), front(k, -1), rear(k, -1), next(n) {
        for (int i = 0; i < n - 1; i++) next[i] = i + 1;
        next[n - 1] = -1;
        freeSpot = 0;
    }

    void enqueue(int x, int qi) {
        if (freeSpot == -1) return;
        int index = freeSpot;
        freeSpot = next[index];
        if (front[qi] == -1) front[qi] = index;
        else next[rear[qi]] = index;
        next[index] = -1;
        rear[qi] = index;
        arr[index] = x;
    }

    int dequeue(int qi) {
        if (front[qi] == -1) return -1;
        int index = front[qi];
        front[qi] = next[index];
        if (front[qi] == -1) rear[qi] = -1;
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }

    bool isEmpty(int qi) {
        return front[qi] == -1;
    }

    bool isFull() {
        return freeSpot == -1;
    }
};


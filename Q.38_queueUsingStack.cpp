#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> inputStack;
    stack<int> outputStack;

public:
    // Enqueue operation (push element into the queue)
    void enqueue(int x) {
        inputStack.push(x);
    }

    // Dequeue operation (pop and return the front element from the queue)
    int dequeue() {
        if (outputStack.empty()) {
            if (inputStack.empty()) {
                throw runtime_error("Queue is empty.");
            }

            // Transfer elements from the input stack to the output stack
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;

    queue.enqueue(4);

    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;

    return 0;
}

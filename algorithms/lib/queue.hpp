#pragma once
namespace DataStructures
{
    template <typename T>
    struct Node
    {
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
    };

    template <typename T>
    class Queue
    {
    private:
        Node<T>* front;
        Node<T>* rear;
        int size;

    public:
        // Constructor
        Queue() : front(nullptr), rear(nullptr), size(0) {}

        // Destructor - to prevent memory leaks
        ~Queue()
        {
            while (!isEmpty())
            {
                dequeue();
            }
        }

        bool isEmpty() const
        {
            return size == 0;
        }

        int getSize() const
        {
            return size;
        }

        void enqueue(T val)
        {
            Node<T>* newNode = new Node<T>(val);

            if (isEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        T dequeue()
        {
            if (isEmpty())
            {
                throw std::runtime_error("Queue is empty!");
            }

            Node<T>* popNode = front;
            T value = popNode->data;

            front = front->next;
            if (front == nullptr)
            {
                // If the queue is empty
                rear = nullptr;
            }

            delete popNode;

            size--;
            return value;
        }

        // To get the front element
        T peek() const
        {
            if (isEmpty())
            {
                throw std::runtime_error("Queue is empty!");
            }
            return front->data;
        }
    };

} // namespace DataStructures
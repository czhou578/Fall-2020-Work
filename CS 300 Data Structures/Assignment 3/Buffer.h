/*
  This is the template Buffer class that is used.
*/

#ifndef BUFFER
#define BUFFER

using namespace std;

template <class T>
class Buffer {
  private:
    T *data;
    int count;
    int front;
    int back;
    int bufferSize;

  public:

    Buffer(int size) { // initializes buffer
      bufferSize = size;
      front = 0;
      count = 0;
      back = bufferSize - 1;
      data = new T[bufferSize];
    }

    int getBufferSize() {
      return bufferSize;
    }

    bool isEmpty() {
      return count == 0;
    }

    bool isFull() {
      return back == bufferSize;
    }

    void dequeue() {
      if (!isEmpty()) {
        front = (front + 1) % bufferSize;
        count--;
      }
    }

    void enqueue(const T& t) {
      if (!isFull()) {
        back = (back + 1) % bufferSize;
        data[back] = t;
        count++;
      }

    }

    T qFront() {
      if (!isEmpty()) {
        return data[front];
      }
    }

    int getCount() {
      return count;
    }

};

#endif


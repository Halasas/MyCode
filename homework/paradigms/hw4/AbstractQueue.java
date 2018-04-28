package queue;
// s = size - count of relevant elements in array
// L = length - length of array
// a[i] - queue array  ∧  i = 0 .. L - 1
// h = head - first element in queue, t = tail - insertion point for next element in queue

public abstract class AbstractQueue implements Queue {

    public Object dequeue() {
        Object result = element();
        dequeueMod();
        if (size() == 0){
            clear();
        }
        return result;
    }

    // PRE: dequeue() was called
    protected abstract void dequeueMod();

    public abstract void enqueue(Object x);

    public boolean isEmpty() {
        return size() == 0;
    }

    public abstract int size();

    public Object[] toArray() {
        return getElements(size());
    }

    protected Object[] getElements(int capacity){
        Object[] newQueue = new Object[capacity];
        int tmp = size();
        for (int i = 0; i < tmp; i++) {
            newQueue[i] = dequeue();
            enqueue(newQueue[i]);
        }
        return newQueue;
    }
}
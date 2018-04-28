package queue;
// s = size - count of relevant elements in array
// L = length - length of array
// a[i] - queue array  ∧  i = 0 .. L - 1
// h = head - first element in queue, t = tail - insertion point for next element in queue

public class ArrayQueue extends AbstractQueue {
    private Object[] elements;
    private int tail;
    private int head;

    public ArrayQueue() {
        elements = new Object[16];
    }
    // POST: L' == 16,  t' == h' == s' == 0

    // PRE: capacity > 0
    public ArrayQueue(int capacity) {
        elements = new Object[capacity];
    }
    //POST: L' == capacity, t' == h' == s' == 0

    public void clear() {
        head = 0;
        tail = 0;
        elements = new Object[16];
    }
    // POST: h == t' == 0, L' == 16

    public int size() {
        if (tail >= head) {
            return tail - head;
        } else {
            return elements.length - head + tail;
        }
    }

    public void dequeueMod() {
        head = ++head % elements.length;
    }
    // POST: h' == (h + 1) mod L,
    // POST: s' = s - 1 >= 0

    public Object element() {
        return elements[head];
    }

    public void enqueue(Object x) {
        if (size() + 1 == elements.length) {
            // s == L - 1
            int tmp = size();
            elements = getElements(elements.length << 1);
            tail = tmp;
            head = 0;
        }
        // POST: L' >= L > s
        elements[tail] = x;
        tail = ++tail % elements.length;
    }
    // POST: ((t' == (t + 1) mod L')  ∧  (s' < L' == L))  ∨  ((L' == L * 2)  ∧  (s == L - 1 == t'))


    public ArrayQueue copy() {
        ArrayQueue c = new ArrayQueue(elements.length);
        c.head = head;
        c.tail = tail;
        System.arraycopy(elements, 0, c.elements, 0, elements.length);
        return c;
    }
}
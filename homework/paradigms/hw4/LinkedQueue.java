package queue;
// s = size - count of relevant elements in array
// L = length - length of array
// L == s
// a[i] - queue array  ∧  i = 0 .. L - 1
// h = head - first element in queue, t = tail - insertion point for next element in queue

public class LinkedQueue extends AbstractQueue {
    private Node head;
    private Node tail;
    private int size;

    private class Node {
        private Node next;
        private Object value;

        private Node(Node newNext, Object newValue) {
            next = newNext;
            value = newValue;
        }
    }

    public void clear() {
        size = 0;
    }

    protected void dequeueMod() {
        head = head.next;
        size--;
    }
    // POST: h' = h + 1
    //       s' = s - 1 >= 0

    public Object element() {
        return head.value;
    }

    public int size(){
        return size;
    }

    public void enqueue(Object x) {
        if (size == 0) {
            head = tail = new Node(null, x);
            // s' == 0, h' == x
        } else {
            tail.next = new Node(null, x);
            tail = tail.next;
            // s' > 0, t' = t + 1 , h' == h
        }
        size++;
    }
    // POST: (s' == s + 1)  ∧  (((t' == (t + 1) mod L')  ∧  (s' < L' == L))  ∨  ((L' == L * 2)  ∧  (s == L - 1 == t')))


    public LinkedQueue copy() {
        LinkedQueue result = new LinkedQueue();
        Node tmp = head;
        for (int i = 0; i < size; i++) {
            result.enqueue(tmp.value);
            tmp = tmp.next;
        }
        return result;
    }
}
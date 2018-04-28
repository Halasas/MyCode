package queue;
// s = size - count of relevant elements in array
// L = length - length of array
// a[i] - queue array  ∧  i = 0 .. L - 1
// h = head - first element in queue, t = tail - insertion point for next element in queue

// INV:  L > h >= 0  ∧  L > t >= 0  ∧  s >= 0
public interface Queue {

    // PRE: true
    void clear();
    // POST: s' == 0

    // PRE: (s > 0)  ∧  (h != null)
    Object dequeue();
    // POST: ℝ == h
    //       s' == s - 1 >= 0

    // PRE: (s > 0)  ∧  (h != null)
    Object element();
    // POST: ℝ == h
    //       a'[i] == a[i] for i = 0 .. L - 1
    //       s' == s,  h' == h,  t' == t, L' == L

    // PRE: x != null
    void enqueue(Object x);
    // POST: s' == s + 1, t' == t + 1
    //       a[t] == x

    // PRE: true
    boolean isEmpty();
    // POST: ℝ == (s == 0)
    //       a'[i] == a[i] for i = 0 .. L - 1
    //       s' == s, h' == h, t' == t, L' == L

    // PRE: true
    int size();
    // POST: ℝ == s
    //       a'[i] == a[i] for i = 0 .. L - 1
    //       s' == s, L' == L, h' == h, t' == t

    // PRE: true
    Object[] toArray();
    // POST: ℝ == c[i] for i = 0 .. s, c[] - new queue with elements a[] in order from head to tail
    //       a'[i] == a[i] for i = 0 .. L - 1
    //       s' == s, L' == L, t' == t, h' == h


    // PRE: true
    AbstractQueue copy();
    // POST: ℝ == c[i] == a'[i] == a[i]  for i = 0 .. L - 1
    //       s' == s, L' == L, t' == t, h' == h
}
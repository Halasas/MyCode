package array_queue;

//Q - exemplar of array_queue.ArrayQueueADT
//L - length of Q array
//S - size of Q.array_queue
//H - head - first element in Q
//T - tail - last element in Q
//R - result
//
//INV: L > H ∧ H >= 0
//      L > T ∧ T >= -1
//      S >= 0 ∧ L >= 32 ∧ L >= S
//
public class ArrayQueueADT {
    private static Object[] queue = new Object[32];
    private static int head = 0;
    private static int tail = -1;

    public ArrayQueueADT() {
        queue = new Object[16];
        tail = -1;
        head = 0;
    }
    // POST: L' == 16,  T' == -1,  H' == 0, S' == 0

    // PRE: x > 0
    public ArrayQueueADT(int x) {
        queue = new Object[x];
        tail = -1;
        head = 0;
    }
    // POST: L' == x, T' == -1, H' == 0, S' == 0

    // PRE: x != NULL
    //      Q != NULL
    public static void enqueue(ArrayQueueADT Q, Object x) { //add new element to Q.tail
        if (size(Q) == Q.queue.length)
            increaseCapacity(Q, size(Q));
        // Q.L' > Q.S
        Q.tail = ++Q.tail % Q.queue.length;
        Q.queue[Q.tail] = x;
    }
    // POST: S' == S + 1 ∧ T' == (T + 1) % L ∧ Q.array_queue[T] == x

    // PRE: S > 0
    //      Q != NULL
    public static Object element(ArrayQueueADT Q) { //return first element in array_queue
        return queue[Q.head];
    }
    // POST: R = Q.array_queue[H]

    // INV: array_queue'[i] == for all i except i == H
    // PRE: Q != null ∧ (S > 0)  ∧  (array_queue[H] != null)
    public static Object dequeue(ArrayQueueADT Q) { //delete and return firs element
        Object x = queue[Q.head];
        //S' == 1
        if (size(Q) == 1)
            clear(Q);
        else {
            Q.head = ++Q.head % Q.queue.length;
        }
        return x;
    }
    // POST: (S' > 0 ∧ H' == (H + 1) % L  ∧ T' == T)  ∨  (S' == 0 ∧ H' == 0 ∧ T' == -1)
    // R = Q.array_queue[H]

    //PRE:     Q != NULL
    public static Integer size(ArrayQueueADT Q) { //return size of array_queue
        if (Q.head <= Q.tail)
            return Q.tail - Q.head + 1;
        else if (Q.tail != -1)
            return Q.queue.length - Q.head + Q.tail + 1;
        else
            return 0;
    }
    // POST: R == S

    //      Q != NULL
    public static boolean isEmpty(ArrayQueueADT Q) { // (is array_queue empty?)
        return (size(Q) == 0);
    }
    // POST: (R == true ∧ S == 0) ∨ (R == false ∧ S > 0)

    // PRE: x >= L
    //      Q != NULL
    private static void increaseCapacity(ArrayQueueADT Q, int x) { // increase capacity of array_queue
        Object[] increasedQueue = new Object[2 * x];
        System.arraycopy(queue, Q.head, increasedQueue, 0, Q.queue.length - Q.head);

        //T' <= H' - 1  ∧  H > 0
        if (Q.head != 0) {
            System.arraycopy(queue, 0, increasedQueue, Q.queue.length - Q.head, Q.tail + 1);
        }
        // increasedQueue.length = L * 2
        // increasedQueue[j] == Q.array_queue[i] : j = 0 .. S - 1,  i = (L - H) .. (L - H + T + 1))

        Q.tail = Q.queue.length - 1;
        Q.head = 0;
        queue = increasedQueue;
    }
    // POST: L' == L * 2 ∧ S' == S ∧ array_queue' == array_queue ∧ T' = S - 1 ∧ H' = 0

    //PRE:   Q != NULL
    public static void clear(ArrayQueueADT Q) {// delete all elements from array_queue
        Q.queue = new Object[32];
        Q.head = 0;
        Q.tail = -1;
    }
    // POST: S' == 0 ∧ H' == 0 ∧ T' == -1 ∧ L' == 32

    // PRE: S > 0 ∧ Q.array_queue != null
    public static Object[] toArray(ArrayQueueADT Q) {
        Object[] array = new Object[size(Q)];
        for (int i = 0; i < size(Q); i++) {
            array[i] = Q.queue[(i + Q.head) % Q.queue.length];
        }
        return array;
    }
    // POST: R == getArray[i]
}

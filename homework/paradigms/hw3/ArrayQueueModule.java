package array_queue;
//L - length of array
//S - size of array_queue
//H - head - first element
//T - tail - last element
//R - result
//
// INV: L > H ∧ H >= 0
//      L > T ∧ T >= -1
//      S >= 0 ∧ L >= 32 ∧ L >= S
public class ArrayQueueModule {
    private static Object[] queue = new Object[32];
    private static int head = 0;
    private static int tail = -1;

    // PRE: x != NULL
    public static void enqueue(Object x) { //add new element to tail
        if(size() == queue.length)
            increaseCapacity(size());
        // L' > S
        tail = ++tail % queue.length;
        queue[tail] = x;
    }
    // POST: S' == S + 1 ∧ T' == (T + 1) % L ∧
    //       array_queue[T] == x ∧ for all i: array_queue[i]' = array_queue[i]

    // PRE: S > 0
    public static Object element() { //return first element in array_queue
        return queue[head];
    }
    // POST: R = array_queue[H]

    public static Object dequeue() { //delete and return firs element
        Object x = queue[head];
        //S' == 0
        if(size() == 1)
            clear();
        //S' > 0
        else {
            head = ++head % queue.length;
        }
        return x;
    }
    // POST: ((S' > 0 ∧ H' == (H + 1) % L  ∧ T' == T) ∨
    //       (S' == 0 ∧ H' == 0 ∧ T' == -1)) ∧
    //       for all i except i == H: array_queue[i]' = array_queue[i]
    // R = array_queue[H]

    public static Integer size() { //return size of array_queue
        if (head <= tail)
            return tail - head + 1;
        else if (tail != -1)
            return queue.length - head + tail + 1;
        else
            return 0;
    }
    // POST: R == S

    public static boolean isEmpty() { // (is array_queue empty?)
        return (size() == 0);
    }
    // POST: (R == true ∧ S == 0) ∨
    //       (R == false ∧ S > 0)

    // PRE: x >= L
    private static void increaseCapacity(int x) { // increase capacity of array_queue
        Object[] increasedQueue = new Object[2 * x];
        System.arraycopy(queue, head, increasedQueue, 0, queue.length - head);

        //T' <= H' - 1  ∧  H > 0
        if (head != 0) {
            System.arraycopy(queue, 0, increasedQueue, queue.length - head, tail + 1);
        }
        // increasedQueue.length = L * 2
        // increasedQueue[j] == array_queue[i] : j = 0 .. t + 1,  i = (L - h) .. (L - h + t + 1))

        tail = queue.length - 1;
        head = 0;
        queue = increasedQueue;
    }
    // POST: L' == L * 2 ∧ S' == S ∧
    //       array_queue' == array_queue ∧ T' = S - 1 ∧ H' = 0

    public static void clear() {// delete all elements from array_queue
        queue = new Object[32];
        head = 0;
        tail = -1;
    }
    // POST: S' == 0 ∧ H' == 0 ∧
    //       T' == -1 ∧ L' == 32

    // PRE: S > 0 ∧ array_queue != null
    public static Object[] toArray() {
        Object[] array = new Object[size()];
        for (int i = 0; i < size(); i++) {
            array[i] = queue[(i + head) % queue.length];
        }
        return array;
    }
    // POST: R == getArray[i]
}

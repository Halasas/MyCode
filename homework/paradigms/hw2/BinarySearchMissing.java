package search;

public class BinarySearchMissing {

    //  PRE: i < j ∧ a[i] >= a[j]
    // POST:
    //  i < a.length  ∧  a[i] == x  => R = i
    //  i >= a.length  V a[i] != x  => R = -i-1
    public static int iterativeBinarySearch(int[] a, int x) {
        int l, r;
        l = 0;
        r = a.length;
        // INV: a[-1] => a[l-1] > x >= a[r] >= a[a.length]
        while (r > l) {
            // INV  ∧  l < r
            int m = ((r + l) / 2);
            // l <= m < r
            if (a[m] > x)
                // INV  ∧  a[m] > x
                // a[-1] >= a[m] > x >= a[r] >= a[a.length]
                l = m + 1;
            else
                // INV ∧ a[m] <= x
                // a[-1] >= a[l - 1] > x >= a[m] >= a[a.length]
                r = m;
        }
        //  INV  ∧  l >= r
        //  => a[l-1] > x >= a[r]  ∧  l-1 >= r-1
        //  => a[r-1] > x >= a[r]
        //  => ℝ = r
        //
        //  r < a.length  ∧  a[r] == x  => r
        //  r >= a.length  v  a[r] != x => -r-1
        return (r < a.length) && (a[r] == x) ? r : (-r - 1);
    }

    //  PRE: i < j ∧ a[i] >= a[j]
    // POST:
    //  i < a.length  ∧  a[i] == x  => R == i
    //  i >= a.length  v  a[i] != x => R == -i-1
    //  INV: a[-1] >= a[l-1] > x >= a[r] >= a[a.length]
    public static int recursiveBinarySearch(int a[], int x, int l, int r) {
        if (l > r) {
            // INV  ∧  l < r
            int m = (l + r) / 2;
            // l <= m < r

            if (a[m] > x) {
                // INV  ∧  a[m] > x
                // a[-1] > a[m] > x >= a[r] >= a[a.length]
                return recursiveBinarySearch(a, x, m + 1, r);
            } else {
                // INV ∧  x >= a[m]
                // a[-1] > a[l-1] > x >= a[m] >= a[a.length]
                return recursiveBinarySearch(a, x, l, m);
            }
        }
        //  INV  ∧  l >= r
        //  => a[l-1] > x >= a[r]  ∧  l-1 >= r-1
        //  => a[r-1] > x >= a[r]
        //  => ℝ = r
        //
        //  r < a.length  ∧  a[r] == x  => r
        //  r >= a.length  v  a[r] != x => -r-1
        else return (r < a.length) && (a[r] == x) ? r : (-r - 1);
    }

    public static void main(String[] args) {
        int x = Integer.parseInt(args[0]);
        int[] a = new int[args.length - 1];

        for (int i = 1; i <= a.length; i++)
            a[i - 1] = Integer.parseInt(args[i]);

        int r0 = iterativeBinarySearch(a, x);
        int r1 = recursiveBinarySearch(a, x, 0, a.length);
        System.out.println(r0);
    }
}

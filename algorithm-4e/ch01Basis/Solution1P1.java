/**
 * ch01Basis/Solution1P1.java
 * 2021/01/26
 */

public class Solution1P1 {
    public static void main(String[] args) {
//        Ans_1();
//        Ans_2();
//        Ans_3(args);
//        Ans_4();
//        Ans_5(args);
//        Ans_6();
//        Ans_7();
//        Ans_8();
//        Ans_9(args);
//        Ans_10();
//        Ans_11(args);
//        Ans_12();
//        Ans_13();
//        Ans_14(args);
//        Ans_15();
//        Ans_16(6);
//        Ans_17(6);
        System.out.println(Ans_18(2, 25));
    }

    // 1.1.1
    public static void Ans_1() {
        System.out.println((0 + 15) / 2);
        System.out.println(2e-6*100000000.1);
        System.out.println(true && false || true && true);
    }

    // 1.1.2
    public static void Ans_2() {
        System.out.println((1 + 2.236) / 2);
        System.out.println(1 + 2 + 3 + 4.0);
        System.out.println(4.1 >= 4);
        System.out.println(1 + 2 + "3");
    }

    // 1.1.3
    public static void Ans_3(String[] args) {
        int a, b, c;
        if (args.length != 3) {
            System.out.println("Invalid input.");
        } else {
            a = Integer.parseInt(args[0]);
            b = Integer.parseInt(args[1]);
            c = Integer.parseInt(args[2]);
            if ( a == b && b == c) {
                System.out.println("equal");
            } else {
                System.out.println("not equal");
            }
        }
    }

    // 1.1.4
    public static void Ans_4() {
    }

    // 1.1.5
    public static void Ans_5(String[] args) {
        if (args.length != 2) {
            return;
        }

        double x = Double.parseDouble(args[0]),
               y = Double.parseDouble(args[1]);
        if ((0.0 <= x && x <= 1.0) && (0.0 <= y && y <= 1.0)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }

    // 1.1.6
    public static void Ans_6() {
        int f = 0,
            g = 1;
        for (int i = 0; i <= 15; ++i) {
            System.out.println(f);
            f = f + g;
            g = f - g;
        }
    }

    // 1.1.7
    public static void Ans_7() {
        //a
        double t = 9.0;
        while (Math.abs(t - 9.0 / t) > .001) {
            t = (9.0/t + t) / 2.0;
        }
        System.out.println(t);

        //b
        int sumb = 0;
        for (int i = 0; i <= 1000; ++i) {
            for (int j = 0; j < i; j++) {
                sumb++;
            }
        }
        System.out.println(sumb);

        //c
        int sumc = 0;
        for (int i = 1; i < 1000; i *= 2) {
            for (int j = 0; j < 1000; j++) {
                sumc++;
            }
        }
        System.out.println(sumc);
    }

    // 1.1.8
    public static void Ans_8() {
        System.out.println('b');
        System.out.println('b' + 'c');
        System.out.println((char)('a' + 4));
    }

    // 1.1.9
    public static void Ans_9(String[] args) {
        if (args.length != 1) {
            return;
        }

        int x = Integer.parseInt(args[0]);
        String out = "";
        while (x != 0) {
            out = (x % 2) + out;
            x /= 2;
        }
        System.out.println(out);
    }
    
    // 1.1.10
    public static void Ans_10() {
        int[] a;
        for (int i = 0; i < 10; i++) {
//            a[i] = i * i;
        }
    }

    // 1.1.11
    public static void Ans_11(String[] args) {
        int row = Integer.parseInt(args[0]),
            vol = Integer.parseInt(args[1]);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < vol; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

    // 1.1.12
    public static void Ans_12() {
        int[] a = new int[10];
        for (int i = 0; i < 10; i++) {
            a[i] = 9 - i;
        }
        for (int i = 0; i < 10; i++) {
            a[i] = a[a[i]];
        }
        for (int i = 0; i < 10; i++) {
            System.out.println(a[i]);
        }
    }

    // 1.1.13
    public static void Ans_13() {
        int[][] a = {{1, 2, 3}, {4, 5, 6}};
        for (int col = 0; col < 3; col++) {
            for (int row = 0; row < 2; row++) {
                System.out.print(a[row][col] + " ");
            }
            System.out.println();
        }
    }

    // 1.1.14
    public static void Ans_14(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = 0;
        while (a >= 2) {
            a /= 2;
            b++;
        }
        System.out.println(b);
    }

    // 1.1.15
    public static void Ans_15() {
        int[] a = new int[] {1, 2, 3, 4, 5, 6, 2, 4, 8, 9};
        for (int i = 10; i < 10; i++) {
            int cnt = 0;
            for (int j = 0; j < 10; j++) {
                if (j == a[j]) {
                    cnt++;
                }
            }
            System.out.println(cnt);
            cnt = 0;
        }
    }

    // 1.1.16
    public static String Ans_16(int n) {
        if (n <= 0) {
            return "";
        }
        return Ans_16(n-3) + n + Ans_16(n-2) + n;
    }

    // 1.1.17
    public static String Ans_17(int n) {
        String s = Ans_17(n-3) + n + Ans_17(n-2) + n;
        if (n <= 0) {
            return "";
        }
        return s;
    }

    // 1.1.18
    public static int Ans_18(int a, int b) {
        if (b == 0) {
            return 0;
        }
        if (b % 2 == 0) {
            return Ans_18(a + a, b/2);
        }
        return Ans_18(a + a, b / 2) + a;
    }

    // 1.1.19
    public static int Ans_19(int N) {
        if (N <= 1) {
            return N;
        }
        return Ans_19(N-2) + Ans_19(N - 1);
    }

    // 1.1.20
    public static double Ans_20(int N) {
        if (N <= 1) {
            return Math.log(N);
        }
        return Math.log(N) + Ans_20(N - 1);
    }

}


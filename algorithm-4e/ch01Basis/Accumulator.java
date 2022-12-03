/**
 * ch01Basis/Accumulator.java
 * 2021/02/22
 */

import edu.princeton.cs.algs4.StdRandom;

public class Accumulator {
    private double total;
    private int N;

    public void addDataValue(double val) {
        N++;
        total += val;
    }

    public double mean() {
        return total / N;
    }

    public String toString() {
        return "Mean (" + N + " values): " + String.format("%7.5f", mean());
    }

    public static void main(String[] args) {
        int T = Integer.parseInt(args[0]);
        Accumulator acc = new Accumulator();
        for (int i = 0; i < T; i++) {
            acc.addDataValue(StdRandom.random());
        }

        System.out.println(acc);
    }
}

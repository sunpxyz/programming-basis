/*
  ch01Basis/Rolls.java
  2021/02/20
 */

import edu.princeton.cs.algs4.Counter;
import edu.princeton.cs.algs4.StdRandom;

public class Rolls {
    public static void main(String[] args) {
        int T = Integer.parseInt(args[0]);

        int SIDES = 6;
        Counter[] rolls = new Counter[SIDES+1];
        for (int i = 1; i <= SIDES; i++) {
            rolls[i] = new Counter(i + "'s");
        }

        for (int i = 0; i < T; i++) {
            int result = StdRandom.uniform(1, SIDES+1);
            rolls[result].increment();
        }
        for (int i = 1; i <= SIDES; i++) {
            System.out.println(rolls[i]);
        }
    }
}

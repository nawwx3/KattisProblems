import java.util.Scanner;
import java.math.*;

import static java.math.BigDecimal.ROUND_HALF_UP;

/*
 * Created by Nathan Welch on 2/23/2017.
 * A real Challenge - Kattis Problem
 */


public class main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String i = in.next();
        BigDecimal invalue = new BigDecimal(i);
        System.out.println(invalue);

        BigDecimal front = new BigDecimal(0); //const for bigDecimal 0
        BigDecimal one = new BigDecimal(1); //const for bigDecimal 1

        BigDecimal ending = one.scaleByPowerOfTen(18).add(one); //const for upper bound
        System.out.println(ending);

        //finds values to be compared with
        int greater = invalue.compareTo(ending);
        int less = invalue.compareTo(front);

        //compares values, prints if in range of 1 <= x <= 10^18
        if(less == 1 && greater == -1)
            System.out.println(sqrt(invalue, 30));
    }

    public static BigDecimal sqrt(BigDecimal A, final int SCALE) {
        final BigDecimal TWO = BigDecimal.valueOf(2);

        BigDecimal x0 = new BigDecimal("0");
        BigDecimal x1 = new BigDecimal(Math.sqrt(A.doubleValue()));
        while (!x0.equals(x1)) {
            x0 = x1;
            x1 = A.divide(x0, SCALE, ROUND_HALF_UP);
            x1 = x1.add(x0);
            x1 = x1.divide(TWO, SCALE, ROUND_HALF_UP);

        }
        return x1;
    }
}



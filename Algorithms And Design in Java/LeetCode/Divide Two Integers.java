/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2

*/

class Solution {

    public int divide(int dividend, int divisor) {
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        	sign = -1;

        long ldividend = Math.abs(dividend);
        long ldivisor = Math.abs(divisor);

        // take care edge
        if (ldivisor == 0) return Integer.MAX_VALUE;
        if (ldividend == 0 || ldividend < ldivisor) return 0;

        long lans = divide(ldividend, ldivisor);
        
        int ans;
        if (lans > Integer.MAX_VALUE) {
        	ans = (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        } esle {
        	ans = (int) (sign) * lans;
        }

        return ans;
    }

    private long divide(long dividend, long divisor) {
    	if (dividend < divisor) return 0;

    	long sum = divisor;
    	long multiple = 1;
    	while (sum + sum <= dividend) {
    		sum += sum;
    		multiple++;
    	}

    	return multiple + divide(dividend - sum, divisor);
    }

}

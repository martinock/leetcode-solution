class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        
        String finalResult = "0";
        for (int i = num1.length()-1; i >= 0; i--) {
            int digit = Character.getNumericValue(num1.charAt(i));
            int carry = 0;
            String tempResult = "";
            for (int j = num2.length()-1; j >= 0; j--) {
                int digit2 = Character.getNumericValue(num2.charAt(j));
                int product = (digit * digit2) + carry;
                carry = product / 10;
                product = product % 10;
                
                tempResult = Integer.toString(product) + tempResult;
            }
            
            if (carry > 0) {
                tempResult = Integer.toString(carry) + tempResult;
                carry = 0;
            }
            
            int trailingZeroCount = num1.length()-1-i;
            while (trailingZeroCount > 0) {
                tempResult += "0";
                trailingZeroCount--;
            }
            
            finalResult = add(finalResult, tempResult);
        }
        
        return finalResult;
    }
    
    private String add(String num1, String num2) {
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        String result = "";
        
        while(i >= 0 && j >= 0) {
            int digit = Character.getNumericValue(num1.charAt(i)) + Character.getNumericValue(num2.charAt(j)) + carry;
            carry = digit / 10;
            digit = digit % 10;
            
            result = Integer.toString(digit) + result;
            i--;
            j--;
        }
        
        while (i >= 0) {
            int digit = Character.getNumericValue(num1.charAt(i)) + carry;
            carry = digit / 10;
            digit = digit % 10;
            
            result = Integer.toString(digit) + result;
            i--;
        }
        
        while (j >= 0) {
            int digit = Character.getNumericValue(num2.charAt(j)) + carry;
            carry = digit / 10;
            digit = digit % 10;
            
            result = Integer.toString(digit) + result;
            j--;
        }
        
        if (carry > 0) {
            result = Integer.toString(carry) + result;
        }
        
        return result;
    }
}
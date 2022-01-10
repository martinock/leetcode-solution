func addStrings(num1 string, num2 string) string {
	carry := 0
	i := len(num1) - 1
	j := len(num2) - 1
	result := ""

	for i >= 0 || j >= 0 || carry > 0 {
		sumDigit := 0
		if i >= 0 {
			digit, _ := strconv.Atoi(string(num1[i]))
			sumDigit += digit
			i--
		}

		if j >= 0 {
			digit, _ := strconv.Atoi(string(num2[j]))
			sumDigit += digit
			j--
		}

		sumDigit += carry
		carry = sumDigit / 10
		result = strconv.Itoa(sumDigit%10) + result
	}

	return result
}
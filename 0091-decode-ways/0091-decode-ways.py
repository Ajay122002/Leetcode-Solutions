class Solution:
    def numDecodings(self, s: str) -> int:
        # Initialize an array to store the number of ways to decode the string
        # ending at each index
        dp = [0] * (len(s) + 1)

        # Base case: there is only one way to decode an empty string
        dp[0] = 1

        # Iterate through the string, starting from the first character
        for i in range(1, len(s) + 1):
            # If the current character is non-zero, then it can be decoded as a
            # single character, so add the number of ways to decode the previous
            # substring to the current number of ways
            if s[i - 1] != '0':
                dp[i] += dp[i - 1]

            # If the current character and the previous character form a valid
            # two-digit number between 10 and 26, then those two characters can
            # be decoded as a single number, so add the number of ways to decode
            # the substring ending two characters before to the current number of
            # ways
            if i > 1 and 10 <= int(s[i - 2:i]) <= 26:
                dp[i] += dp[i - 2]

        # Return the number of ways to decode the entire string
        return dp[len(s)]

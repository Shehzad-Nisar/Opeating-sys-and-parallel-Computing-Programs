# Function to match strings based on specific patterns
# First pattern: Starts with '0' and ends with '1' with only '0' or '1' in the middle
# Second pattern: Starts with '1' and ends with '0', with only '0' or '1' in between

def match_pattern(string):
    if len(string) < 2:
        return False  # Too short to match any valid pattern

    if string[0] == '0' and string[-1] == '1':
        # Check if the middle part only contains '0' or '1'
        middle_part = string[1:-1]
        return all(char in '01' for char in middle_part)
    
    elif string[0] == '1' and '0' in string[1:]:
        # Ensure the string ends with '0' after starting with '1'
        if not string.endswith('0'):
            return False
        # Check that the remaining characters are only '0' or '1'
        return all(char in '01' for char in string[1:])
    
    return False

# Test cases to check the string matching function
test_strings = ["011", "0101", "100", "1010", "1100", "0", "1", "001", "1a0", ""]

for test_str in test_strings:
    result = match_pattern(test_str)
    print(f"Input: '{test_str}' -> Accepted: {result}")

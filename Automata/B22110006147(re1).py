# DFA to recognize the language: a(a + b)*
# i.e., strings that start with 'a' and are followed by any number of 'a' or 'b'

def dfa_starts_with_a_followed_by_ab(string):
    current_state = 'q0'  # Initial state

    for symbol in string:
        if current_state == 'q0':
            # From q0, only 'a' is accepted to go to q1
            if symbol == 'a':
                current_state = 'q1'
            else:
                return False  # Any other symbol in q0 is invalid
        elif current_state == 'q1':
            # From q1, both 'a' and 'b' keep us in q1
            if symbol == 'a' or symbol == 'b':
                continue  # Stay in q1
            else:
                return False  # Invalid symbol

    # Accepting state is q1
    return current_state == 'q1'

# Test the DFA with various inputs
test_strings = ["a", "ab", "aa", "abbab", "b", "", "ba", "aaaabbb"]

for input_str in test_strings:
    result = dfa_starts_with_a_followed_by_ab(input_str)
    print(f"Input: {input_str.ljust(8)} -> Accepted: {result}")

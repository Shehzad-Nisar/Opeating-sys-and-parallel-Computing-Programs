def dfa_a_plus_b_a_plus_b_star(input_str):
    state = 'q0'
    if input_str == "":
        return False  # Reject empty string

    for ch in input_str:
        if ch not in ('a', 'b'):
            return False  # Invalid symbol
        if state == 'q0':
            state = 'q1'  # First valid character (a or b)
        elif state == 'q1':
            state = 'q1'  # Loop on a or b
    return state == 'q1'
test_inputs = ["a", "b", "ab", "ba", "aa", "abab", "", "abc"]
for s in test_inputs:
    print(f"Input: {s.ljust(5)} -> Accepted: {dfa_a_plus_b_a_plus_b_star(s)}")

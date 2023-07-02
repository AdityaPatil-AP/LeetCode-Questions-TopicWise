from collections import Counter

def get_words_from_string(text):
    words = text.split()
    return words

def helper(text, k):
    words = get_words_from_string(text)
    word_counts = Counter(words)
    ans = []
    for word in words:
        if word_counts[word] >= k:
            ans.append(word)
            word_counts[word] = 0
    return ans

if __name__ == '__main__':
    text = "hello the a a the the is ohkay ohkay hello"
    ans = helper(text, 2)

    for word in ans:
        print(word, end=" ")
    print()

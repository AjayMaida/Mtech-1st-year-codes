def findAllConcatenatedWordsInADict(words):
    result = []
    for i in range(len(words)):
        for j in range(i+1, len(words)):
            if words[i] in words[j]:
                if check_concatenated(words[j], words[i], set(words)):
                    result.append(words[j])
            elif words[j] in words[i]:
                if check_concatenated(words[i], words[j], set(words)):
                    result.append(words[i])
    return result

def check_concatenated(word, part, words):
    if part in words:
        rest = word.replace(part, "")
        if not rest:
            return True
        return check_concatenated(rest, part, words) or check_concatenated(rest, word, words)
    return False

# Example usage:
words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
print(findAllConcatenatedWordsInADict(words))

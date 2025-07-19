char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) {
        char* empty = malloc(sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < len; i++) {
        int left = i - 1;
        int right = i + 1;

        while (right < len && s[i] == s[right]) {
            right++;
        }

        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }

        int currentLength = right - left - 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = left + 1;
        }
    }

    char* result = malloc((maxLength + 1) * sizeof(char));
    strncpy(result, &s[start], maxLength);
    result[maxLength] = '\0';

    return result;
}
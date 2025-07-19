bool isValid(char* s) {
    int len = strlen(s);
    if(len % 2 != 0) {
        return false;
    }

    char* stack = (char*) malloc(len * sizeof(char));
    int top = -1;

    for(int i = 0; i < len; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i] == '(' ? ')' : (s[i] == '[' ? ']' : '}');
        }
        else if(top == -1 || stack[top--] != s[i]) {
            free(stack);
            return false;
        }
    }

    free(stack);
    return top == -1;
}
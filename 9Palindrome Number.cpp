bool isPalindrome(int x) {
    int tx = x;
    long y = 0;
    while(tx != 0) {
        y *= 10;
        y += (tx % 10);
        tx /= 10;
    }
    return y == x && x >= 0;
}

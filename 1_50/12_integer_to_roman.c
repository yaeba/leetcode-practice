char* intToRoman(int num) {
    int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char roman[][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
                      "V", "IV", "I"};
    int n = 13;
    char *arr = (char*)malloc(sizeof(char) * 50);
    
    while (num != 0) {
        for (int i=0; i<n; i++) {
            while (num >= number[i]) {
                strcat(arr, roman[i]);
                num -= number[i];
            }
        }
    }
    return arr;
}

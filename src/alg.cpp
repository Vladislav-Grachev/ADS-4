/ Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
     int result = 0;
     for (int i = 0; i < len - 1; i++) {
         for (int j = i + 1; j < len; j++) {
             if (arr[i] + arr[j] == value)
                result++;
         }
      }
      return result;
}

int countPairs2(int* arr, int len, int value) {
     int result = 0;
     int right = len - 1;
     for (int end = len - 1; arr[end] > value; end--)
         right--;
     for (int i = 0; i <= len; i++) {
         if (arr[i] > value / 2)
            break;
         for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                result++;
            }
            if (arr[i] + arr[j] < value)
               break;
         }
     }
     return result;
}

int countPairs3(int* arr, int len, int value) {
    int result = 0;
    int left = 0;
    int right = len - 1;
    int middle = 0;
    int count = 0;
    while (left < right - 1) {
        middle = (left + right) / 2;
        if (arr[middle] < value) {
            right = middle;
        } else {
            left = middle;
        }
    }
    len = right - 1;
    for (int i = 0; i < len; i++) {
        left = i + 1, right = len - 1;
        count = 0;
        while (left < right) {
            middle = (left + right) / 2;
            if (arr[middle] < (value - arr[i])) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        while (arr[left] == (value - arr[i])) {
            count++;
            left++;
        }
        result += count;
    }
    return result;
}

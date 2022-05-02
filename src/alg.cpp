// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        pairs++;
    }
  }
  return pairs;
}
int countPairs2(int *arr, int len, int value) {
  int pairs = 0;
  int l = len;
  int q = len - 1;
  for (int x = len - 1; arr[l] > value; l--)
    q--;
  for (int i = 0; i <= len; i++) {
    if (arr[i] > value / 2)
      break;
    for (int j = q; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        pairs++;
      }
      if (arr[i] + arr[j] < value)
        break;
    }
  }
  return pairs;
}
int countPairs3(int* arr, int len, int value) {
    int res = 0;
    int l = 0;
    int r = len - 1;
    int mid = 0;
    int count = 0;
    while (l < r - 1) {
        mid = (l + r) / 2;
        if (arr[mid] < value) {
            r = mid;
        } else {
            l = mid;
        }
    }
    len = r - 1;
    for (int i = 0; i < len; i++) {
        l = i + 1, r = len - 1;
        count = 0;
        while (l < r) {
            middle = (l + r) / 2;
            if (arr[mid] < (value - arr[i])) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        while (arr[left] == (value - arr[i])) {
            count++;
            l++;
        }
        res += count;
    }
    return res;
}

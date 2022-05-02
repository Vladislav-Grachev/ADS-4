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
int countPairs3(int *arr, int len, int value) {
  int pairs = 0;
  int q = len - 1;
  for (int i = 0; i < len - 1; i++) {
    bool res = false;
    int l = i + 1;
    int mid = (l + q) / 2;
    while (l <= q) {
      if (arr[i] + arr[mid] == value) {
        pairs++;
        res = true;
        break;
      }else{ if (arr[mid] > value - arr[i]) {
        q = mid - 1;
      }
      }else{ if (arr[mid] < value - arr[i]) {
        l = mid + 1;
      }
      }
      mid = (l + q) / 2;
    }
    int cur1 = mid;
    int cur2 = mid;
    if (res == true) {
      while (arr[cur1 - 1] == arr[mid] && cur1 - 1 != i) {
        pairs++;
        cur1--;
      }
      while (arr[cur2 + 1] == arr[mid]) {
        pairs++;
        cur2++;
      }
    }
  }
  return pairs;
}

/*Bucket sort in C*/ 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

void BucketSort(int arr[], int n, int nBucket, int interval) {
  int i, j;
  struct Node **buckets;

  buckets = (struct Node **)malloc(sizeof(struct Node *) * nBucket);

  for (i = 0; i < nBucket; ++i) {
    buckets[i] = NULL;
  }

  for (i = 0; i < n; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i], interval);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  for (i = 0; i < nBucket; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  for (j = 0, i = 0; i < nBucket; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}








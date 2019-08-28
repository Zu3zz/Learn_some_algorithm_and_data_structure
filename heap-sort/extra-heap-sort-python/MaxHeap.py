# -*- coding: utf-8 -*-
# @Author : 3zz
# @Time   : 2019-08-17 23:27
# @File   : MaxHeap.py
import random


class MaxHeap:

    def __init__(self, data=None, capacity=10):
        if not data:
            self._data = [None] * (capacity + 1)
            self._count = 0
            self._capacity = capacity
        else:
            n = len(data)
            self._data = [None] * (n + 1)
            for i in range(n):
                self._data[i + 1] = data[i]
            self._count = n
            self._capacity = n + 1
            for i in range(self._count // 2, 0, -1):
                self._shift_down(i)

    def _shift_down(self, k):
        while 2 * k <= self._count:
            j = 2 * k  # swap self._data[j] self._data[k]
            if j + 1 <= self._count and self._data[j + 1] > self._data[j]:
                j += 1  # switch to the right point
            if self._data[k] >= self._data[j]:
                break
            self._data[k], self._data[j] = self._data[j], self._data[k]
            k = j

    def _shift_up(self, k):
        while k > 1 and self._data[k // 2] < self._data[k]:
            self._data[k // 2], self._data[k] = self._data[k], self._data[k // 2]
            k //= 2

    def extract_max(self):
        assert self._count > 0, 'can not extract max from empty heap'
        ret = self._data[1]
        self._data[1], self._data[self._count] = self._data[self._count], self._data[1]
        self._count -= 1
        self._shift_down(1)
        return ret

    def size(self):
        return self._count

    def is_empty(self):
        return self._count == 0

    def insert(self, val):
        assert (self._count > 0)
        self._count += 1
        self._data.append(val)
        self._shift_up(self._count)


def main():
    data = [1]
    maxheap = MaxHeap(data)
    for i in range(10):
        maxheap.insert(random.randint(0, 100))
    while not maxheap.is_empty():
        print(maxheap.extract_max())


if __name__ == "__main__":
    main()
    # print(int(7 / 2))

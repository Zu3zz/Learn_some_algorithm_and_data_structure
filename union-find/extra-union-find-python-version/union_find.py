# -*- coding: utf-8 -*-
# @Author : 3zz
# @Time   : 2019-09-02 17:23
# @File   : union_find.py


class UnionFind:
    """
    普通并查集 时间复杂度O(n)
    """

    def __init__(self, n):
        self._count = n
        self._id = [i for i in range(n)]

    def _find(self, p):
        assert 0 <= p <= self._count
        return self._id[p]

    def is_connected(self, p, q):
        return self._find(p) == self._find(q)

    def union(self, p, q):
        assert 0 <= p < self._count and 0 <= q < self._count
        p_id = self._find(p)
        q_id = self._find(q)
        if p_id == q_id:
            return
        for i in range(self._count):
            if self._id[i] == q_id:
                self._id[i] = p_id


class UnionFind2:
    """
    利用parent数组存储结果
    """

    def __init__(self, n):
        self._count = n
        self._parent = [i for i in range(n)]

    def _find(self, p):
        assert 0 <= p < self._count
        while p != self._parent[p]:
            p = self._parent[p]
        return p

    def is_connected(self, p, q):
        return self._find(p) == self._find(q)

    def union(self, q, p):
        assert 0 <= q < self._count and 0 <= p < self._count
        q_root = self._find(q)
        p_root = self._find(p)
        if p_root == q_root:
            return
        self._parent[p_root] = q_root


class UnionFind3:
    """
    新加一个size数组用来存储以i为根的集合中的元素个数
    """

    def __init__(self, n):
        self._count = n
        self._sz = [1] * n
        self._parent = [i for i in range(n)]

    def _find(self, p):
        assert 0 <= p < self._count
        while p != self._parent[p]:
            p = self._parent[p]
        return p

    def is_connected(self, q, p):
        return self._find(q) == self._find(p)

    def union(self, q, p):
        p_root = self._find(p)
        q_root = self._find(q)
        if q_root == p_root:
            return
        if self._sz[q_root] < self._sz[p_root]:
            self._parent[q_root] = p_root
            self._sz[p_root] += self._sz[q_root]
        else:
            self._parent[p_root] = q_root
            self._sz[q_root] += self._sz[p_root]


class UnionFind4:
    """
    利用rank数组用来存储以i为根的集合所表示的层数
    利用层数可以用来加速集合间的合并 从而不要让并查集长度过长
    """

    def __index__(self, n):
        self._count = n
        self._rank = [i for i in range(n)]
        self._parent = [i for i in range(n)]

    def find(self, q):
        assert 0 <= q < self._count
        while q != self._parent[q]:
            q = self._parent[q]
        return q

    def is_connected(self, p, q):
        return self.find(q) == self.find(p)

    def union(self, p, q):
        p_root = self.find(p)
        q_root = self.find(q)
        if p_root == q_root:
            return
        if self._rank[p_root] < self._rank[q_root]:
            self._parent[p_root] = q_root
        elif self._rank[p_root] > self._rank[q_root]:
            self._parent[q_root] = p_root
        else:
            # rank[p_root] = rank[q_root]
            self._parent[q_root] = p_root
            self._rank[q_root] += 1


class UnionFind5:
    """
    使用压缩路径能够更进一步加快union操作
    """

    def __init__(self, n):
        self._count = n
        self._rank = [1] * n
        self._parent = [i for i in range(n)]

    def find(self, p):
        """
        在这里 使用递归的方式进行路径压缩
        """
        assert 0 <= p < self._count
        if p != self._parent[p]:
            self._parent[p] = self.find(self._parent[p])
        return self._parent[p]

    def find2(self, p):
        """
        递归有可能导致栈溢出 所以find2使用非递归方式进行路径压缩
        """
        assert 0 <= p < self._count
        r = p
        while r != self._parent[r]:
            r = self._parent[r]
        k = p
        while k != r:
            j = self._parent[k]
            self._parent[k] = r
            k = j
        return r

    def is_connect(self, q, p):
        return self.find(q) == self.find(p)

    def union(self, p, q):
        assert 0 <= q < self._count and 0 <= p < self._count
        q_root = self.find(q)
        p_root = self.find(p)
        if p_root == q_root:
            return
        if self._rank[p_root] < self._rank[q_root]:
            self._parent[p_root] = q_root

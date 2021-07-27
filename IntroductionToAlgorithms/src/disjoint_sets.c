#include "disjoint_sets.h"

void Initialize( DisjSet S ) {
    int i;

    for (i = NumSets; i > 0; i--)
        S[i] = 0;
}

#if 0

void SetUnion( DisjSet S, SetType Root1, SetType Root2 ) {
    S[Root2] = Root1;
}

SetType Find( ElementType X, DisjSet S) {
    if (S[X] <= 0)
        return X;
    else
        return Find(S[X], S);
}

#endif

/**
 * 按秩合并 union by rank
 */
void SetUnion( DisjSet S, SetType Root1, SetType Root2 ) {
    if (S[Root2] < S[Root1])
        S[Root1] = Root2;
    else {
        if (S[Root1] == S[Root2])
            S[Root1]--;
        S[Root2] = Root1;
    }
}

/**
 * 路径压缩 path compression
 */
SetType Find( ElementType X, DisjSet S) {
    if (S[X] <= 0)
        return X;
    else
        return S[X] = Find(S[X], S);
}

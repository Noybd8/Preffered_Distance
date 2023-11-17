#pragma once
struct Item {
    int x;
    int w;
    int nextWhite;
    int d;
    int d2;
    int line;
    Item(int x1, int w1, int line1)
    {
        x = x1;
        w = w1;
        line = line1;
    }
    Item() {}
};

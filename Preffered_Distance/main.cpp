#include "HelpFunctions.h"
#include "tools.h"
#include "Stack.h"
//In colorArr : True = "white city", False = "black city"
int findNextWhite(List stateStructure[], int x, bool colorArr[])
{
    if (stateStructure[x].getCurrent() == NULL)
        return -1;
    while (colorArr[stateStructure[x].getCurrent()->getData()] == false)
    {
        stateStructure[x].promoteCurrent();
        if (stateStructure[x].getCurrent() == NULL)
            return -1;
    }
    return stateStructure[x].getCurrent()->getData();
}
int TownDistance(List stateStructure[], int x, int w, bool colorArr[])
{
    colorArr[x] = false;
    int nextWhite;
    int d;
    int d2;
    if (x == w)
        return 0;
    else
    {
        nextWhite = findNextWhite(stateStructure, x, colorArr);
        if (nextWhite == -1)
            return -1;
        d = TownDistance(stateStructure, nextWhite, w, colorArr);
        if (d != -1)
            return 1 + d;
        else {
            d2 = TownDistance(stateStructure, x, w, colorArr);
            return d2;
        }

    }


}

int CancleRecurs(List stateStructure[], int x, int w, bool colorArr[]) {
    Stack S;
    S.createEmptyStack();
    int returnValue;
    Item Curr(x, w, START);
    S.Push(Curr);
    while (!S.IsEmpty()) {
        Curr = S.Pop();
        if (Curr.line == START) {
            colorArr[Curr.x] = false;
            if (Curr.x == Curr.w)
            {
                returnValue = 0;
            }
            else
            {
                Curr.nextWhite = findNextWhite(stateStructure, Curr.x, colorArr);
                if (Curr.nextWhite == -1)
                    returnValue = -1;
                else
                {
                    Curr.line = AFTER_FIRST;
                    S.Push(Curr);
                    Item Next(Curr.nextWhite, w, START);
                    S.Push(Next);

                }
            }

        }
        else if (Curr.line == AFTER_FIRST) {
            Curr.d = returnValue;
            if (Curr.d != -1)
            {
                returnValue = Curr.d + 1;
            }
            else
            {
                Curr.line = AFTER_SECOND;
                S.Push(Curr);
                Item Next(Curr.x, w, START);
                S.Push(Next);
            }
        }
        else if (Curr.line == AFTER_SECOND) {
            Curr.d2 = returnValue;
            returnValue = Curr.d2;

        }


    }
    return returnValue;
}
int main()
{
    int n;
    int roads;
    int count = 0;
    int x;
    int w;
    int c1, c2;
    cin >> n;
    if (n <= 0) {
        cout << "invalid input";
        return 0;
    }
    List* arr = new List[n + 1];
    bool** roadsArr = new bool* [n + 1];
    for (int i = 1; i <= n; i++)
        roadsArr[i] = new bool[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            roadsArr[i][j] = false;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i].createEmptyList();

    }
    cin >> roads;
    while (count != roads)
    {
        cin >> c1;
        cin >> c2;
        if (roadsArr[c1][c2] == true) {
            cout << "invalid input \n";
            return 0;
        }
        else if (c1 == c2) {
            cout << " invalid input \n";
            return 0;
        }
        else if ((!IsNormal(c1, n)) || (!IsNormal(c2, n))) {
            cout << " invalid input\n";
            return 0;
        }
        else
        {

            roadsArr[c1][c2] = true;
            roadsArr[c2][c1] = true;
            Node* node1 = new Node(c2);
            arr[c1].addToEnd(node1);
            Node* node2 = new Node(c1);
            arr[c2].addToEnd(node2);
            count++;
        }
    }
    //sort in order to create the state structure:
    for (int i = 1; i <= n; i++)
    {
        Node* left = arr[i].getHead();
        Node* right = arr[i].getTail();
        selection(left, right);
    }
    cin >> x;
    if (x<1 || x>n) {
        cout << "invalid input";
        return 0;
    }
    cin >> w;
    if (w< 1 || w >n) {
        cout << "invalid input";
        return 0;
    }
    bool* colorArr = new bool[n + 1];
    InitVariables(colorArr, n, arr);
    int d = TownDistance(arr, x, w, colorArr);
    cout << "Preferred distance (recursive algorithm): " << d;
    cout << "\n";
    InitVariables(colorArr, n, arr);
    int t = CancleRecurs(arr, x, w, colorArr);
    cout << "Preferred distance (iterative stack algorithm): " << t;
    for (int i = 1; i <= n; i++)
        delete[] roadsArr[i];
    delete[] roadsArr;
    delete[] colorArr;
    delete[] arr;
    cout << "\n";


}
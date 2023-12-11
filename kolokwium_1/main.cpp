#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int serie(int x[], int y[], int z[], const int n)
{
    int ilosc_serii = 0;
    bool ktora = false; // false do tab2, true do tab3
    int dl_tab2 = -1, dl_tab3 = -1, last_tab2 = 0, last_tab3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > x[i + 1])
        {
            ilosc_serii++;
            if(!ktora)
            {
                for (int j = last_tab3; j <= i; j++)
                {
                    dl_tab2++;
                    y[dl_tab2] = x[j];
                }
                ktora = true; // zminana na  tab3
                last_tab2 = i + 1;
            }
            else
            {
                for (int j = last_tab2; j <= i; j++)
                {
                    dl_tab3++;
                    z[dl_tab3] = x[j];
                }
                ktora = false; // zmiana na tab2
                last_tab3 = i + 1;
            }
            continue;
        }
    }
    return ilosc_serii;
}

int main()
{
    srand(time(nullptr));
    const int n = 20;
    int tab1[n], tab2[n], tab3[n];
    for (int i = 0; i < n; i++)
    {
       tab1[i] = rand() % 47 + 23; // losuje liczby z zakresu 23 - 69
       tab2[i] = 0;
       tab3[i] = 0;
    }
    cout << endl;
    for (int i : tab1)
    {
        cout << i << "  ";
    }
    cout << endl << endl << "ilosc serii: " << serie(tab1, tab2, tab3, n) << endl;

    for (int i : tab2)
    {
        if(i == 0)
            break;
        cout << i << "  ";
    }
    cout << endl;
    for (int i : tab3)
    {
        if(i == 0)
            break;
        cout << i << "  ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int serie(int x[], int y[], int z[], const int n)
{
    int ilosc_serii = 0;
    bool ktora = false; // false do tab2, true do tab3
    int dl_tab2 = 0, dl_tab3 = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (x[i] > *(x + 1))
        {
            ilosc_serii++;
            if(!ktora)
            {
                for (int j = dl_tab2; j <= i; j++)
                {
                    y[j] = x[j];
                }
                ktora = true; // zminana na  tab3
                dl_tab2 = i++;
            }
            else
            {
                for (int j = dl_tab3; j <= i; j++)
                {
                    z[j] = x[j];
                }
                ktora = false; // zmiana na tab2
                dl_tab3 = i++;
            }
            continue;
        }
    }
    return ilosc_serii;
}

int main()
{
    srand(time(NULL));
    const int n = 20;
    int tab1[n], tab2[n], tab3[n];
    for (int i = 0; i < n; i++)
    {
        tab1[i] = rand() % 47 + 23;
        tab2[i] = 0;
        tab3[i] = 0;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << tab1[i] << "  ";
    }
    cout << endl << endl << "ilosc serii: " << serie(tab1, tab2, tab3, n) << endl;

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int serie(int x[], int y[], int z[], const int n)
{
	int ilosc_serii = 0;
	bool ktora = false; // false do tab2, true do tab3
	int dl_tab2 = -1, dl_tab3 = -1, last_tab2 = 0, last_tab3 = 0;
	for (int i = 0; i < n-1; i++)
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
				last_tab2 = i+1;
			}
			else
			{
				for (int j = last_tab2; j <= i; j++)
				{
					dl_tab3++;
					z[dl_tab3] = x[j];
				}
				ktora = false; // zmiana na tab2
				last_tab3 = i+1;
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
	int* tab = new int[n];
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
	for (int i = 0; i < n; i++)
	{
		if(tab2[i] == 0)
			break;
		cout << tab2[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if(tab3[i] == 0)
			break;
		cout << tab3[i] << "  ";
	}

	return 0;
}
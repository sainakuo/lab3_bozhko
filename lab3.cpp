#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//считаем количество повторений в двумерной матрице
int repeat_fun (int mass[6][6]) {
	int count = 0;

	//повторения по горизонтали
	for (int i = 0; i < 6; i++) {
	    for (int j = 0; j < 6; j++) {
			int a = mass[i][j];
			for (int k = j+1; k < 6; k++) {
			    if (a == mass[i][k]) {
				   count++;
				}
			}
		}
	}

    //повторения по вертикали
	for (int j = 0; j < 6; j++) {
	    for (int i = 0; i < 6; i++) {
			int a = mass[i][j];
			for (int k = i+1; k < 6; k++) {
			    if (a == mass[k][j]) {
				   count++;
				}
			}
		}
	}

	//повторения по диагонали 1
	for (int j = 0; j < 6; j++) {
	    int a = mass[j][j];
		for (int k = j+1; k < 6; k++) {
		    if (a == mass[k][k])
				count++;
		}
	}

    int g=5;
    int v;

    //повторения по диагонали 2
	for (int i=0; i<6; i++) {  
		int a = mass[i][g];
        v = i+1; 
		for (int j = g-1; j >= 0; j--) {
				if (a == mass[v][j])
					count++;
				v++;
	    }
	    g--;
	}

    return count;  
}
	

int main()
{
	int key[6][6] = {{1,1,1,1,1,1}, {0,0,0,0,0,0}, {0,0,0,1,1,1}, {0,0,0,0,0,0}, {1,1,1,0,0,0}, {0,0,0,0,0,0}}; //неизменные значения (ключ) по строкам
	int rez[6][6] = {{1,2,3,4,5,6}, {0,0,0,0,0,0}, {0,0,0,1,3,4}, {0,0,0,0,0,0}, {2,3,5,0,0,0}, {0,0,0,0,0,0}}; //сами значения

	int min_mass[6][6];

	int key_stolb[6][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,1,0,0,0},{1,0,1,0,0,0},{1,0,1,0,0,0}}; //неизменные значения (ключ) по столбцам
	int rez_stolb[6][6] = {{1,0,0,0,2,0},{2,0,0,0,3,0},{3,0,0,0,5,0},{4,0,1,0,0,0},{5,0,3,0,0,0},{6,0,4,0,0,0}}; //сами значения
	
	int key2 = 0;
	int l = 1;
	int tek_l;

    //инициализация двумерной матрицы (без повторений в столбцах)
	for (int j = 0; j < 6; j++) {

		for (int i = 0; i < 6; i++) {

			if (key[i][j] == 0) {

				for (l = 1; l < 7; l++) {
				    
					for (int k = 0; k < 6; k++) {
						if (l == rez[k][j]) { 
						   key2 = 1;
					    }   
			        }

					if (key2 == 1) {
						key2 = 0;
						continue;
					}
					else {
						tek_l = l;
						break;
					}
			    }
			    rez[i][j] = tek_l;
		    }
	     }
	}

    cout << endl; 
    cout <<"первоначальная матрица: "<< endl;

	for (int i = 0; i < 6; i++) {
	   for (int j = 0; j < 6; j++) {
	       cout <<rez[i][j] << " ";
	   }
    cout << endl;	
 	}

	int mass[6];
	int k=0;

	int tek_min;
	int min = 100;
	int count_iter = 0;

    //записываем столбец в массив
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
		    mass[k] = rez[i][j];
			k++;
		}

	k = 0;
    sort (mass,mass+6);
	int mass_min[6];

		
    do {

	    int key3 = 0;
		for (int i = 0; i < 6; i++) {
	        if (key_stolb[j][i] == 1) {
	           if (mass[i] != rez_stolb[j][i])
				    key3 = 1;
				}
			}


	    if (key3==1) {
			continue;
		}

		else {

			for (int i=0; i<6; i++) {   //обновляем матрицу 
				rez[i][j] = mass[i];
			}
             
			tek_min = repeat_fun(rez);
			count_iter++;

			if  (tek_min < min) {
			    min = tek_min;
				for (int i=0; i<6; i++) {
				    for (int j=0; j<6; j++) {
						min_mass[i][j] = rez[i][j];	
					}
				}
			}
		}
 
    } while (next_permutation(mass,mass+6));    
}
 
    cout << "Количество итераций:" << count_iter << endl;
    cout <<"Минимальное число повторений: "<< min << endl;
    cout <<"Результат: "<< endl;

    for (int i = 0; i < 6; i++) {
	    for (int j = 0;j < 6;j++) {  
	        cout <<min_mass[i][j] << " ";
	}
    cout << endl;	
    }

return 0;
}


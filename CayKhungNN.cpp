#include <fstream>
#include <string.h>

using namespace std;

struct Canh {
    int dinhdau, dinhcuoi;
    int dodai;
};

int n, m;
Canh a[100];
int Nutgoc[100];

fstream f;

void Nhap() {
    f.open("D://input.txt", ios::in);
    f >> n >> m;
    int i;
    for (i=1; i <= m; i++) f >> a[i].dinhdau >> a[i].dinhcuoi >> a[i].dodai;
    f.close();
}

void SapXep() {
    Canh tam;
    int i, j;
    for (i=1; i<m-1; i++)
        for (j=i+1; j <= m; j++)
            if (a[i].dodai > a[j].dodai) {
                    tam = a[i];
                    a[i] = a[j];
                    a[j] = tam;
            }
}

int Tim(int x) {
	int gtri = x;
    while (Nutgoc[gtri] > 0 )
	gtri = Nutgoc[gtri];
	return (gtri);
}

void hop(int r1, int r2) { 
    int x = Nutgoc[r1] + Nutgoc[r2];

 if (Nutgoc[r1] > Nutgoc[r2]) {

  Nutgoc[r1] = r2;

  Nutgoc[r2] = x;

 }

 else {

  Nutgoc[r2] = r1;

  Nutgoc[r1] = x;

 }
}

void Kruskal() {
    SapXep();
    int i;
    for (i=1; i <= n; i++) Nutgoc[i] = -1;
    int dem = 0;
    int tong = 0;
    int x, y, z;
    int r1, r2;
    f.open("D://output.txt", ios::out);
    for (i=1; i <= m; i++) {
        if (dem == n-1) break;
        x = a[i].dinhdau;
        y = a[i].dinhcuoi;
		z = a[i].dodai;
		
        r1 = Tim(x);
        r2 = Tim(y);
		
        if (r1 != r2) {
        
            f << x << "   " << y << "   " << z << endl; 
            dem++;
            tong = tong + a[i].dodai;
            hop(r1, r2);
        }
    }
    f << "Tong trong so cua cay khung be nhat la: " << tong;
    f.close();

}

int main() {
    Nhap();
    Kruskal();
}


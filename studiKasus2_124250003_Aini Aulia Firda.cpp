#include <iostream>
using namespace std;

void bubbleSort(string nama[], int n){
	for(int i = 0; i < n -1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(nama[j] > nama[j + 1]){
				swap(nama[j], nama[j + 1]);
			}
		}
	}
}

void quickSort(string nama[], int awal, int akhir){
	int low = awal;
	int high = akhir;
	string pivot = nama[(awal + akhir) / 2];
	
	do{
		while(nama[low] > pivot)
		low++;
		
		while(nama[high] < pivot)
		high--;
		
		if(low <= high){
			swap(nama[low], nama[high]);
			low++;
			high--;
		}
	}while(low <= high);
		
		if(awal < high)
			quickSort(nama,awal,high);
		if(low < akhir)
			quickSort(nama, low, akhir);
}
int main(){
	int n;
	cout << "Jumlah Mahasiswa yang ingin diInput: ";
	cin >> n;
	cin.ignore();
	
	string nama[25];
		cout << "Masukkan Nama Mahasiswa:" << endl;
	for(int i = 0; i<n; i++){
		cout << i + 1 << ". ";
		getline(cin, nama[i]);
		}
	cout << endl;
	
	//menyalin isi array nama, agar data asli tidak hilang
	string nama2[25];
	for(int i = 0; i<n; i++){
		nama2[i] = nama[i];
		}
	cout << endl;
	
	bubbleSort(nama, n);
	cout << "Bubble Sort (ASC): " << endl;
	for(int i = 0; i < n; i++){
		cout << i + 1 << ". " << nama[i] << endl;
		}
	cout << endl;
	
	quickSort(nama2, 0, n - 1);
	cout << "Quick Sort (DESC): " << endl;
	for(int i = 0; i  < n; i++){
		cout << i + 1 << ". " <<nama2[i] <<endl;
		}
	return 0;
}


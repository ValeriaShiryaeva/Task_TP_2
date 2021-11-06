//#include <iostream>
//using namespace std;
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	int a, bits[32];
//	cout << "Введите целое число: ";
//	cin >> a;
//	for (int i = 0; i < 32; i++)
//	{
//		if (a & (1 << i))
//			bits[i] = 1;
//		else
//			bits[i] = 0;
//	}
//	cout << "Биты числа " << a << endl;
//	for (int i = 32 - 1; i >= 0; i--) {
//		cout << bits[i] << ' ';
//	}
//	cout << endl; 
//	int flag = 0, lenght = 0, max_lenght = 0;
//	for (int i = 0; i < 32; i++) {
//		if (bits[i] == 0)
//		{
//			bits[i] = 1;
//			for (int j = 0; j < 32; j++) {
//				if (bits[j] == 0)
//				{
//					if (max_lenght < lenght)
//						max_lenght = lenght;
//					flag = 0;
//					lenght = 0;
//				}
//				if (bits[j] == 1)
//				{
//					lenght++;
//					flag = 1;
//				}
//			}
//			if (max_lenght < lenght)
//				max_lenght = lenght;
//			bits[i] = 0;
//		}
//	}
//	cout << "Наибольная последовательность единиц, при изменении одного бита равна " << max_lenght << endl;
//}
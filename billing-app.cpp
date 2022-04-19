#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>
using namespace std;

int menu(float toplam) {
	int seçim, adet, taksit;
	char EH;
	cout << "----------------------------------------" << endl;
	int A = 500, B = 250, C = 1900, D = 90;
	cout << "| 1-A marka 100'lü tuğla      :" << A << "  TL |" << endl;
	cout << "| 2-B marka el arabası        :" << B << "  TL |" << endl;
	cout << "| 3-C marka taşıma paleti     :" << C << " TL |" << endl;
	cout << "| 4-D marka dış cephe plakası :" << D << "   TL | " << endl;
	cout << "----------------------------------------" << endl;
	cout << "Seçiminiz: ";
	cin >> seçim;
	cout << "Adet sayısı giriniz: ";
	cin >> adet;

	switch (seçim) {
	case 1: {
		cout << "Şuanlık toplam borcunuz: " << A * adet << endl;
		toplam += A * adet;
		cout << "----------------------------------------" << endl;
		break;
	}
	case 2: {
		cout << "Şuanlık toplam borcunuz: " << B * adet << endl;
		toplam += B * adet;
		cout << "----------------------------------------" << endl;
		break;
	}
	case 3: {
		cout << "Şuanlık toplam borcunuz: " << C * adet << endl;
		toplam += C * adet;
		cout << "----------------------------------------" << endl;
		break;
	}
	case 4: {
		cout << "Şuanlık toplam borcunuz: " << D * adet << endl;
		toplam += D * adet;
		cout << "----------------------------------------" << endl;
		break;
	}
	}
	return toplam;
}


int main() {
	setlocale(LC_ALL, "Turkish");
	char x;
	int a = 0;
	char EH, takmi;
	string name;
	float toplam;
	int seçim, adet, taksit;
	string aylar[12] = { "ocak", "şubat", "mart", "nisan", "mayıs", "haziran", "temmuz", "ağustos", "eylül", "ekim", "kasım", "aralık" };
	cout << "Selçuk Taştekin    B201200042\n" << endl;
	cout << "Taştekin İnşaat Malzemeleri ----> HOŞGELDİNİZ.. " << endl;
	cout << "----------------------------------------" << endl;
	cout << "Lütfen Adınızı Giriniz: ";
	getline(cin, name);
	cout << "Sayın " << name << " aşağıdaki menüden alışveriş yapabilirsiniz" << endl;

	while (1) {
		a = menu(a);
		cout << "Alışverişe devam etmek istiyor musunuz? (E/H) :";
		cin >> x;
		if (x == 'E' || x == 'e') {
			continue;
		}
		else if (x == 'H' || x == 'h') {
			cout << "Toplam borcunuz: " << a << " TL" << endl;
			cout << "----------------------------------------" << endl;
			cout << "kdv'li fiyatı görmek ister misiniz?(E/H): ";
			cin >> EH;
			if (EH == 'E' || EH == 'e') {
				float kdvli = a + (a * (0.18));
				cout << "ürünün kdv dahil toplam fiyatı: " << kdvli << " TL" << endl;
			}
			else {
				cout << endl;
			}
			cout << "----------------------------------------" << endl;
			cout << "taksitli ödeme yapmak ister misiniz?(E/H): ";
			cin >> takmi;
			if (takmi == 'E' || takmi == 'e') {
				float kdvli = a + (a * (0.18));
				cout << "kaç taksitte ödeme yapacaksınız(max =12): ";
				cin >> taksit;
				cout << "aylık ödeme tutarınız: " << kdvli / taksit << " TL" << endl;
				for (int i = 0; i < taksit; i++) {
					cout << aylar[i] << ": " << kdvli / taksit << " TL" << endl;
				}
				break;
			}
			else if (takmi == 'H' || takmi == 'h') {
				break;
			}
		}
	}
	ofstream dosya;
	dosya.open("Fatura.txt");
	dosya << "Müşteri Adı" << endl;
	dosya << name << endl;
	dosya << "\nToplam borcunuz: " << (a + (a * (0.18))) << " TL" << endl;
	dosya << "----------------------------------------" << endl;
	if (takmi == 'E' || takmi == 'e') {
		dosya << "Ödeme Çizelgesi:" << endl;
		dosya << "----------------------------------------" << endl;
		for (int i = 0; i < taksit; i++) {
			dosya << aylar[i] << ": " << (a + (a * (0.18))) / taksit << " TL" << endl;
		}
	}
	else {
		dosya << "İşleminiz başarıyla gerçekleştirilmiştir" << endl;
	}
	dosya.close();
	return 0;
}
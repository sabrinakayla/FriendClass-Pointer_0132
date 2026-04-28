#include <iostream>
using namespace std;

class BelahKetupat;

class LayangLayang {
private:
    float d1, d2, sisiA, sisiB;

public:
    void input() {
        cout << "--- Input Layang-Layang ---" << endl;
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi Pendek: "; cin >> sisiA;
        cout << "Sisi Panjang: "; cin >> sisiB;
    }

    float hitungLuas() {
        return 0.5 * d1 * d2;
    }

    void output() {
        cout << "Luas Layang-Layang: " << hitungLuas() << endl;
    }

    friend float hitungKelilingLayang(LayangLayang &l, BelahKetupat &b);
};

class BelahKetupat {
private:
    float d1, d2, sisi;

public:
    void input() {
        cout << "\n--- Input Belah Ketupat ---" << endl;
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi: "; cin >> sisi;
    }

    float hitungLuas() {
        return 0.5 * d1 * d2;
    }

    float hitungKeliling() {
        return 4 * sisi;
    }

    void output() {
        cout << "Luas Belah Ketupat: " << hitungLuas() << endl;
        cout << "Keliling Belah Ketupat: " << hitungKeliling() << endl;
    }

    friend float hitungKelilingLayang(LayangLayang &l, BelahKetupat &b);
};

float hitungKelilingLayang(LayangLayang &l, BelahKetupat &b) {
    return 2 * (l.sisiA + l.sisiB);
}

int main() {
    LayangLayang *layang = new LayangLayang();
    BelahKetupat *ketupat = new BelahKetupat();

    layang->input();
    ketupat->input();

    cout << "\n--- HASIL PERHITUNGAN ---" << endl;
    layang->output();
    ketupat->output();

    cout << "Keliling Layang-Layang (via Friend Method): " << hitungKelilingLayang(*layang, *ketupat) << endl;

    delete layang;
    delete ketupat;

    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

void SaveInt(int value, ofstream& file) {
    file.write(reinterpret_cast<const char*>(&value), sizeof(int));
}

void SaveFloat(float value, ofstream& file) {
    file.write(reinterpret_cast<const char*>(&value), sizeof(float));
}

void MultiplyAndSaveInt(ofstream& file) {
    for (int i = 1; i <= 5; i++) {
        int result = 1000 * i * 5;
        SaveInt(result, file);
    }
}

void SquareAndSaveFloat(ofstream& file) {
    float num = -0.5;
    for (int i = 0; i < 3; i++) {
        float result = num * num;
        SaveFloat(result, file);
        num += 0.5;
    }
}

void All(ofstream& file) {
    // 1. int 1234 저장
    int num1 = 1234;
    SaveInt(num1, file);

    // 2. int 1000부터 5000까지 숫자에 5를 곱하여 저장
    MultiplyAndSaveInt(file);

    // 3. float -0.5에서 0.5씩 증가하면서 자승을 하고 저장
    SquareAndSaveFloat(file);
}

int main() {
    ofstream file("mybin.dat", ios::binary | ios::out);
    if (!file) {
        cout << "파일을 열 수 없습니다.";
        return 1;
    }

    All(file);

    file.close();
    return 0;
}

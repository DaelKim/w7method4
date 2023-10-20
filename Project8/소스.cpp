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
    // 1. int 1234 ����
    int num1 = 1234;
    SaveInt(num1, file);

    // 2. int 1000���� 5000���� ���ڿ� 5�� ���Ͽ� ����
    MultiplyAndSaveInt(file);

    // 3. float -0.5���� 0.5�� �����ϸ鼭 �ڽ��� �ϰ� ����
    SquareAndSaveFloat(file);
}

int main() {
    ofstream file("mybin.dat", ios::binary | ios::out);
    if (!file) {
        cout << "������ �� �� �����ϴ�.";
        return 1;
    }

    All(file);

    file.close();
    return 0;
}

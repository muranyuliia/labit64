#include <iostream>
using namespace std;
// ������� ��� ���������� ������� �������� ������, ������ �� C.
int countElementsLessThanC(double arr[], int n, double C) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < C) {
            count++;
        }
    }
    return count;
}

// ������� ��� ���������� ���� ����� ������ �������� ���� ���������� ��'������ ��������.
int sumIntPartsAfterLastNegative(double arr[], int n) {
    int sum = 0;
    bool foundNegative = false;

    for (int i = n - 1; i >= 0; i--) {
        if (foundNegative) {
            sum += static_cast<int>(arr[i]);
        }

        if (arr[i] < 0) {
            foundNegative = true;
        }
    }

    return sum;
}

// ������� ��� ����������� ������� ������������� �������� ������.
int findIndexOfMax(double arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// ������� ��� ����������� ������� ���������� �������� ������.
int findIndexOfMin(double arr[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// ������� ��� ����� �������� ������, ��������� ������� ������������.
void swapElementsWithinRange(double arr[], int n, double maxElement) {
    double range = maxElement * 0.2; // 20% �� ������������� ��������

    for (int i = 0; i < n; i++) {
        if (arr[i] >= maxElement - range && arr[i] <= maxElement + range) {
            arr[i] = -arr[i];
        }
    }
}

int main() {
    int n;
    double C;

    cout << "������ ����� ������: ";
    cin >> n;

    if (n <= 0) {
        std::cerr << "�������� ����� ������." << std::endl;
        return 1;
    }

    double* arr = new double[n];

    cout << "������ " << n << " ������ �����: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "������ �������� C: ";
    cin >> C;

    int count = countElementsLessThanC(arr, n, C);
    cout << "ʳ������ �������� ������ �� C: " << count << endl;

    int sum = sumIntPartsAfterLastNegative(arr, n);
    cout << "���� ����� ������ �������� ���� ���������� ��'������: " << sum << endl;

    int maxIndex = findIndexOfMax(arr, n);
    int minIndex = findIndexOfMin(arr, n);

    if (maxIndex != minIndex) {
        if (maxIndex > minIndex) {
            std::swap(maxIndex, minIndex);
        }
        swapElementsWithinRange(arr, n, arr[maxIndex]);
    }

    cout << "������������� �����: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}

#include <iostream>
using namespace std;
// Функція для обчислення кількості елементів масиву, менших за C.
int countElementsLessThanC(double arr[], int n, double C) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < C) {
            count++;
        }
    }
    return count;
}

// Функція для обчислення суми цілих частин елементів після останнього від'ємного елементу.
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

// Функція для знаходження індексу максимального елемента масиву.
int findIndexOfMax(double arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Функція для знаходження індексу мінімального елемента масиву.
int findIndexOfMin(double arr[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Функція для обміну елементів масиву, зберігаючи відносне розташування.
void swapElementsWithinRange(double arr[], int n, double maxElement) {
    double range = maxElement * 0.2; // 20% від максимального елемента

    for (int i = 0; i < n; i++) {
        if (arr[i] >= maxElement - range && arr[i] <= maxElement + range) {
            arr[i] = -arr[i];
        }
    }
}

int main() {
    int n;
    double C;

    cout << "Введіть розмір масиву: ";
    cin >> n;

    if (n <= 0) {
        std::cerr << "Недійсний розмір масиву." << std::endl;
        return 1;
    }

    double* arr = new double[n];

    cout << "Введіть " << n << " дійсних чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Введіть значення C: ";
    cin >> C;

    int count = countElementsLessThanC(arr, n, C);
    cout << "Кількість елементів менших за C: " << count << endl;

    int sum = sumIntPartsAfterLastNegative(arr, n);
    cout << "Сума цілих частин елементів після останнього від'ємного: " << sum << endl;

    int maxIndex = findIndexOfMax(arr, n);
    int minIndex = findIndexOfMin(arr, n);

    if (maxIndex != minIndex) {
        if (maxIndex > minIndex) {
            std::swap(maxIndex, minIndex);
        }
        swapElementsWithinRange(arr, n, arr[maxIndex]);
    }

    cout << "Модифікований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}

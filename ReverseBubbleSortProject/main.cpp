#include <iostream>
#include <iomanip>

using namespace std;

// Function to initialize an array with random values
void initMasRandom(int mas[], int size, int min = 0, int max = 10) {
   // Fill the array with random values between min and max
   for (int i = 0; i < size; ++i) {
      mas[i] = rand() % (max - min) - min;
   }
}

// Function to print the elements of an array
void printMas(int mas[], int size) {
   for (int i = 0; i < size; ++i) {
      cout << "mas [ " << i << " ] = " << mas[i] << "\n";
   }
}

// Function to sort an array using bubble sort algorithm
void bubbleSort(int mas[], int size) {
   // Continue sorting until no more swaps are needed
   while (--size > 0) {
      bool flag = true;
      for (int i = 0; i < size; ++i) {
         if (mas[i] > mas[i + 1]) {
            // Swap elements if they are out of order
            swap(mas[i], mas[i + 1]);
            flag = false;
         }
      }
      // If no swaps were made, the array is sorted
      if (flag) break;
   }
}

// Function to sort an array using insertion sort algorithm
void insertionSort(int mas[], int size) {
   int i, key, j;
   for (i = 1; i < size; ++i) {
      key = mas[i];
      j = i - 1;

      // Move elements of mas[0..i-1] that are greater than key
      // to one position ahead of their current position
      while (j >= 0 && mas[j] > key) {
         mas[j + 1] = mas[j];
         j = j - 1;
      }
      mas[j + 1] = key;
   }
}

int main() {
   const int size = 10; // Size of the array
   int mas[size]; // Array declaration

   // Initialize array with random values
   initMasRandom(mas, size);

   // Perform bubble sort and print the sorted array
   cout << "Bubble Sort: \n";
   bubbleSort(mas, size);
   printMas(mas, size);

   // Perform insertion sort and print the sorted array
   cout << "Insertion Sort: \n";
   insertionSort(mas, size);
   printMas(mas, size);

   return 0;
}

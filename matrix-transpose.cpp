/*
Chris McKnight
Bijaya Karki
CS 3102 Sec 1

Sparse Matrix Transpose Program

Displays the O(n) of different size sparse matrix transposes
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main (int argc, char * const argv[])
{
  char op;
  int temp,
      row,
      rows,
      cols,
      count;
  cout << "Would you like to run the system? <Y for yes, N for no>: ";
  cin >> op;
  int index2;
  while (op != 'n' && op != 'N')
  {
    char file[1000];
    cout << "Enter the matrix file name: ";
    cin >> file;
    fstream input(file);
    if (!input)
    {
      cout << "Error opening file M5x5.mat" << endl;
      exit(1);
    }
    input >> rows;
    input >> cols;
    int m[rows][cols],
      t[cols][rows];

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        m[r][c] = 0;
        t[r][c] = 0;
      }
    }

    count = 0;
    row = 0;
    input >> temp;
    m[row][count] = temp;
    while (!input.eof())
    {
      count++;
      if (count - 1 % cols == 0 && count - 1 != 0)
        row++;
      input >> temp;
      m[row][count] = temp;

    }
    input.close();
    int index,
      index3;
    for (index3 = 0; index3 < rows; index3++)
    {
      for (index = 0; index < cols; index++)
      {
        cout  << m[index3][index] << " ";
      }
      cout << endl;
    }

    cout << endl;

    for (index = 0; index < rows; index++)
    {
      for (index2 = 0; index2 < cols; index2++)
      {
        int tempi = m[index][index2];
        t[index2][index] = tempi;
      }
    }
    for (index3 = 0; index3 < cols; index3++)
    {
      for (index = 0; index < rows; index++)
      {
        cout << t[index3][index] << " ";
      }
      cout << endl;
    }
    cout << "Would you like to run the system again? <Y for yes, N for no>: ";
    cin >> op;
  }
  return 0;
}

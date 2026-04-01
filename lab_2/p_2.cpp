step 1: allocate array of pointers( one per row)
int** arr = new int*[rows];
// step 2: allocate each ROW separately with its own column count
 for(int i = 0; i< rows; i++){
  int cols;
  cout << "Colums for row " << i << ":";
  cin >> cols;
  arr[i] = new int[cols];
 }
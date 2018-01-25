

// Example of undefined behavior.
int x; // x has indeterminate value
if (x < 0) // Either branch could execute
  cout << 1 << '\n';
else
  cout << 2 << '\n';




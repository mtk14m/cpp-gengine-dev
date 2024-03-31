 #include <iostream>

//pointer print func7

 void pp(int & a) //pass by reference
 {
     std::cout << &a << " " << a << " "<< sizeof(a)<< "\n";
 }

 class IntArray
 {
    size_t m_size;
    int * m_arr;
 public:
     //constructor
     IntArray(size_t size)
     :  m_size(size)
     , m_arr (new int[size])
     {
         std::cout << "Arrray Constructor\n";
     }
     //destructor
     ~IntArray()
     {
         delete [] m_arr;
         std::cout << "Array destructor\n";
     }
     int get(size_t index) const
     {
         return m_arr[index];
     }
     void set(size_t index, int val)
     {
         m_arr[index] = val;
     }
     void print() const
     {
         for (size_t i=0; i<m_size; i++)
         {
             std::cout << i << " " << m_arr[i] << "\n";
         }
     }
 };

int main()
{
  /*int arr[10] = {};
  int * harr = new int[10]; // allocated memory leaked
  for(size_t i=0; i<10; i++)
  {
      pp(arr[i]);
  }
  for(size_t i=0; i<10; i++)
  {
    pp(harr[i]);
  }*/

  /*
  int    a = 10;
  int    b = 25;
  //int * pa = &a;
  int * pb = &b;

  *(pb+1) = 17;//this why raw pointers are dangerous

  pp(a);
  pp(b);
  */

  //IntArray
  IntArray myArray(10);
  //set
  myArray.set(4, 7);
  myArray.set(2, 152);

  myArray.print();
  return 0;
}

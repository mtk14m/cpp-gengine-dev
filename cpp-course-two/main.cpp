 #include <iostream>

//pointer print func7

 void pp(int & a) //pass by reference
 {
     std::cout << &a << " " << a << " "<< sizeof(a)<< "\n";
 }
 template <typename T>
 class DynamicArray
 {
    size_t m_size;
    T * m_arr;
 public:
     //constructor
     DynamicArray(size_t size)
     :  m_size(size)
     , m_arr (new T[size])
     {
         std::cout << "Arrray Constructor\n";
     }
     //destructor
     ~DynamicArray()
     {
         delete [] m_arr;
         std::cout << "Array destructor\n";
     }
     T get(size_t index) const
     {
         return m_arr[index];
     }
     void set(size_t index, T val)
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

     //operator overwriting
     T & operator [](size_t index)
     {
         return m_arr[index];
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
  DynamicArray<float> myArray(10);
  //set
  myArray.set(4, 7.8);
  myArray.set(2, 152.365);

  //overwritting operator
  myArray[3] = 3.14159;
  myArray[5] = 2.784;

  myArray.print();
  return 0;
}

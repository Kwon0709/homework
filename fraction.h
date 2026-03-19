typedef unsigned int my_fraction;


extern my_fraction create(int numerator, int denominator); //numerator 분자 , denominator 분모
extern my_fraction add(my_fraction i, my_fraction j);
extern my_fraction minus(my_fraction i, my_fraction j);
extern my_fraction mult(my_fraction i, my_fraction j);
extern my_fraction divid(my_fraction i, my_fraction j);
extern my_fraction reduce(my_fraction f);
extern int find_gcd(int a, int b);
extern void print(my_fraction f);

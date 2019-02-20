#include <iostream>
#include <iomanip>
int sample()
{
    setlocale(LC_ALL, "Russian");
    char _char[] = "char\n"; 
    int _int = 20;
    int negative_int = -10;
    double _double = 123.5467;
    float zero_float = 10;
 
//======== работаем с выравниванием ========\\
    
    std::cout<<"Работаем с выравниванием\n";
    //устанавливаем ширину поля вывода
    std::cout.width (20);
    //устанавливаем символ заполнитель(по умолчанию - пробел)
    std::cout.fill ('_');
    //флаг форматирования при котором знак числа выводится по левому краю, 
    //число — по правому. Промежуток заполняется символами заполнителя
    std::cout.setf(std::ios::internal);
    std::cout<<negative_int<<std::endl;
 
    //устанавливаем ширину поля вывода
    std::cout.width(50);
    //устанавливаем символ заполнитель(по умолчанию - пробел)
    std::cout.fill ('/');
    //выравниваем по правому краю поля
    std::cout.setf(std::ios::right);
    std::cout<<_char<<std::endl;
 
    //P.S. флаги  left, right и internal не могут быть установлены одновременно.
 
//======== выводим в разных системах исчисления ========\\
 
    std::cout<<"Выводим в разных системах исчисления\n";
    //восьмеричная система счисления
    std::cout.flags(std::ios::oct);
    std::cout<<_int<<std::endl;
 
    //десятичная система счисления
    std::cout.flags(std::ios::dec);
    std::cout<<_int<<std::endl;
 
    //шестнадцатеричная система счисления
    std::cout.flags(std::ios::hex);
    std::cout<<_int<<std::endl;
 
    //задаем основание системы счисления (8, 16, 10 или 0)
    //по умолчанию 0 - это десятичное, кроме случаев, когда вводятся 8- или
    //16-ричные числа. Здесь к примеру основание 8
    std::cout<<std::setbase(8)<<_int<<std::endl;
 
    //P.S. флаги dec, oct и hex не могут быть установлены одновременно.
 
//======== выводим вещественные чисел ========\\
 
    std::cout<<"\nВыводим вещественные числа\n";
    //при выводе вещественных чисел печатаем десятичную точку и дробную часть
    std::cout.flags(std::ios::showpoint);
    std::cout<<zero_float<<std::endl;
 
    //печатаем вещественные числа в форме мантиссы с порядком
    std::cout.flags(std::ios::scientific);
    std::cout<<_double<<std::endl;
    
    //Печатаем вещественные числа в форме с фиксированной точкой, 
    //точность определяем строкой ниже в setprecision
    std::cout.flags(std::ios::fixed);
    std::cout<<std::setprecision(2)<<_double<<std::endl;
 
    //P.S. флаги scientific и fixed не могут быть установлены одновременно
 
//======== печатаем знаки ========\\
 
    std::cout<<"\nПечатаем знаки\n";
    //печатаем знак при выводе положительных чисел
    std::cout.flags(std::ios::showpos);
    std::cout<<_int<<std::endl;
 
    system("pause");
    return 0;
}
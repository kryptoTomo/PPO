#include"funkcje.h"

const int wczytajLiczbeWyrazow()
{
    int number;
    do{
        std::cout << "Podaj n: ";
        std::cin >> number;
    }while(number<1);
    return number;
}
void wypiszBinarnie(int number)
{
	int i=31;
	bool ok=false;
	while(i--)
	{
		if(number>>i&1&!ok) 
			ok=true;
        if(ok)
			std::cout<<((number>>i)&1);
	}
}
const int* inicjalizujCiagFibonacciego(const int number)
{
    if(number < 0)
        return nullptr;
    int * series = new int[number + 1];
    series[0]= 0;
    if(number > 0)
    {
        series[1] = 1;
        for(int i = 2 ; i <= number; i++ )
            series[i] = series[i-1] + series[i-2];
    }
    return series;
}
void wypisz(const int * series,const int number)
{
    if(series)
    {
        std::cout<<"(";
        for(int i = 0; i < number;i++)
            std::cout<<series[i]<<", ";
        std::cout<<series[number]<<")"<<std::endl;
    }
    else 
        std::cout << "Ciag nie istnieje"<<std::endl;
}
int sum(const int * series,const int number)
{
    int s = 0;
    for(int i = 1; i <= number;i++)
        s += series[i];
    return s;
}
void suma(const int * series,const int number)
{
    std::cout<<"suma: "<<sum(series,number)<<std::endl;
}
void iloczyn(const int * series,const int number)
{
    int multip = 1;
    for(int i = 1;i <= number;i++)
        multip *= series[i];
    std::cout<<"iloczyn: "<<multip<<std::endl;
}
void suma(const int * series_1,const int number_1,const int * series_2,const int number_2)
{
    std::cout<<"suma dwoch ciagow: "<<sum(series_1,number_1)+sum(series_2,number_2)<<std::endl;
}
void max(const int * series_1,const int number_1,const int * series_2,const int number_2)
{
    if(number_1>number_2){
        std::cout<<"maksimum: "<<series_1[number_1]<<" (ciag 0)"<<std::endl;
        return;
    }
    if(number_1<number_2) 
        std::cout<<"maksimum: "<<series_2[number_2]<<" (ciag 1)"<<std::endl;
    else 
        std::cout<<"maksimum: "<<series_1[number_1]<<" (ciagi sa równe)"<<std::endl; 
}
void UsunCiag(const int *series)
{
    delete []series;
}
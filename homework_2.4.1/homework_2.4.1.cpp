#include <iostream>
#include <string>
#include <fstream>


class Address
{

private:

    std::string city;
    std::string street;
    std::string result;

    int number_house;
    int number_apartment;

    std::string making_address(std::string city, std::string street, int number_house, int number_apartment)
    {

        std::string completion_address = city + ", " + street + ", " + std::to_string(number_house) + ", " + std::to_string(number_apartment) + "\n";

        return completion_address;
    }

public:

    Address()
    {
        city = "none";
        street = "none";
        number_house = 0;
        number_apartment = 0;
    }

    Address(std::string city, std::string street, int number_house, int number_apartment)
    {

        this->city = city;
        this->street = street;
        this->number_house = number_house;
        this->number_apartment = number_apartment;

    }

    std::string get_address()
    {
        result = making_address(this->city, this->street, this->number_house, this->number_apartment);
        return result;
    };

};



int main()
{
    setlocale(LC_ALL, "Russian");

    int _number_house = 0;
    int _number_apartment = 0;
    int _count_address = 0;



    std::string _city;
    std::string _street;



    std::fstream fin("in.txt");
    std::ofstream fout("out.txt");


    if (fin.is_open())
    {

        fin >> _count_address;
        fout << _count_address << std::endl;
        Address* location_array = new Address[_count_address];

        for (int i = 0; i < _count_address; ++i)
        {

            fin >> _city;
            fin >> _street;
            fin >> _number_house;
            fin >> _number_apartment;

            location_array[i] = Address(_city, _street, _number_house, _number_apartment);

        }

        for (int i = _count_address - 1; i >= 0; --i)
        {

            fout << location_array[i].get_address();
        }

        fin.close();
    }
    else
    {
        std::cout << "Не удалось открыть файл!";
    }



    return 0;
}
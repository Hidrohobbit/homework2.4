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

void sort (Address* addresses, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
        {
            if (addresses[i].get_address() > addresses[j].get_address())
            {
                std::swap(addresses[i], addresses[j]);
            }
        }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int number_house = 0;
    int number_apartment = 0;
    int count_address = 0;

    std::string city;
    std::string street;

    std::fstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (fin.is_open())
    {

        fin >> count_address;
        fout << count_address << std::endl;
        Address* location_array = new Address[count_address];

        for (int i = 0; i < count_address; ++i)
        {
            fin >> city;
            fin >> street;
            fin >> number_house;
            fin >> number_apartment;
            location_array[i] = Address(city, street, number_house, number_apartment);
        }

        for (int i = 0; i < count_address; ++i)
        {
            location_array[i].get_address();
        }

        sort(location_array, count_address);

        for (int i = 0; i < count_address; ++i)
        {
            fout << location_array[i].get_address();
        }
        fin.close();
        delete[] location_array;
    }
    else
    {
        std::cout << "Не удалось открыть файл!";
    }

    return 0;
}
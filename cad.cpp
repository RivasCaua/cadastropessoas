#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring> 
#include <limits>

class Membros {
//class to store each person information
private:
    std::string name;
    int age;
    std::string phone;
    std::string email;
    std::string adress;
    std::string sex;

public:
    //set and get name 
    std::string getName(){
        return name;
    }
    void setName(const std::string& name) {
        this->name = name;
    }
    
    //set and get age
    int getAge(){
        return age;
    }
    void setAge(int age){
        if (age >= 0)
            this->age = age;
        else
            std::cout << "Erro: idade invalida" << std::endl;
    }

    //Set and get phone  
    std::string getPhone(){
        return phone;
    }
    void setPhone(const std::string& phone){
        this->phone = phone;
    }

    //Set and get adress
    std::string getAdress(){
        return adress;
    }
    void setAdress(const std::string& adress){
        this->adress = adress;
    }

    //set and get email
    std::string getEmail(){
        return email;
    }
    void setEmail(const std::string& email){
        this->email = email;
    }

    //set and get sex
    std::string getSex(){
        return sex;
    }
    void setSex(const std::string& sex){
        this->sex = sex;
    }   
};

//clear the buffer before to use std::getline
void clearinputbuffer(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//capture the string
void getstring(const std::string& prompt, std::string& output){
    std::cout << prompt;
    std::getline(std::cin, output);
}

//capture the int
void getint(const std::string& prompt, int& output){
    std::cout << prompt;
    while (!(std::cin >> output)) { //validates if a number was entered
        std::cout << "Erro!!! Entrada invalida. Digite um numero. \n";
        std::cin.clear();
        clearinputbuffer();
    }
}

//save the informations in a csv archive
void savetocsv(Membros& member, const std::string& filename){

    //verify if the file exists
    bool fileexists = std::ifstream(filename).good();

    //open the archive in write mode
    std::fstream file(filename, std::ios::out | std::ios::app);

    //verify if the file was opened succefully
    if (!file) { 
        std::cerr << "Erro ao rodar o arquivo " << filename << std::endl;
        return; 
    }

    //Create a newline if the file dont exist
    if (!fileexists){
        file << "Nome, Idade, Telefone, Endereco, Sexo\n";
    }

    //write the member dates in csv file 
    file << member.getName() << ","
         << member.getAge() << ","
         << member.getPhone() << ","
         << member.getAdress() << ","
         << member.getSex() << "\n";

    std::cout << "Dados gravados no arquivo CSV com sucesso!" << std::endl;

}

int main() {
    Membros member;
    std::string name, phone, adress, email, sex;
    int age;

    //Get the name 
    getstring("Nome: ", name);
    member.setName(name);
    std::cout << "" << member.getName() << std::endl;

    clearinputbuffer();

    //Get the age
    getint("Idade: ", age);
    member.setAge(age);
    std::cout << "" << member.getAge() << std::endl;

    clearinputbuffer();

    //Get the phone number
    getstring("Telefone: ", phone);
    member.setPhone(phone);
    std::cout << "" << member.getPhone() << std::endl;

    clearinputbuffer();

    //get the email
    getstring("Email: ", email);
    member.setEmail(email);
    std::cout << "" << member.getEmail() << std::endl;

    clearinputbuffer();

    //Get the gender 
    getstring("Sexo: ", sex);
    member.setSex(sex);
    std::cout << "" << member.getSex() << std::endl;

    //save the informations in csv file
    savetocsv(member, "membros.csv");

    return 0;
}   
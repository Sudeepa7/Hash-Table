//************************GROUP  14************************************


#include <iostream>
#include <string>

//xxxx= 3688
using namespace std;
int zz = 68;
int q = 8;
int yy = 88;


float c = 0.7376; //c=3688/5000

struct religion   //structure to key value pair
{
    string religion_name; 
    string origin_year;
    string origin_country;

};

struct religion* Hashtable[39];  // size of array = (11) + ((yy)%(30))=11+(88%30) = 39;
int Hash_Function(string key, int size)
{
    int sum = 0;
    int index = 0;
    for (int i = 0; i < key.length(); i++)
    {
        sum = sum + key[i];                          //get sum off ASCII value
    }
   index = floor((size)*fmod(((sum) * 1.0 * c), (1)));;


    return index;
}
void Insert(struct religion* data)   // function to insert data
{
    int size = 39;
    string key = data->religion_name;
    int index = Hash_Function(key, size);
    int i = index;
    int h = 1;
    while (Hashtable[i] != NULL)
    {

        i = (i + (h * h)) % size;
        h++;

    }
    Hashtable[i] = data;
}



void Delete_item(string key) {  //function to delete data
    int size = 39;
    int a = 1;
    int index = Hash_Function(key, size);
    int i = index;
    while (true)
    {
        if (Hashtable[i] != NULL && Hashtable[i]->religion_name == key)
        {
            Hashtable[i] = NULL;
            break;
        }
        if (a >= 39) {
            break;
        }

        i = (i + (a * a)) % size;
        a++;



    }
}

struct religion* Search(string key)  //function to search data
{
    int size = 39;
    int a = 1;
    int index = Hash_Function(key, size);
    int i = index;
    while (true)
    {
        if (Hashtable[i] != NULL && Hashtable[i]->religion_name == key)
        {
            cout << "Result of search about " << key << "  =>" << "[Religion:" << Hashtable[i]->religion_name << "      " << "Origin_year :" << Hashtable[i]->origin_year << "   " << "Country :" << Hashtable[i]->origin_country << "  ]" << endl;
            return Hashtable[index];
            break;
        }
        if (a >= 39) {
            cout << "There is no element by  " << key << "  key  value" << endl;
            break;
        }

        i = (i + (a * a)) % size;
        a++;

    }
    return NULL;
}


void display() {   //function to display data
    cout << endl << endl << endl;
    for (int i = 0; i < 39; i++) {
        cout << "[";
        if (Hashtable[i] == NULL) {
            cout << "EMPTY";
        }
        else {

            cout << "Religion:" << Hashtable[i]->religion_name << "      " << "Origin_year :" << Hashtable[i]->origin_year << "   " << "Country :" << Hashtable[i]->origin_country << "  ";
        }
        cout << "]" << endl;
    }
    cout << endl << endl;
}

int main()
{
    for (int i = 0; i < 39; i++) {     // initilaizing hash array
        Hashtable[i] = NULL;
    }
    religion R1 = { "Buddhism","563 BC","Indian" };             //input data to the structure
    religion R2 = { "Christianity","33 AD","Galilean-Judean" };  
    religion R3 = { "Islam","c.570","Arab" };    
    religion R4 = { "Charvaka","6th century","Indian" };    
    religion R5 = { "Atenism","1353 BC ","Egyptian" };   
    religion R6 = { "Valmikism","3rd century BC","Indian" };   
    religion R7 = { "Nusayrism","late 9th century","Persia" };  
    religion R8 = { "Zen","5th century","Indian" };      
    religion R9 = { "Mennonite","1561","Dutch" };    
    religion R10 = { "Neo-Confucianism","9th century","Chinese" };    
    religion R11 = { "Hinduism","c. 2000 BCE","Indian" };             
    religion R12 = { "Judaism","c. 2000 BCE","Northern India" };             
    religion R13 = { "Confucianism","c. 500 BCE","Northern China" };            
    religion R14 = { "Daoism","c. 550 BCE","Northern China" };             
    religion R15 = { "Baha'i","1863","Iran" };             
    religion R16 = { "Zoroastrianism","900s BCE","Persia" };            
    religion R17 = { "Shinto","800s CE","Japan" };            
    religion R18 = { "Sikhism","1500s CE","Punjab" };             
    religion R19 = { "denomination","1600s BCE","China " };             
    religion R20 = { "Conversos","late 15th Century","Spain  " };            
    religion R21 = { "Catharists","1184","southern France " };            
    religion R22 = { "Torquemada","1478","China " };            
    religion R23 = { "Inquisition","1542 ","Rome  " };             
    religion R24 = { "Taoism","1600s BCE","China " };            
    religion R25 = { "Tenriism","19th century","Japan " };            
    religion R26 = { "Druze"," 9th century","Egypt " };            
    religion R27 = { "Cheondoism","19th century","Korea " };            
    religion R28 = { "Hoahaoism","1600s BCE","20th century " };             



    Insert(&R1);    //call insert funtion by reference
    Insert(&R2);   
    Insert(&R3);   
    Insert(&R4);   
    Insert(&R5); 
    Insert(&R6);    
    Insert(&R7);    
    Insert(&R8);    
    Insert(&R9);   
    Insert(&R10);   
    Insert(&R11); 
    Insert(&R12);   
    Insert(&R13);   
    Insert(&R14);   
    Insert(&R15);   
    Insert(&R16);  
    Insert(&R17);  
    Insert(&R18);   
    Insert(&R19);   
    Insert(&R20);  
    Insert(&R21);   
    Insert(&R22);   
    Insert(&R23);   
    Insert(&R24);  
    Insert(&R25);   
    Insert(&R26);   
    Insert(&R27);   
    Insert(&R28);   

    cout << "****************After Insert Data (Hash_table)*****************************************" << endl;
    display();  // call display funtion

    Delete_item("Charvaka");   // call delete function
    Delete_item("Nusayrism");
    Delete_item("Taoism");
    Delete_item("Atenism");
    Delete_item("Hoahaoism");
    Delete_item("Shinto");
    Delete_item("Mennonite");
    Delete_item("Hoahaoism");
    Delete_item("Christianity");
    Delete_item("Conversos");
    Delete_item("Inquisition");
    Delete_item("Neo-Confucianism");
    cout << " * ***************After Delete 12 Data(Hash_table) * ****************************************" << endl;
    display();
    cout << "*************************************search data by key****************" << endl << endl;
    Search("Buddhism");    //call search function
    Search("Islam");
    Search("Christianity");
    Search("Zen");
    Search("Tenriism");
    Search("Valmikism");
    Search("Daoism");
    Search("Hinduism");
    Search("Judaism");
    cout << endl << endl;




}


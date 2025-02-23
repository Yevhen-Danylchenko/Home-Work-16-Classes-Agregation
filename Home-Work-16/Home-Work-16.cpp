#include <iostream>
#include <list>

using namespace std;

class Order {
private:
    int number_id;
    double price;
public:
    explicit Order(int number_id, double price) {
        this->number_id = number_id;
        this->price = price;
    }

    void setNumber() {
        this->number_id = number_id;
    }

    void setPrice() {
        this->price = price;
    }

    int getNumber() {
        return number_id;
    }

    double getPrice() {
        return price;
    }

    void show_info() {
        cout << "Number ID is: " << number_id << " Price: " << price << endl;
    }
};

class Customer {
private:
    Order* obj;
    list<Customer> li;
public:
    Customer(Order* obj) {
        this->obj = obj;
    }

    void show_info_order() {
        obj->show_info();
    }

    void add_obj() {        
        int number_id;
        double price;
        string temp;
        while (temp != "stop") {
            cout << "Enter number ID of object: \t";
            cin >> number_id;
            cout << "Enter price of object: \t";
            cin >> price;            
            Order* new_obj = new Order(number_id, price);
            Customer new_add_obj(new_obj);
            li.push_back(new_add_obj);
            cout << "Enter stop for anding enter \t";
            cin >> temp;
        }
    }

    double sum_price() {
        double sum = 0;
        for (auto& Customer : li) {
            sum += Customer.obj->getPrice();
        }
        return sum;
    }

    void show_all_obj() {
        for (auto& Customer : li) {
            Customer.show_info_order();
        }
    }
};

int main()
{
    Order obj(1, 237.7);
    Customer obj_1(&obj);
    obj_1.show_info_order();
    obj_1.add_obj();
    cout << obj_1.sum_price() << endl;
    obj_1.show_all_obj();
    return 0;
}



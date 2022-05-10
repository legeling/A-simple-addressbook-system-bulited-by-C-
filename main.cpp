/***************************************
*@File    ：learn_addressbook.cpp
*@IDE     ：CLion 
*@Author  ：lingxiaotian
*@Date    ：2022/4/4 16:28 
***************************************/

#include <string>
#include <iostream>
#include "function.h"
using namespace std;

//数据封装
//创建联系人结构体
struct Person{
//    int id;
    string Name;
    int gender;
    int age;
    string phone_number;
    string address;
};
//通讯录结构体
#define MAX 2000//通讯录最大人数
struct Address_book{
    struct Person person_array[MAX];
    int book_size;
};


//函数
//欢迎信息
void welcome(){
    cout<<"欢迎使用小添通讯录管理系统beta0.1\n"
          "-------1、创建新的联系人-------\n"
          "-------2、显示所有联系人-------\n"
          "-------3、删除联系人信息-------\n"
          "-------4、查找联系人信息-------\n"
          "-------5、修改联系人信息-------\n"
          "-------6、清除所有联系人-------\n"
          "-------0、退出通讯录系统-------\n"<<endl;
}
//判断输入是否合法
int judge(){
    int trigger;
    for (int i = 0; i < 10; ++i) {
        cin>>trigger;
        if (trigger!=1&&trigger!=2&&trigger!=3&&trigger!=4&&trigger!=5&&trigger!=6&&trigger!=0){
            cout<<"输入数值不合法，请输入0~6的数字"<<endl;
        } else{
            break;
        }
    }
    return trigger;
}
//添加联系人
void add_person(Address_book *book){
    if (book->book_size ==MAX){
        cout<<"通讯录已满，无法添加"<<endl;
        return ;
    }
    else{
        string name;
        cout<<"请输入联系人姓名"<<endl;
        cin>>name;
        book->person_array[book->book_size].Name = name;
        int gender = 0;
        cout<<"请输入联系人性别，1为男，2为女"<<endl;

        while (1){
        cin >> gender;
        if (gender == 1 || gender == 2) {
            book->person_array[book->book_size].gender = gender;
            break;
        } else {
            cout << "输入格式错误，请输入1或2来代表性别" << endl;

        }
        }
        int age;
        cout<<"请输入联系人年龄"<<endl;
        cin>>age;
        book->person_array[book->book_size].age = age;
        string number;
        cout<<"请输入联系人手机号码"<<endl;
        cin>>number;
        book->person_array[book->book_size].phone_number = number;
        string address;
        cout<<"请输入联系人邮箱"<<endl;
        cin>>address;
        book->person_array[book->book_size].address = address;

        book->book_size++;
        cout<<"成功添加用户！"<<endl;
        system("clear");
    };
};
//显示联系人
void show_person(Address_book *book){
    if (book->book_size == 0){
        cout<<"当前通讯录为空！"<<endl;
    }else{
    for (int i = 0; i <book->book_size ; i++) {
        cout
        <<"序号："<<i+1
        <<"\t"<<"姓名："<<book->person_array[i].Name
        <<"\t"<<"年龄："<<book->person_array[i].age
        <<"\t"<<"性别："<<(book->person_array[i].gender ==1?"男":"女")
        <<"\t"<<"手机号码："<<book->person_array[i].phone_number
        <<"\t"<<"家庭住址："<<book->person_array[i].address<<endl;
    }
    }

}
//删除联系人
void delete_person(Address_book *book){
    show_person(book);
    int x = -1;
    int y = -1;
    cout<<"请输入要删除的用户的编号"<<endl;
    cin>>x;
    cout<<"请再次确认要删除的用户编号"<<endl;
    cin>>y;
    if (x == y){
        for (int i = 0; i < book->book_size -x+1; i++) {
            book->person_array[x-1+i] = book->person_array[x+i];
        }
        cout<<"删除成功！"<<endl;
        book ->book_size -=1;
        show_person(book);
    }else{
        cout<<"两次输入的编号不一致！请重新输入"<<endl;
    }

}
//输出单个联系人信息
void print_person(Address_book *book,int i){
    cout
            << "序号：" << i + 1
            << "\t" << "姓名：" << book->person_array[i].Name
            << "\t" << "年龄：" << book->person_array[i].age
            << "\t" << "性别：" << (book->person_array[i].gender == 1 ? "男" : "女")
            << "\t" << "手机号码：" << book->person_array[i].phone_number
            << "\t" << "家庭住址：" << book->person_array[i].address << endl;
}
//查找联系人
int search_person(Address_book *book){
    while (true) {
        string name;
        cout << "请输入要查找的联系人姓名" << endl;
        cin >> name;
        if (name == "0"){
            break;
        }else{
            for (int i = 0; i < book->book_size; i++) {
                if (name == book->person_array[i].Name) {
                    return i;
                    print_person(book,i);
                } else {
                    cout << "查无此人！" << endl;
                    break;
                }
            }
        }
    }
}
//修改联系人
void change_person(Address_book *book){
    show_person(book);
    int i = search_person(book);

    string name;
    cout<<"请输入联系人姓名"<<endl;
    cin>>name;
    book->person_array[i].Name = name;
    int gender = 0;
    cout<<"请输入联系人性别，1为男，2为女"<<endl;

    while (1){
        cin >> gender;
        if (gender == 1 || gender == 2) {
            book->person_array[i].gender = gender;
            break;
        } else {
            cout << "输入格式错误，请输入1或2来代表性别" << endl;

        }
    }
        int age;
        cout<<"请输入联系人年龄"<<endl;
        cin>>age;
        book->person_array[i].age = age;
        string number;
        cout<<"请输入联系人手机号码"<<endl;
        cin>>number;
        book->person_array[i].phone_number = number;
        string address;
        cout<<"请输入联系人邮箱"<<endl;
        cin>>address;
        book->person_array[i].address = address;
        cout<<"修改成功！"<<endl;
}
//清空联系人
void clean_person(Address_book *book){
    string jude = "";
    cout<<"请问您真的要清空联系人吗？输入y清空"<<endl;
    cin>>jude;
    if (jude == "y"){
        book ->book_size = 0;
        cout<<"通讯录已清空！！"<<endl;
    } else{
        return;
    }

}
//菜单
//           "-------1、创建新的联系人-------\n"
//           "-------2、显示所有联系人-------\n"
//           "-------3、删除联系人信息-------\n"
//           "-------4、查找联系人信息-------\n"
//           "-------5、修改联系人信息-------\n"
//           "-------6、清除所有联系人-------\n"
//           "-------0、退出通讯录系统-------\n"
         
int Menu(int x,Address_book *book){
        switch(x){
            //退出程序
            case 0:cout<<"欢迎下次使用"<<endl;return 0;break;
            //添加联系人
            case 1:add_person(book);break;
            case 2:show_person(book);break;
            case 3:delete_person(book);break;
            case 4:search_person(book);break;
            case 5:change_person(book);break;
            case 6:clean_person(book);break;
        }


}

//主函数
int main(){
//    创建通讯录
    Address_book book;
    book.book_size = 0;

    while(1) {
        welcome();
        int trigger = judge();
        Menu(trigger,&book);
        if(trigger == 0){
            return 0;
        }
    }

};

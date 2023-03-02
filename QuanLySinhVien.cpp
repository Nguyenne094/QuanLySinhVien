#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

typedef struct sinhVien
{
    int MaSV;
    string tensv;
    string Lop;
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;

}sv;

int main()
{
    system("color 6");
    //Main information
    sv loptruong;
    cout << "Nhap ma sv: ";
    cin >> loptruong.MaSV;
    getchar();
    cout << "Nhap ten sv: ";
    getline(cin, loptruong.tensv);
    cout << "Nhap so tuoi: ";
    cin >> loptruong.tuoi;
    cout << "Nhap ID Lop: ";
    cin >> loptruong.Lop;

    //Declare pointer variable
    system("cls");
    sv *sv2=&loptruong;
    cout << "<<----------------------------->>" << endl;
    cout << "Xin chao lop truong " << sv2->tensv <<"<3"<< endl;
    cout << "Ma sinh vien cua ban la: " << sv2->MaSV << endl;
    cout << "<<----------------------------->>" << endl;
    
    //Fill student information of class
    int siso;
    sv sinhvienIT11[50];
    cout << "Thong bao si so lop: ";
    cin >> siso;
    for(int j = 0; j < siso; j++)
    {
        system("cls");
        system("color 6");
        cout << "Ten sinh vien "<< j + 1 << ": ";
        fflush(stdin);
        getline(cin, sinhvienIT11[j].tensv);
        sinhvienIT11[j].tuoi = 18;
        cout << "Nhap ma sinh vien: ";
        cin >> sinhvienIT11[j].MaSV;
    }

    //Print student information
    cout << "Thong tin sinh vien lop " << loptruong.Lop << " la:";
    for(int j = 0; j < siso; j++)
    {
        cout << "Ten sinh vien thu " << j + 1 << " la:" << sinhvienIT11[j].tensv << endl;
        cout << "Ma sinh vien: " << sinhvienIT11[j].MaSV << endl;
        cout << "-------------------------------------" << endl;
        
    }

    system("cls");
 
    //Enter the gpa
    for(int j = 0; j < siso; j++)
    {
        system("cls");
        cout << "Nhap diem cua sinh vien thu " << j + 1 << ": " << endl;
        cout << "Nhap diem toan:";
        cin >> sinhvienIT11[j].diemToan;
        cout << "Nhap diem ly:";
        cin >> sinhvienIT11[j].diemLy;
        cout << "Nhap diem hoa:";
        cin >> sinhvienIT11[j].diemHoa;
    }
    
    //Print the highest and the lowest gpa 
    int i;
    double gpa[i];
    for(int i=0; i < siso; i++)
    {
        gpa[i] = (sinhvienIT11[i].diemToan + sinhvienIT11[i].diemLy + sinhvienIT11[i].diemHoa) / 3 ;
        cout << "GPA cua sinh vien thu " << i+1 << " co ten " << sinhvienIT11[i].tensv << " la:" << gpa[i] << endl;
        cout << "<---------------------------------->" << endl;
    }
    
    //Print rank GPA
    system("cls");
    for(int j=0; j < siso-1; j++)
    {
        for(int i = 0; i < siso-1; i++)
        {
            if(gpa[i] > gpa[i+1])
            {
                int temp = gpa[i];
                gpa[i] = gpa[i+1];
                gpa[i+1] = gpa[i];
            }
        }
    }

    cout << "***RANK***" << endl;
    for(int j = siso-1; j >=0; j--)
    {
        cout << sinhvienIT11[j].tensv << " | " << gpa[j] << endl;
    }

    cout << "System Updated!" << endl;
    system("pause");
    return 0;
}
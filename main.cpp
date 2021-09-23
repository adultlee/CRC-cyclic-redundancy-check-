#include <iostream>
#include <vector>

using namespace std;
int inputArr[14]; // 14의 크기를 가진 배열로 초기 입력되는 수이다. 
int testArr[17]; //17의 크기(14+3)를 가진 crc 결과가 더해져 만들어질 배열이다.
int tempArr[17]; // 중간 계산과정에 있어서 crc도출해 내기 위한 배열이다.
int crc[3]; // 3의 크기를 가진 crc 결과이다. 초기에는 0으로 초기화 되어있다. 
int test_crc[3]; // test 하여 들어가게 될  crc  값이다. 
int divisor[4];

void div()
{
    cout << "------------------------------------------------------" << endl;
    cout << "제수를 통해서 임시 배열이 나눠지는 과정입니다. 이진수의 나눗셈은 Xor 논리로 이루어집니다." << endl;

    for (int i = 0; i < 14; i++)
    {
        if (tempArr[i] == 1)
        {
            //가장 첫위치
            if (tempArr[i] == divisor[0])
            {
                tempArr[i] = 0;
            }
            else
            {
                tempArr[i] = 1;
            }
            //두번째 위치
            if (tempArr[i + 1] == divisor[1])
            {
                tempArr[i + 1] = 0;
            }
            else
            {
                tempArr[i + 1] = 1;
            }

            //3번째 위치
            if (tempArr[i + 2] == divisor[2])
            {
                tempArr[i + 2] = 0;
            }
            else
            {
                tempArr[i + 2] = 1;
            }
            //4번째 위치
            if (tempArr[i + 3] == divisor[3])
            {
                tempArr[i + 3] = 0;
            }
            else
            {
                tempArr[i + 3] = 1;
            }

            for (int j = 0; j < 17; j++)
            {

                cout << tempArr[j] << " ";
            }
            cout << endl;
        }
    }
    test_crc[0] = tempArr[14];
    test_crc[1] = tempArr[15];
    test_crc[2] = tempArr[16];
}
int main()
{
    cout << "샘플 데이터를 입력하시오"<<endl;
    for(int i=0; i<14;i++ )
    {
        cin >> inputArr[i];
    }
   
    cout << "제수를 입력하시오" <<endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> divisor[i];
    }
   
    cout << endl;
    cout << "------------------------------------------------------"<<endl;
    cout << "나눠질 배열입니다. 14번째 이후에는  0 으로 초기화 해줍니다. "<<endl;
    for (int i = 0; i < 17; i++)
    {
        if(i<14)
        {
            tempArr[i] = inputArr[i];
        }
        else
        {
            tempArr[i] = 0;
        }
        cout << " "<<tempArr[i];
    }

    cout << endl;
  
    div();

    cout << endl<< "------------------------------------------------------" << endl;
    cout << "최종으로 나눠진 배열입니다. 마지막 세 숫자는 CRC배열에 들어가게 됩니다." << endl;
    cout <<endl<< "나누는 과정 후 arr" <<endl;
    for (int i = 0; i < 17; i++)
    {
        cout << tempArr[i] <<" ";
    }

    crc[0] = tempArr[14];
    crc[1] = tempArr[15];
    crc[2] = tempArr[16];

    cout << endl;

    cout << "------------------------------------------------------" << endl<<endl;
    cout << "당신의 제수(divisor)는 " ;
    for(int i = 0; i<4; i++)
    {
        cout << " " << divisor[i];
    }
    cout << "\n당신의 CRC bit 는  ";
    for(int i = 0; i<3; i++)
    {
        cout << " " << crc[i];
    }
    cout << endl;

    cout << endl<< "------------------------------------------------------" << endl;
    cout << "당신이 테스트할 배열을 입력하세요"<<endl;
    for (int i = 0; i < 14; i++)
    {
        cin >> inputArr[i];
    }
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "나눠질 배열입니다. 14번째 이후에는  0 으로 초기화 해줍니다. " << endl;
    for (int i = 0; i < 17; i++)
    {
        if (i < 14)
        {
            tempArr[i] = inputArr[i];
        }
        else
        {
            tempArr[i] = 0;
        }
        cout << tempArr[i] << " ";
    }
    cout << endl<<endl;
    div();
    cout << "\n당신의 CRC bit 는  ";
    for (int i = 0; i < 3; i++)
    {
        cout << " " << test_crc[i];
    }
    cout <<" 입니다"<< endl;
    if (crc[0] == test_crc[0] && crc[1] == test_crc[1] && crc[2] == test_crc[2])
    {
        cout <<"crc 값이 같으므로 데이터 손실은 없습니다." <<endl;
    }
    else{
        cout << "crc 값이 다르므로 데이터 손실이 있습니다." << endl;
    }
}
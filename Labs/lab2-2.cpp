#include <iostream>

using namespace std;

class Complex{
public:
    Complex(){}
    Complex(float real, float image){ //constructor
        this->real=real;          //thisָ���Á���ȡclass�еĳɆT(private��׃��)
        this->image=image; //���_ʹ��this�Ͳ��ؓ��ĳɆT����(Complex)�ą������Q��class��׃���ɆT��ͬ
    }
    const Complex operator+(const Complex& k){ //k����main�e��+̖��ą���(��myComplex2)
        float r_output=this->real+k.getReal();
        float i_output=this->image+k.getImage();
        return Complex(r_output,i_output);
    }
    const Complex operator-(const Complex& k){
        float r_output=this->real-k.getReal();
        float i_output=this->image-k.getImage();
        return Complex(r_output,i_output);
    }
    float getReal() const{
        return real;
    }
    float getImage() const{
        return image;
    }
private:
    float real,image;
};

ostream& operator<<(ostream& out,const Complex& k){ //out��ostream�͑B�ą�����k���@��ݔ����ʽ��Ҫ�ą���
    float real, image;
    real = k.getReal();
    image = k.getImage();
    if(image >= 0)out<<real<<" + "<<image<<"i"; //out�ἴ��ݔ������ʽ����ԭ����cout��ʽoverload���@��ݔ����ʽ
      else out<<real<<" - "<<-image<<"i";
    return out;
}

int main(){
    float real1, image1;
    float real2, image2;
    while(cin >> real1 >> image1 >> real2 >> image2){
        Complex myComplex1(real1, image1);
        Complex myComplex2(real2, image2);
        cout<< myComplex1 + myComplex2 << endl;
        cout<< myComplex1 - myComplex2 << endl;
    }
    return 0;
}

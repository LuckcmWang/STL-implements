#include<stringbymyself.h>

//��ͨ���캯�������ж��ǲ��ǿ��ַ���
//����char�����ַ���
String::String(const char *str) {
    if (str==NULL) {
        m_data = new char[1] ;
        *m_data = ��\0��;
        //�Կ��ַ����Զ������Ž�����־����0���ļӷֵ㣺��m_data��NULL�ж�
    }
    else{
        int length= strlen(str) ;//strlen������ĩβ��\0
        m_data = new char[length+1] ;
        strcpy(m_data,str) ;
    }
}

//������������Ҫ������ɾ����Ա���������ж��ַ�ָ���Ƿ�Ϊ�գ���Ϊ�ս���ɾ����
String::~String() {
    if(m_data) {
        delete [] m_data ;
        m_data=O ; //�� delete m_data ;
    }
}

//�������캯����
String::String(const String &other){ //���������const ���ı䡣
    if(!other.m_data){ //ͬ���ȶ�m_data��NULL�жϣ�
        m_data=0;
    }
    m_data = new char[strlen(other.m_data)+1];
    strcpy(m_data,other.m_data);
}

//��ֵ�����
String & String ::operator=(const String &other){
    if(this != &other){       //����Ƿ��Ը�ֵ
        delete[] m_data;      //�ͷ�ԭ�����ڴ���Դ
        if(!other.m_data){    //�ж��Ƿ�ΪNULL
            m_data = 0;
        }
        else{
            m_data = new char[strlen(other.m_data)+1];
            strcpy(m_data,other.m_data);
        }
    }
    return *this;   //���ض��������
}

//�ַ�������
//��������������ַ���Ϊ�գ�����Ϊ�գ����߶���Ϊ��
String& String::operator+(const String &other){
    String newString;
    if(!other.m_data){
        newString = *this;
    }
    else if(!m_data){
        newString = other;
    }
    else{
        newString.m_data=new char[strlen(m_data)+strlen(other.m_data)+1];
        strcpy(newString.m_data,m_data);
        strcat(newString.m_data,other.m_data);
    }
    return newString;
}

//�ж�������
bool String::operator==(const String &other){
    if(strlen(m_data)!=strlen(other.m_data))
        return false;
    else{
        return strcmp(this.m_data,other.m_data)?true:false;
    }
}

//���س���
int String::getLength(){
    return strlen(m_data);//����strlen(this.m_data); thisĬ���С�
}


























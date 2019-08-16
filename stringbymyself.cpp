#include<stringbymyself.h>

//普通构造函数，先判断是不是空字符串
//传入char类型字符串
String::String(const char *str) {
    if (str==NULL) {
        m_data = new char[1] ;
        *m_data = ’\0’;
        //对空字符串自动申请存放结束标志’＼0’的加分点：对m_data加NULL判断
    }
    else{
        int length= strlen(str) ;//strlen不计算末尾的\0
        m_data = new char[length+1] ;
        strcpy(m_data,str) ;
    }
}

//析构函数，主要功能是删除成员变量，先判断字符指针是否为空，不为空将其删除。
String::~String() {
    if(m_data) {
        delete [] m_data ;
        m_data=O ; //或 delete m_data ;
    }
}

//拷贝构造函数，
String::String(const String &other){ //输入参数加const 不改变。
    if(!other.m_data){ //同样先对m_data加NULL判断，
        m_data=0;
    }
    m_data = new char[strlen(other.m_data)+1];
    strcpy(m_data,other.m_data);
}

//赋值运算符
String & String ::operator=(const String &other){
    if(this != &other){       //检查是否自赋值
        delete[] m_data;      //释放原来的内存资源
        if(!other.m_data){    //判断是否为NULL
            m_data = 0;
        }
        else{
            m_data = new char[strlen(other.m_data)+1];
            strcpy(m_data,other.m_data);
        }
    }
    return *this;   //返回对象的引用
}

//字符串连接
//三种情况，传入字符串为空，本身为空，两者都不为空
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

//判断相等与否
bool String::operator==(const String &other){
    if(strlen(m_data)!=strlen(other.m_data))
        return false;
    else{
        return strcmp(this.m_data,other.m_data)?true:false;
    }
}

//返回长度
int String::getLength(){
    return strlen(m_data);//或者strlen(this.m_data); this默认有。
}


























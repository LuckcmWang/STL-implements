class String{
public :
String(const char *str =NULL) ;//��ͨ���캯��
String(const String &other) ;  //�������캯��
~ String () ;                  //��������
String & operator =(canst String &other) ; //��ֵ����
String & operator +(canst String &other);  //�ַ�������
bool operator ==(canst String &other) ;    //�ж����
int getLength();  //���س���
private:
char *m_data ;    //˽�б��������ַ���
}

